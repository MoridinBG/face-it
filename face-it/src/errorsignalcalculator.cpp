//
// C++ Implementation: errorsignalcalculator
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "errorsignalcalculator.h"
using namespace std;

ErrorSignalCalculator::ErrorSignalCalculator(QObject *parent)
 : ThreadDispatcher(parent)
{
	isRunning = false;
	runningThreads = 0;
}

void ErrorSignalCalculator::calculateErrorSignals(Network * network)
{
	if(isRunning)
		clearThreads();
	
	std::vector<Layer*> ::iterator itLayer;
	vector<Layer*> hiddenLayers;
	
	//Load the input layer
	networkLayers.push_back(network->getInputLayer());
	//Load the hidden layers
	hiddenLayers = network->getHiddenLayers();
	for(itLayer = hiddenLayers.begin(); itLayer < hiddenLayers.end(); itLayer++)
		networkLayers.push_back(*itLayer);
	//Load the output layer
	networkLayers.push_back(network->getOutputLayer());

	//Calculate the error form the last hidden layer to the input layer
	isRunning = true;
	currentThread = networkLayers.size() - 2;
	createThreads();
	threadManager();
	
}

void ErrorSignalCalculator::clearThreads()
{
	for (ErrorThreads::iterator iter = errorThreads.begin();
         	iter != errorThreads.end(); ++iter)
    	{
        	(*iter)->terminate();
		delete *iter;
	}
	errorThreads.clear();
}



/*!
    \fn ErrorSignalCalculator::threadManager()
 */
void ErrorSignalCalculator::threadManager()
{
	lock.lock();
	if (runningThreads >= cpuCount)
		return;
		
	if (errorThreads.size() > 0)
	{
		while ((runningThreads < cpuCount) && (errorThreads.size() > 0))
		{
			ErrorSignalThread *worker = errorThreads.front();
			errorThreads.pop_front();
			worker->start();
			runningThreads++;
		}
	}
	lock.unlock();
	
}


/*!
    \fn ErrorSignalCalculator::createThreads(int threadLevel)
 */
void ErrorSignalCalculator::createThreads()
{
	//CpuCount counter;
	//cpuCount = counter.count();
	cpuCount = 4;
	currentLayer = networkLayers[currentThread];
	errorSignalStorage.clear();
	errorSignalStorage.reserve(currentLayer->numNeurons());
	upperLayer = networkLayers[currentThread + 1];
		
	errorSignalStorage.clear();
	errorSignalStorage.reserve(currentLayer->numNeurons());
		
	int begin = 0;
	int offset = 0;
	int reminder = 0;
		
	if((cpuCount == 1) && ((currentLayer->numNeurons() / cpuCount) == 0))
	{
		ErrorSignalThread *worker = new ErrorSignalThread(currentLayer,
								upperLayer,
    								0,
    								currentLayer->numNeurons());
		connect(worker,SIGNAL(ready()),this, SLOT(threadFinished()),Qt::DirectConnection);
		errorThreads.push_back(worker);
		return;
	}

	offset = currentLayer->numNeurons() / cpuCount;
	if(offset < 10)
	{
		cpuCount /= 2;
		offset = currentLayer->numNeurons() / cpuCount;
	}
	reminder = currentLayer->numNeurons() % cpuCount;

	for(long i = 0; i < cpuCount; ++i)
	{
		ErrorSignalThread *worker = new ErrorSignalThread(currentLayer,
								upperLayer,
    								begin,
    								begin + offset);
		connect(worker,SIGNAL(ready()),this, SLOT(threadFinished()),Qt::DirectConnection);
		errorThreads.push_back(worker);
		begin += offset;
	}

	if(reminder != 0)
	{
		ErrorSignalThread *worker = new ErrorSignalThread(currentLayer,
								upperLayer,
								begin,
								begin + reminder);
		connect(worker,SIGNAL(ready()),this, SLOT(threadFinished()),Qt::DirectConnection);
		errorThreads.push_back(worker);
	}
}

void ErrorSignalCalculator::threadFinished()
{
	lock.lock();
	runningThreads--;
	if((runningThreads == 0) && (currentThread > 1) && (errorThreads.size() == 0))
	{
		currentThread--;
		createThreads();
	}
	else if ((runningThreads == 0) && (currentThread = 1))
	{
		isRunning = false;
		lock.unlock();
		emit signalsCalculated();
		return;
	}
	lock.unlock();
	if (runningThreads <= cpuCount)
		threadManager();
}
