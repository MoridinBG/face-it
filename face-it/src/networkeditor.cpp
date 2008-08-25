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
#include "networkeditor.h"
using namespace std;

NetworkEditor::NetworkEditor(Network *net,QWidget *parent) : QDialog(parent)
{

	network = net;

	inputNeurons = network->getInputSize();
	outputNeurons = network->getOutputSize();
	hiddenLayers = network->getHiddenSize();

	setupUi(this);

	inputChanged = FALSE;
	hiddenChanged = FALSE;
	outputChanged = FALSE;

	spinInputNeurons->setValue(network->getInputSize());
	spinHiddenLayers->setValue(network->getHiddenSize());
	spinOutputNeurons->setValue(network->getOutputSize());
	for (unsigned int i = 0; i < network->getHiddenSize(); ++i)
		addNewHiddenLayer(network->getHiddenLayers()[i]->numNeurons());
		
	std::list<QSpinBox*>::iterator it;
	for(it = hiddenSpinners.begin(); it != hiddenSpinners.end(); ++it)
		hiddenNeurons.push_back(((QSpinBox*)*it)->value());
}

void NetworkEditor::on_spinInputNeurons_valueChanged(int i)
{
	if(i == inputNeurons)
		return;
	if(i > inputNeurons)
	{
// 		QMessageBox::StandardButton choice = QMessageBox::question(	this,
// 								"Change network structure",
// 								"Are you sure you want to change the network? It will need to be trained again!",
// 								QMessageBox::Yes|QMessageBox::No);
// 		if(choice == QMessageBox::Yes)
// 		{
			inputNeurons = spinInputNeurons->value();
			inputChanged = TRUE;
// 		}
// 		else
// 			spinInputNeurons->setValue(i - 1);
	}
	else
	{
// 		QMessageBox::StandardButton choice = QMessageBox::question(	this,
// 								"Change network structure",
// 								"Are you sure you want to change the network? It will need to be trained again!",
// 								QMessageBox::Yes|QMessageBox::No);
// 		if(choice == QMessageBox::Yes)
// 		{
			inputNeurons = spinInputNeurons->value();
			inputChanged = TRUE;
/*		}
		else
			spinInputNeurons->setValue(i + 1);
	*/}
	
}

void NetworkEditor::on_spinHiddenLayers_valueChanged(int i)
{
	if(i == hiddenLayers)
		return;
	if(i > hiddenLayers)
	{
// 		QMessageBox::StandardButton choice = QMessageBox::question(	this,
// 								"Change network structure",
// 								"Are you sure you want to change the network? It will need to be trained again!",
// 								QMessageBox::Yes|QMessageBox::No);
// 		if(choice == QMessageBox::Yes)
// 		{
			hiddenChanged = TRUE;
			for(int j = 0; j < (i - hiddenLayers); ++j)
				addNewHiddenLayer();
			hiddenLayers = spinHiddenLayers->value();
// 		}
// 		else
// 			spinHiddenLayers->setValue(i - 1);
	}
	else
	{
// 		QMessageBox::StandardButton choice = QMessageBox::question(	this,
// 								"Change network structure",
// 								"Are you sure you want to change the network? It will need to be trained again!",
// 								QMessageBox::Yes|QMessageBox::No);
// 		if(choice == QMessageBox::Yes)
// 		{
			hiddenChanged = TRUE;
			
			for(int j = 0; j < (hiddenLayers - i); ++j)
			{
				QSpinBox* deprecatedLayer = hiddenSpinners.back();
				deprecatedLayer->close();
				delete deprecatedLayer;
				hiddenSpinners.pop_back();
			}
			
			hiddenLayers = spinHiddenLayers->value();;
// 		}
// 		else
// 			spinHiddenLayers->setValue(i + 1);
	}
		
}

