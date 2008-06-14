//
// C++ Interface: errorsignalcalculator
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef ERRORSIGNALCALCULATOR_H
#define ERRORSIGNALCALCULATOR_H

#include <QObject>
#include <QDebug>
#include <list>
#include <QMutex>
#include <QMutexLocker>

#include "cpucount.h"
#include "network.h"
#include "errorsignalthread.h"
#include "threaddispatcher.h"

/**
Management class spawning threads to calculate  the error signals of single neurons.

	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class ErrorSignalCalculator : public ThreadDispatcher
{
public:
	ErrorSignalCalculator(QObject *parent = 0);
	void calculateErrorSignals(Network* network);
private:
// Methods
	void clearThreads();
	void createThreads();
	void threadManager();

// Variables
	long cpuCount;
	
	vector<Layer*> networkLayers;
	Layer *currentLayer;
	Layer *upperLayer;

	typedef list<ErrorSignalThread*> ErrorThreads;
	ErrorThreads errorThreads;

	vector<double> errorSignalStorage;
	
	QMutex lock;

	bool isRunning;
	
	int currentThread;
	int runningThreads;
public slots:
	void threadFinished();
};

#endif
