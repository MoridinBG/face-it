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
#include "qxmlpersistance.h"

using namespace std;
void QXmlPersistance::exportToXml(QString filename)
{
	Layer* inputLayer = network->getInputLayer();
	vector<Layer*> hiddenLayers = network->getHiddenLayers();
	Layer* outputLayer = network->getOutputLayer();

	
	
	QFile xmlFile(filename);
	xmlFile.open(QIODevice::WriteOnly);
	
	QXmlStreamWriter writer((&xmlFile));
	writer.setAutoFormatting(true);
	
     	writer.writeStartDocument();
	writer.writeDTD("<!DOCTYPE NeuralNetwork>");
     	writer.writeStartElement("NeuralNetowrk");

     		writer.writeStartElement("Layer");
			writer.writeAttribute("level", "input");
			exportLayer(writer,inputLayer);
     		writer.writeEndElement();

     		writer.writeStartElement("HiddenLayers");
			writer.writeAttribute("layers", QString::number(hiddenLayers.size()));
     			for(unsigned int i = 0; i < hiddenLayers.size(); ++i)
     			{
				writer.writeStartElement("Layer");
					writer.writeAttribute("level", "hidden");
					exportLayer(writer,hiddenLayers[i]);
				writer.writeEndElement();
			}
		writer.writeEndElement();

		writer.writeStartElement("Layer");
			writer.writeAttribute("level", "output");
			exportLayer(writer,outputLayer);
		writer.writeEndElement();
		
	writer.writeEndElement();
	writer.writeEndDocument();
	xmlFile.flush();
}

void QXmlPersistance::loadNetwork(Network * _network)
{
	if(_network == NULL)
		throw Exception("Can not persist a NULL network.");
	else
		network = _network;
}

void QXmlPersistance::exportLayer(QXmlStreamWriter & writer, Layer * layer)
{
	vector<Neuron*> neurons;
	neurons = layer->getNeurons();
	
	writer.writeAttribute("Neurons",  QString::number(neurons.size()));
	
	for(unsigned int i = 0; i < neurons.size(); ++i)
	{
		Neuron* neuron = neurons[i];
		std::vector<double> weights = neuron->getWeights();
		std::vector<double> weightChanges = neuron->getWeightChanges();

		unsigned int numChanges = weightChanges.size();
		unsigned int numWeights = weights.size();
				
		writer.writeStartElement("Neuron");
				
		writer.writeStartElement("Weights");
		writer.writeAttribute("Number",  QString::number(numWeights));
		for(unsigned int j = 0; j < numWeights; ++j)
			writer.writeTextElement("weight", QString::number(weights[j]));
		writer.writeEndElement();
					
		writer.writeStartElement("Changes");
		writer.writeAttribute("Number",  QString::number(numChanges));
		for(unsigned int j = 0; j < numChanges; ++j)
			writer.writeTextElement("change", QString::number(weightChanges[j]));
		writer.writeEndElement();
		writer.writeEndElement();
	}
}

Network * QXmlPersistance::importFromXml(QString filename)
{
	QFile xmlFile(filename);
	xmlFile.open(QIODevice::ReadOnly);
	
	QXmlStreamReader reader((&xmlFile));


	while(!reader.atEnd())
	{
		reader.readNext();
	}
	return 0;
}


