//
// C++ Interface: weightchangingthread
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef WEIGHTCHANGINGTHREAD_H
#define WEIGHTCHANGINGTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QReadWriteLock>

#include "layer.h"

/**
Thread used to change the weights of part of the neurons of a layer.

	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class WeightChangingThread : public QThread
{
Q_OBJECT
public:
	WeightChangingThread(Layer *current,
			     Layer *lower,
			unsigned int start,
			unsigned int end,
   			double _momentum,
   			double _learningRate,
   			QObject *parent = 0);
private:
	Layer* currentLayer;
	Layer* lowerLayer;
	unsigned int startPosition;
	unsigned int endPosition;
	double momentum;
	double learningRate;
	
	QReadWriteLock lock;
protected:
	void run();
signals:
	void ready();

};

#endif
