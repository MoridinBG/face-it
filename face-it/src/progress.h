//
// C++ Interface: $MODULE$
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef PROGRESS_H
#define PROGRESS_H

#include "ui_progress.h"
#include <QDialog>

class Progress : public QDialog, public Ui::Progress{
Q_OBJECT
public:
	Progress(QWidget *parent = 0);
public slots:
	void setProgress(double value);	
};

#endif
