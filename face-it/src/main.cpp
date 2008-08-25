/***************************************************************************
 *   Copyright (C) 2008 by Ivan Dilchovski   *
 *   root.darkstar@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include <QApplication>
#include <iostream>
#include <vector>
#include <QImage>
#include <QColor>
#include <QDir>
#include <QString>
#include <QDebug>

#include "NullParamEx.h"
#include "BadPathEx.h"
#include "exception.h"

#include "mainscreen.h"


#include "network.h"
#include "backpropagation.h"
#include "TrainingImagesContainer.h"
#include "ImageFeeder.h"
#include "qxmlpersistance.h"

using namespace std;

int main(int argc, char *argv[])
{
    	QApplication app(argc, argv);

	srand((unsigned)time(0));
    	MainScreen *dialog = new MainScreen();

    	dialog->show();
    	return app.exec();
}
