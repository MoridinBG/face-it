//
// C++ Implementation: weightchangingthread
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "weightchangingthread.h"

WeightChangingThread::WeightChangingThread(Layer *current,
					Layer *lower,
					unsigned int start,
 					unsigned int end,
					double _momentum,
					double _learningRate,
 					QObject *parent) : QThread(parent)
{
	currentLayer = current;
	lowerLayer = lower;
	startPosition = start;
	endPosition = end;
	
	momentum = _momentum;
	learningRate = _learningRate;
}

void WeightChangingThread::run()
{
//	qDebug() << "Thread with" << currentLayer->numNeurons() << "neurons, beginning at " << startPosition << " ending at " << endPosition;

	std::vector<Neuron*> neuronsAtCurrentLayer = currentLayer->getNeurons();
	std::vector<Neuron*> neuronsAtLowerLayer = lowerLayer->getNeurons();
	std::vector<double> levelErrorSignals = currentLayer->getErrorSignal();
	std::vector<double> weights;
	std::vector<double> newWeights;
	std::vector<double> weightChanges;
	std::vector<double> newWeightChanges;
	
	double input;
	double previousDelta;
	double errorSignal;
	double weightDelta;
	double newWeight;
	
	//Iterrate all error signals (In fact all neurons at this layer)
	for (unsigned int j = startPosition; j < endPosition; ++j)
	{
		lock.lockForRead();
		weights = neuronsAtCurrentLayer[j]->getWeights();
		weightChanges = neuronsAtCurrentLayer[j]->getWeightChanges();
		lock.unlock();
		//Adjust all the weights of connection to the previous layer, according to the error
		for (unsigned int k = 0; k < neuronsAtLowerLayer.size(); ++k)
		{
			input = neuronsAtLowerLayer[k]->getOutput();
			previousDelta = weightChanges[k];
			errorSignal = levelErrorSignals[j];
			//Adjustment is made by taking into account the input  and the previous weight change
			weightDelta = ((learningRate * errorSignal * input) + (momentum * previousDelta));
			newWeight = weights[k] + weightDelta;
			newWeights.push_back(newWeight);
			newWeightChanges.push_back(weightDelta);
			
		}
		for (unsigned int i = startPosition; i < endPosition; ++i)
		{
			weightChanges[i] = newWeightChanges[i - startPosition];
			weights[i] = newWeights[i - startPosition];
		}
		lock.lockForWrite();
		neuronsAtCurrentLayer[j]->setWeightChanges(weightChanges);
		neuronsAtCurrentLayer[j]->setWeights(weights);
		lock.unlock();
		newWeightChanges.clear();
		newWeights.clear();
	}
	emit ready();
}




