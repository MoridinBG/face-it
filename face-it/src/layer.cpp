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
#include "layer.h"
/**
 * Constructor for layers
 * @param _numOfNeurons Number of neurons in this layer.
 * @param inputsPerNeuron Number of inputs per neuron. Generally it must equal the number of neurons in the previous layer or 1 for an input layer.
 * @param isInput Boolean flag determing if the layer is input (neurons have weights of 1)
 */
Layer::Layer(unsigned int _numOfNeurons, unsigned int inputsPerNeuron, bool isInput = false)
{
	numOfNeurons = _numOfNeurons;

	for(unsigned int i = 0; i < numOfNeurons; ++i)
		neurons.push_back(new Neuron(inputsPerNeuron,isInput));
	
	errorSignal.reserve(numOfNeurons);
	for(unsigned int i = 0; i < numOfNeurons; ++i)
		errorSignal.push_back(0);
}

Layer::Layer(const Layer &layer)
{
	numOfNeurons = layer.numNeurons();
	
	for(unsigned int i = 0; i < numOfNeurons; ++i)
	{
		Neuron* newNeuron = new Neuron( layer.getNumOfInputs(),
				  		layer.isInput());
		
		newNeuron->setWeights(layer.neurons[i]->getWeights());
		newNeuron->setWeightChanges(layer.neurons[i]->getWeightChanges());

		neurons.push_back(newNeuron);
	}
}

Layer& Layer::operator=(const Layer& other)
{
	if(this !=& other)
	{
		for(unsigned int i = 0; i < neurons.size(); ++i)
			delete neurons[i];
		neurons.clear();

		for(unsigned int i = 0; i < other.neurons.size(); ++i)
		{
			Neuron* newNeuron = new Neuron(other.getNumOfInputs(),
						       other.isInput());
			newNeuron->setWeightChanges(other.neurons[i]->getWeightChanges());
			newNeuron->setWeights(other.neurons[i]->getWeights());

			neurons.push_back(newNeuron);
		}
	}
		return *this;
}

/**
 * Deletes the neurons at this layer
 */
Layer::~Layer()
{
	for(unsigned int i = 0; i < neurons.size(); ++i)
		delete neurons[i];
}

/**
 * Returns the number of neurons
 * @return Number of neurons
 */
unsigned int Layer::numNeurons() const
{
	return numOfNeurons;
}

/**
 * Returns the output of this layer for the last set of inputs
 * @return Vector of doubles with outputs of all neurons
 */
const std::vector< double >& Layer::getOutputs()
{
	std::vector< double >& _outputs = outputs;
	return _outputs;
}

/**
 * Calculates the output of hidden and output layers.
 * @param input Input vector. Number of inputs must equal number of neurons in the previous layer.
 */
void Layer::calculateOutputs(const std::vector< double >& input)
{
	outputs.clear();
	
	if(neurons[0]->checkInput())
		calculateInputLayer(input);
	else
		for (unsigned int i = 0; i < neurons.size(); ++i)
			outputs.push_back(neurons[i]->calculateOutput(input));
}

/**
 * Returns vector with the neurons at this layer
 * @return Vector of Neuron*
 */
const std::vector< Neuron * >& Layer::getNeurons()
{
	const std::vector< Neuron * >& _neurons = neurons;
	return _neurons;
}

/**
 * Returns vector with error signals for all neurons at this layer.
 * @return Vector of doubles representing error signals
 */
const std::vector< double >& Layer::getErrorSignal() const
{
	const std::vector< double >& _errorSignal = errorSignal;
	return _errorSignal;
}

/**
 * Sets a new errorSignal vector
 * @param theValue vector of doubles
 */
void Layer::setErrorSignal ( const std::vector< double >& theValue )
{
	if(theValue.size() != numOfNeurons)
		throw Exception("[LAYER] Number of error signals differs from number of neurons at this layer.");
	else	
		errorSignal = theValue;
}

void Layer::calculateInputLayer(const std::vector< double >& input)
{
	for (unsigned int i = 0; i < neurons.size(); ++i)
		outputs.push_back(neurons[i]->passInput(input[i]));
}

unsigned int Layer::getNumOfInputs() const
{
	return neurons[0]->getNumOfInputs();
}

bool Layer::isInput() const
{
	return neurons[0]->checkInput();
}
