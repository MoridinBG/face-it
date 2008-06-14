//
// C++ Interface: weightchanger
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef WEIGHTCHANGER_H
#define WEIGHTCHANGER_H

#include "threaddispatcher.h"
#include "weightchangingthread.h"
#include "network.h"
#include <QObject>

/**
Manages threads changing the weights of neurons.

	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class WeightChanger : public ThreadDispatcher
{
public:
	WeightChanger();
	void changeWeights(Network* network,
			double _momentum,
      			double _learningRate);
private:
// Methods
	void clearThreads();
	void createThreads();
	void threadManager();

// Variables
	long cpuCount;
	bool isRunning;
	QMutex lock;
	
	vector<Layer*> networkLayers;
	Layer *currentLayer;
	Layer *lowerLayer;
	
	typedef list<WeightChangingThread*> WeightThreads;
	WeightThreads weightThreads;
	
	int currentThread;
	int runningThreads;
	
	double momentum;
	double learningRate;
public slots:
	void threadFinished();
};

#endif
