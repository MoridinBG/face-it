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
#include "network.h"

/**
 * Creates a new network with given topology
 * @param numInput Neurons at input layer
 * @param numOutput Neurons at output layer
 * @param hidden Vector with sizes of hidden layers. Started from input to output. For N hidden layers hidden.at(0) is the hidden layer right after the input and hidden.at(n - 1) is the layer just before the output layer
 */
Network::Network(unsigned int numInput, unsigned int numOutput, std::vector<unsigned int> hidden)
{
	if(numInput == 0)
		throw Exception("[NETWORK] Can not create inputless network. Network must have at least one input");

	if(numOutput == 0)
		throw Exception("[NETWORK] Can not create outputless network. Network must have at least one output");

	inputLayer = new Layer(numInput,1,true);

	//Iterrates the hidden layers. Creates a layer with neurons with number of inputs
	//equal to the number of the neurons at the previous layer
	if(hidden.size() > 0)
	{
		std::vector<unsigned int>::iterator current = hidden.begin();
		std::vector<unsigned int>::iterator previous = current;
		hiddenLayers.push_back(new Layer(*current,numInput, false));
		current++;
 		for(current = current; current < hidden.end(); current++)
		{
 			hiddenLayers.push_back(new Layer(*current,*previous,false));
			previous++;
		}
 		outputLayer = new Layer(numOutput,*previous,false);
		
	}
	//In case there are no hidden layers
	else
		outputLayer = new Layer(numOutput,numInput,false);
}

Network::Network(const Network & network)
{
	inputLayer = network.inputLayer;
	hiddenLayers = network.hiddenLayers;
	outputLayer = outputLayer;
}

Network& Network::operator=(Network& other)
{
	if(this !=& other)
	{
		delete inputLayer;
		for(unsigned int i = 0; i < hiddenLayers.size(); ++i)
			delete hiddenLayers[i];
		hiddenLayers.clear();
		delete outputLayer;
			
		inputLayer = other.inputLayer;
		hiddenLayers = other.hiddenLayers;
		outputLayer = other.outputLayer;
	}
		
	return *this;
}

Network::Network()
{
}
/**
 * Deletes created layers
 */
Network::~Network()
{
	delete inputLayer;
	delete outputLayer;
	for(unsigned i = 0; i < hiddenLayers.size(); i++)
		delete hiddenLayers[i];
}


/**
 * Calculates output of the entire network by calculating the output for every layer and feeding it as input for the next layer.
 * @param input Input for the network. The number of inputs must equal the number of neurons in the input layer.
 * @return The output of the network
 */
std::vector< double > Network::calculateOutput(const std::vector< double >& input)
{
	if(input.size() != inputLayer->numNeurons())
		throw Exception("[NETWORK] Input vector size differs from number of input neurons.");
		
	inputLayer->calculateOutputs(input);
	//Iterrates through the hidden layers if there are any
	if (hiddenLayers.size() > 0)
	{
		//Feeds the input to the first hidden layer
		hiddenLayers[0]->calculateOutputs(inputLayer->getOutputs());
		
		//If there is more than one hidden layer feed the output from the previous one for input
		for(unsigned int i = 1; i < hiddenLayers.size(); i ++)
			hiddenLayers[i]->calculateOutputs(hiddenLayers[i-1]->getOutputs());

		//Feeds the output of the last hidden layer to the output layer
		outputLayer->calculateOutputs(hiddenLayers[hiddenLayers.size()-1]->getOutputs());
	}
	//If there are no hidden layers passes the input directly to the output layer
	else
		outputLayer->calculateOutputs(inputLayer->getOutputs());
	
	return outputLayer->getOutputs();

}

/**
 * Returns the output of the outputlayer for the last set of inputs
 * @return Vector of doubles with the output of the network
 */
const std::vector< double >& Network::getOutput()
{
	if(outputLayer->getOutputs().size() == 0)
		throw Exception("[NETWORK] Network has not calculated any output yet.");

	const std::vector< double >& _outputs = outputLayer->getOutputs();
		return _outputs;
}

/**
 * Returns vector with all the hidden layers
 * @return Vector with hidden layers.
 */
const std::vector< Layer * >& Network::getHiddenLayers() const
{
	const std::vector< Layer * >& _hiddenLayers = hiddenLayers;
	return _hiddenLayers;
}

/**
 * Returns the output layer
 * @return Output layer object
 */
Layer* Network::getOutputLayer() const
{
	return outputLayer;
}

/**
 * Returns the input layer
 * @return In[ut layer object
 */
Layer* Network::getInputLayer() const
{
	return inputLayer;
}

/**
 * Returns the number of inputs for the network
 * @return Number of inputs
 */
unsigned int Network::getInputSize() const
{
	return inputLayer->numNeurons();
}

unsigned int Network::getHiddenSize() const
{
	return hiddenLayers.size();
}


unsigned int Network::getOutputSize() const
{
	return outputLayer->numNeurons();
}


void Network::setInputLayer(Layer * layer)
{
	inputLayer = layer;
}

void Network::setOutputLayer(Layer * layer)
{
	outputLayer = layer;
}

void Network::setHiddenLayers(const std::vector< Layer * > & layers)
{
	hiddenLayers = layers;
}