void NetworkEditor::on_spinOutputNeurons_valueChanged(int i)
{
	if(i == outputNeurons)
		return;
	if(i > outputNeurons)
	{
// 		QMessageBox::StandardButton choice = QMessageBox::question(	this,
// 								"Change network structure",
// 								"Are you sure you want to change the network? It will need to be trained again!",
// 								QMessageBox::Yes|QMessageBox::No);
// 		if(choice == QMessageBox::Yes)
// 		{
			outputNeurons = spinOutputNeurons->value();
			outputChanged = TRUE;
// 		}
// 		else
// 			spinOutputNeurons->setValue(i - 1);
 	}
	else
	{
// 		QMessageBox::StandardButton choice = QMessageBox::question(	this,
// 								"Change network structure",
// 								"Are you sure you want to change the network? It will need to be trained again!",
// 								QMessageBox::Yes|QMessageBox::No);
// 		if(choice == QMessageBox::Yes)
// 		{
			outputNeurons = spinOutputNeurons->value();
			outputChanged = TRUE;
		}
// 		else
// 			spinOutputNeurons->setValue(i + 1);
// 	}
	
}

void NetworkEditor::addNewHiddenLayer(int neurons)
{
		QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		QSpinBox* newSpin = new QSpinBox(this);
		newSpin->show();
		vboxLayout4->addWidget(newSpin);
		hiddenSpinners.push_back(newSpin);
		newSpin->setValue(neurons);
		newSpin->setMaximum(9999);
}

void NetworkEditor::on_pushCommit_clicked()
{
	std::list<QSpinBox*>::iterator it;
	
	if(hiddenChanged)
		for(it = hiddenSpinners.begin(); it != hiddenSpinners.end(); ++it)
		{
			if(((QSpinBox*)*it)->value() == 0)
			{
				QMessageBox::critical(	this,
							"Zero neurons",
      							"You can not have zero neurons in a hidden layer! Hidden Layers not updated!");
				return;
			}
		}
			
	if(inputChanged)
		if(spinInputNeurons->value() == 0)
		{
			QMessageBox::critical(	this,
						"Zero neurons",
						"You can not have zero neurons in the input layer!");
			return;
		}
	
	if(outputChanged)
		if(spinOutputNeurons->value() == 0)
		{
			QMessageBox::critical(	this,
						"Zero neurons",
						"You can not have zero neurons in the output layer!");
			return;
		}

	std::vector<unsigned> hiddens;
	for(it = hiddenSpinners.begin(); it != hiddenSpinners.end(); ++it)
		hiddens.push_back(((QSpinBox*)*it)->value());
	
	network = new Network((unsigned)spinInputNeurons->value(),
			      (unsigned)spinOutputNeurons->value(),
			      hiddens);
	emit newNetwork(network);

	inputChanged = FALSE;
	outputChanged = FALSE;
	hiddenChanged = FALSE;
}


void NetworkEditor::on_pushDone_clicked()
{
	if(inputChanged || hiddenChanged || outputChanged)
	{
		QMessageBox::StandardButton choice = QMessageBox::warning(this,
									"Uncomitted changes",
									"You have uncomitted changes. Are you sure you want to leave them?",
									QMessageBox::Yes|QMessageBox::No);
		if(choice == QMessageBox::Yes)
			accept();
		else
			return;
	}
	accept();
}

void NetworkEditor::on_pushAddFaces_clicked()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this,
								"Open File",
                                                 		"",
                                                 		"Images (*.png *.xpm *.jpg *.jpeg *.bmp)");
	listFaces->addItems(fileNames);
	labelFaces->setText("(" + QString::number(listFaces->count()) + ")");
}

void NetworkEditor::on_pushRemoveFaces_clicked()
{
	QList<QListWidgetItem *> faces = listFaces->selectedItems();
	if(faces.size() == 0)
		return;
	delete listFaces->takeItem(listFaces->currentRow());
	labelFaces->setText("(" + QString::number(listFaces->count()) + ")");
}

