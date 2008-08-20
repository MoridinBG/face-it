//
// C++ Implementation: $MODULE$
//
// Description: 
//
//
// Author: Ivan Dilchovski <root.darkstar@gmail.com>, (C) 2008
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "progress.h"

Progress::Progress(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
}

void Progress::setProgress(double value)
{
	progressBar->setValue(value);
}
