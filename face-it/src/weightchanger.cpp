//
// C++ Implementation: weightchanger
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "weightchanger.h"

WeightChanger::WeightChanger()
 : ThreadDispatcher()
{
	isRunning = false;
	runningThreads = 0;
}

void WeightChanger::changeWeights(Network* network,
				 double _momentum,
				 double _learningRate)
{
	if(isRunning)
		clearThreads();
	learningRate = _learningRate;
	momentum = _momentum;
	
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
	
	isRunning = true;
	currentThread = networkLayers.size() - 1;
	createThreads();
	threadManager();
}

void WeightChanger::clearThreads()
{
	for (WeightThreads::iterator iter = weightThreads.begin();
		    iter != weightThreads.end(); ++iter)
	{
		(*iter)->terminate();
		delete *iter;
	}
	weightThreads.clear();
}

void WeightChanger::threadManager()
{
	lock.lock();
	if (runningThreads >= cpuCount)
		return;
		
	if (weightThreads.size() > 0)
	{
		while ((runningThreads < cpuCount) && (weightThreads.size() > 0))
		{
			WeightChangingThread *worker = weightThreads.front();
			weightThreads.pop_front();
			worker->start();
			runningThreads++;
		}
	}
	lock.unlock();
}

void WeightChanger::createThreads()
{
	//CpuCount counter;
	//cpuCount = counter.count();
	cpuCount = 4;
	currentLayer = networkLayers[currentThread];
	lowerLayer = networkLayers[currentThread - 1];
		
	int begin = 0;
	int offset = 0;
	int reminder = 0;
		
	if((cpuCount == 1) && ((currentLayer->numNeurons() / cpuCount) == 0))
	{
		WeightChangingThread *worker = new WeightChangingThread(currentLayer,
									lowerLayer,
	 								0,
	  								currentLayer->numNeurons(),
									momentum,
	 								learningRate);
		connect(worker,SIGNAL(ready()),this, SLOT(threadFinished()),Qt::DirectConnection);
		weightThreads.push_back(worker);
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
		WeightChangingThread *worker = new WeightChangingThread(currentLayer,
									lowerLayer,
									begin,
									begin + offset,
									momentum,
									learningRate);
		connect(worker,SIGNAL(ready()),this, SLOT(threadFinished()),Qt::DirectConnection);
		weightThreads.push_back(worker);
		begin += offset;
	}

	if(reminder != 0)
	{
		WeightChangingThread *worker = new WeightChangingThread(currentLayer,
									lowerLayer,
									0,
									currentLayer->numNeurons(),
									momentum,
									learningRate);
		connect(worker,SIGNAL(ready()),this, SLOT(threadFinished()),Qt::DirectConnection);
		weightThreads.push_back(worker);
	}
}

void WeightChanger::threadFinished()
{
	lock.lock();
	runningThreads--;
	if((runningThreads == 0) && (currentThread > 1) && (weightThreads.size() == 0))
	{
		currentThread--;
		createThreads();
	}
	else if ((runningThreads == 0) && (currentThread = 1))
	{
		isRunning = false;
		lock.unlock();
		emit weightsChanged();
		return;
	}
	lock.unlock();
	if (runningThreads <= cpuCount)
		threadManager();
}


