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
#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include <QFileDialog>
#include <QDebug>
#include <QImage>
#include <QMessageBox>

#include "ui_gui.h"
#include "network.h"
#include "qxmlpersistance.h"
#include "networkeditor.h"
#include "ImageFeeder.h"
#include <vector>

class MainScreen: public QDialog, public Ui::Dialog {
Q_OBJECT
public:
    MainScreen(QWidget *parent = 0);
private slots:
	void on_pushLoad_clicked();
	void on_pushEditNet_clicked();
	void on_pushSearch_clicked();

	void updateNetwork(Network* _network);
private:
	QImage *image;
	Network *network;

	static const int IMAGE_WINDOW_HEIGHT = 20;
	static const int IMAGE_WINDOW_WIDTH = 22;
};

#endif
