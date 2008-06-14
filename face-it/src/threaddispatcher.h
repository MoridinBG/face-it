//
// C++ Interface: threaddispatcher
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef THREADDISPATCHER_H
#define THREADDISPATCHER_H
#include <QObject>
#include <QMutex>

/**
Abstract class used to create thread managers for various tasks.

	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class ThreadDispatcher : public QObject
{
Q_OBJECT
public:
    ThreadDispatcher(QObject *parent = 0);
    ~ThreadDispatcher();
private:
// Methods
	virtual void clearThreads() = 0;
	virtual void createThreads() = 0;
	virtual void threadManager() = 0;
public slots:
	virtual void threadFinished() = 0;
signals:
		void signalsCalculated();
		void weightsChanged();
};

#endif