void NetworkEditor::on_listFaces_itemSelectionChanged()
{
	QList<QListWidgetItem *> faces = listFaces->selectedItems();
	if(faces.size() == 0)
		return;
	QListWidgetItem* face = faces.last();
	QString filename = face->text();
	QImage preview(filename);
	if(!preview.isNull())
	{
		trainingData.applyMask(preview);
		imagePreview->setPixmap(QPixmap::fromImage(preview));
	}
	else
	{
		QBrush brush;
		brush.setColor(QColor(255,0,0));
		face->setForeground(brush);
	}
	listNonFaces->clearSelection();
}

void NetworkEditor::on_pushAddNonFaces_clicked()
{
	QStringList fileNames = QFileDialog::getOpenFileNames(this,
								"Open File",
                                                 		"",
                                                 		"Images (*.png *.xpm *.jpg *.jpeg *.bmp)");
	listNonFaces->addItems(fileNames);
	labelNonFaces->setText("(" + QString::number(listNonFaces->count()) + ")");
}

void NetworkEditor::on_pushRemoveNonFaces_clicked()
{
	QList<QListWidgetItem *> nonFaces = listNonFaces->selectedItems();
	if(nonFaces.size() == 0)
		return;
	delete listNonFaces->takeItem(listNonFaces->currentRow());
	labelNonFaces->setText("(" + QString::number(listNonFaces->count()) + ")");
}

void NetworkEditor::on_listNonFaces_itemSelectionChanged()
{
	QList<QListWidgetItem *> nonFaces = listNonFaces->selectedItems();
	if(nonFaces.size() == 0)
		return;
	QListWidgetItem* nonFace = nonFaces.last();
	QString filename = nonFace->text();
	QImage preview(filename);
	if(!preview.isNull())
	{
		trainingData.applyMask(preview);
		imagePreview->setPixmap(QPixmap::fromImage(preview));
	}
	else
	{
		QBrush brush;
		brush.setColor(QColor(255,0,0));
		nonFace->setForeground(brush);
	}	
	listFaces->clearSelection();
}

void NetworkEditor::on_pushTrain_clicked()
{
	if(listFaces->count() == 0)
	{
		QMessageBox::warning(	this,
					"Empty list of faces",
					"The list of training faces is empty. Add some faces first!");
		return;
	}
	
	if(listNonFaces->count() == 0)
	{
		QMessageBox::warning(	this,
					"Empty list of nonFaces",
					"The list of training non-faces is empty. Add some non-faces first!");
		return;
	}
	startTraining();
}

void NetworkEditor::on_pushRandomize_clicked()
{
	QMessageBox::StandardButton choice = QMessageBox::question(	this,
							"Change network structure",
							"Are you sure you want to change the network? It will need to be trained again!",
							QMessageBox::Yes|QMessageBox::No);
	if(choice == QMessageBox::No)
		return;

	int inputs = network->getInputSize();
	int outputs = network->getOutputSize();
	vector<unsigned int> hiddens;

 	for (unsigned int i = 0; i < network->getHiddenSize(); ++i)
 		hiddens.push_back(((int)network->getHiddenLayers()[i]->numNeurons()));

	network = new Network(inputs, outputs, hiddens);
	emit newNetwork(network);
}

void NetworkEditor::startTraining()
{
	trainingData.setRanges(spinWidth->value(),
				spinHeight->value());
	progress = new Progress(this);
	trainer = new Backpropagation(network,spinError->value(),this);
	progress->show();
	connect(trainer,SIGNAL(exception(const char*)),this,SLOT(propagationException(const char*)));
	connect(trainer,SIGNAL(propagated()),this,SLOT(propagationFinished()));
	connect(trainer,SIGNAL(errr(double)),progress,SLOT(setProgress(double)));
	try
	{
		loadTrainingData();
		trainer->start();
	}
	catch(Exception& ex)
	{
		qDebug() << "Error: " << ex.what();
		QMessageBox::critical(  this,
				        "Error backpropagating",
	  				"There was an error while backpropagating network. Network NOT trained!");
		return;
	}
}

