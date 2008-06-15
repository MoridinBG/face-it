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
#include "mainscreen.h"

MainScreen::MainScreen(QWidget *parent) :QDialog(parent)
{
	vector<unsigned int> hiddenLayers;
	hiddenLayers.push_back(50);
	hiddenLayers.push_back(25);

	network = new Network(20 * 22,1,hiddenLayers);
	setupUi(this);
	image = new QImage();
}

void MainScreen::on_pushLoad_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                 "",
                                                 tr("Images (*.png *.xpm *.jpg)"));
	image = new QImage(fileName);
	if(!image->isNull())
	{
		imageToSearch->setPixmap(fileName);
	}
	else
		QMessageBox::critical(this,"Error opening image","Could not open the image!");
	
}

void MainScreen::on_pushEditNet_clicked()
{
	NetworkEditor* editor = new NetworkEditor(network, this);
	connect(editor,SIGNAL(newNetwork(Network*)),this,SLOT(updateNetwork(Network*)));
	editor->exec();
}

void MainScreen::on_pushSearch_clicked()
{
	std::vector<std::vector<double> > inputs;
	std::vector<QImage> slices;
	ImageFeeder imageFeeder(IMAGE_WINDOW_WIDTH,
				IMAGE_WINDOW_HEIGHT);
	try
	{
		imageFeeder.loadImage(image);
		imageFeeder.createInputsFromImage(inputs,slices);
	}
	catch(Exception& ex)
	{
		qDebug() << "Exception while searching image: " << ex.what();
	}

	for(unsigned int j = 0; j < 5; ++j)
	{
		for (unsigned int i = 0; i < inputs.size(); ++i)
			if(network->calculateOutput(inputs[i])[0] > 0.6)
			{
				listMatches->addItem("Facial figure found!");
				slices[i].save("/home/fester/slice/" + QString::number(i) + ".png");
			}
		imageFeeder.scaleDown();
		imageFeeder.createInputsFromImage(inputs, slices);
	}
}

void MainScreen::updateNetwork(Network * _network)
{
	delete network;
	network = _network;
}
