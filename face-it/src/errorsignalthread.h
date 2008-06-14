//
// C++ Interface: errorsignalthread
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef ERRORSIGNALTHREAD_H
#define ERRORSIGNALTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QReadWriteLock>

#include "layer.h"
/**
Thread used to extract error signals for part of a layer.

	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class ErrorSignalThread : public QThread
{
Q_OBJECT
public:
    	ErrorSignalThread(	Layer* current,
				Layer* upper,
				unsigned int start,
				unsigned int end,
				QObject *parent = 0);
    	~ErrorSignalThread();

	void halt();
private:

	Layer* currentLayer;
	Layer* upperLayer;
	unsigned int startPosition;
	unsigned int endPosition;

	bool toStop;
	bool toRestart;
	
	QReadWriteLock lock;
protected:
	void run();
signals:
	void ready();
};

#endif