void NetworkEditor::loadListsForTraining()
{
	QStringList faceNames;
	QStringList nonFaceNames;
	
	listNonFaces->selectAll();
	const QList<QListWidgetItem*> nonFaceItems = listNonFaces->selectedItems();
	for(QList<QListWidgetItem*>::const_iterator it = nonFaceItems.begin(); it != nonFaceItems.end(); ++it)
	{
		if(((QListWidgetItem*)*it)->foreground().color().red() == 255)
			continue;
		nonFaceNames.push_back(((QListWidgetItem*)*it)->text());
	}
	trainingData.setNonFaces(nonFaceNames);
	
	listFaces->selectAll();
	const QList<QListWidgetItem*> faceItems = listFaces->selectedItems();
	
	for(QList<QListWidgetItem*>::const_iterator it = faceItems.begin(); it != faceItems.end(); ++it)
	{
		if(((QListWidgetItem*)*it)->foreground().color().red() == 255)
			continue;
		faceNames.push_back(((QListWidgetItem*)*it)->text());
	}
	trainingData.setFaces(faceNames);
	
	try
	{
		trainingData.load();
	}
	catch (Exception& e)
	{
		qDebug() << "Could not load training images. Reason: " << e.what();
	}
}

void NetworkEditor::createTargetSets(	vector< vector < double > >& targetFaces,
				     	vector< vector < double > >& targetNonFaces,
	 				unsigned int faces,
      					unsigned int nonFaces)
{
	for(unsigned int i = 0; i < faces; ++i)
	{
		vector<double> target;
		target.push_back(1);
		targetFaces.push_back(target);
	}
	
	for(unsigned int i = 0; i < nonFaces; ++i)
	{
		vector<double> target;
		target.push_back(0);
		targetNonFaces.push_back(target);
	}
}

void NetworkEditor::on_pushToXML_clicked()
{
	QXmlPersistance persist;
	persist.loadNetwork(network);
	persist.exportToXml("/home/fester/network.xml");
}

void NetworkEditor::loadTrainingData()
{
		
	vector< vector < double > > targetFaces;
	vector< vector < double > > targetNonFaces;
	vector< vector < double > > untrainedTargetFaces;
	vector< vector < double > > untrainedTargetNonFaces;
	loadListsForTraining();
	listFaces->clearSelection();
	
	createTargetSets(targetFaces,
			 targetNonFaces,
    			 trainingData.getFaces().size(),
			 trainingData.getNonFaces().size());

	createTargetSets(untrainedTargetFaces,
			 untrainedTargetNonFaces,
    			 trainingData.getUntrainedFaces().size(),
			 trainingData.getUntrainedNonFaces().size());

	trainer->loadParameters( trainingData.getFaces(),
					targetFaces,
    					trainingData.getUntrainedFaces(),
			   		untrainedTargetFaces,
       					spinLearningRate->value(),
		       			spinMomentum->value());
		
	trainer->appendTrainedParameters(trainingData.getNonFaces(),
						targetNonFaces);
	
	trainer->appendUntrainedParameters(trainingData.getUntrainedNonFaces(),
						  untrainedTargetNonFaces);
}

void NetworkEditor::on_spinWidth_valueChanged(int i)
{
	spinInputNeurons->setValue(i * spinHeight->value());
}

void NetworkEditor::on_spinHeight_valueChanged(int i)
{
	spinInputNeurons->setValue(i * spinWidth->value());
}

void NetworkEditor::propagationException(const char * message)
{
	throw Exception(message);
}

void NetworkEditor::propagationFinished()
{
// 	Layer* layer = network->getHiddenLayers()[0];
// 	for(unsigned int i = 0; i < 10; ++i)
// 		qDebug() << layer->getErrorSignal()[i];
	QMessageBox::information(this,
				"Success",
     				"Network successfully trained!");
	delete trainer;
	progress->close();
	delete progress;
}
