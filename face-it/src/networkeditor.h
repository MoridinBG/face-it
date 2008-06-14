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
#ifndef NETWORKEDITOR_H
#define NETWORKEDITOR_H

#include "ui_networkeditor.h"
#include "network.h"
#include "TrainingImagesWorker.h"
#include "backpropagation.h"
#include "qxmlpersistance.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QList>
#include <QImage>
#include <QListWidgetItem>
#include <QBrush>
#include <QColor>
#include <QDebug>

#include <list>
#include <vector>

class NetworkEditor: public QDialog, public Ui::NetworkEditor {
Q_OBJECT
public:
    NetworkEditor(Network *net,QWidget *parent = 0);
private slots:
	void on_spinHiddenLayers_valueChanged(int i);
	void on_spinInputNeurons_valueChanged(int i);
	void on_spinOutputNeurons_valueChanged(int i);

	void on_spinWidth_valueChanged(int i);
	void on_spinHeight_valueChanged(int i);

	void on_listFaces_itemSelectionChanged();
	void on_listNonFaces_itemSelectionChanged();
		
	void on_pushCommit_clicked();
	void on_pushDone_clicked();

	void on_pushAddFaces_clicked();
	void on_pushRemoveFaces_clicked();

	void on_pushAddNonFaces_clicked();
	void on_pushRemoveNonFaces_clicked();

	void on_pushTrain_clicked();
	void on_pushRandomize_clicked();

	void on_pushToXML_clicked();
	
	void propagationException(const char *message);
	void propagationFinished();
signals:
	void newNetwork(Network* newNet);
private:
	void addNewHiddenLayer(int neurons = 0);

	void loadTrainingData(TrainingImagesWorker&trainingData);
	void trainNetwork();
	
	void loadListsForTraining(TrainingImagesWorker& trainingImages);
	void createTargetSets(	vector<vector<double> >& targetFaces,
			      	vector<vector<double> >& targetNonFaces,
	 			unsigned int faces,
     				unsigned int nonFaces);
	
	Network* network;
	Backpropagation *backpropaginator;
	std::list<QSpinBox*> hiddenSpinners;

	bool inputChanged;
	bool hiddenChanged;
	bool outputChanged;

	int inputNeurons;
	int outputNeurons;
	int hiddenLayers;
	
	std::vector<int> hiddenNeurons;
};

#endif
