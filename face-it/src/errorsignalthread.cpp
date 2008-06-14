//
// C++ Implementation: errorsignalthread
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "errorsignalthread.h"

ErrorSignalThread::ErrorSignalThread(	Layer* current,
					Layer* upper,
					unsigned int start,
					unsigned int end,
					QObject *parent) : QThread(parent)
{
	toStop = false;
	toRestart = false;

	currentLayer = current;
	upperLayer = upper;
	startPosition = start;
	endPosition = end;
}


ErrorSignalThread::~ErrorSignalThread()
{
}

void ErrorSignalThread::run()
{
	//qDebug() << "Thread with" << currentLayer->numNeurons() << "neurons, beginning at " << startPosition << " ending at " << endPosition;
	lock.lockForRead();
	std::vector<Neuron*> neuronsAtCurrentLayer = currentLayer->getNeurons();
	std::vector<Neuron*> neuronsAtUpperLayer = upperLayer->getNeurons();
	lock.unlock();
	std::vector<double> currentErrorSignals;
	for (unsigned int j = startPosition; j < endPosition; ++j)
	{
		lock.lockForRead();
		if(toRestart)
			break;
		if(toStop)
			return;
		double sum = 0;
		double currentErrorSignal;
		double currentOutput = neuronsAtCurrentLayer[j]->getOutput();
		double upperErrorSignal;
		double weight;
		//Calculate the contribution to the error of every neuron at the upper layer
		for (unsigned int k = 0; k < neuronsAtUpperLayer.size() ; ++k)
		{
			upperErrorSignal = upperLayer->getErrorSignal()[k];
			weight = neuronsAtUpperLayer[k]->getWeights()[j];
			sum += upperErrorSignal * weight;
		}
		currentErrorSignal = currentOutput * (1.0 - currentOutput) * sum;
		currentErrorSignals.push_back(currentErrorSignal);
		lock.unlock();
	}
	if(!toRestart)
	{
		lock.lockForWrite();
		std::vector<double> errorSignals = currentLayer->getErrorSignal();
		
		for (unsigned int i = startPosition; i < endPosition; ++i)
			errorSignals[i] = currentErrorSignals[i - startPosition];

		currentLayer->setErrorSignal(errorSignals);
		lock.unlock();
	}
	emit ready();
}
