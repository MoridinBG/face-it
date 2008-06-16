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
#include "neuron.h"

/**
 * Constructor for new Neuron
 * @param _numOfInputs the number of inputs for the neuron
 * @param _isInput If it is part of the input layer. Then, generally the weights on the inputs should be 1.
 */
Neuron::Neuron(int _numOfInputs, bool _isInput)
{
	numOfInputs = _numOfInputs;
	isInput = _isInput;
	if(isInput)
		for (int i = 0; i < numOfInputs; ++i)
		{
			weightChanges.push_back(0);
			weights.push_back(1);
		}
	else
		for (int i = 0; i < numOfInputs; ++i)
		{
			weightChanges.push_back(0);
			weights.push_back(getRandomWeight());
		}
}


/**
 * Generates random value between -1 and 1, no 0s
 * @return random double between -1 and 1, no 0s
 */
double Neuron::getRandomWeight()
{
	double randomNumber;
	do
	{
		randomNumber = ((double)(rand() % 100) / 100) * 2 - 1;
	} while((randomNumber == 0));
	
	return randomNumber;
}

/**
 * Returns the weight vector for the neuron
 * @return vector of doubles
 */
const std::vector< double >& Neuron::getWeights()
{
	const std::vector< double >& _weights = weights;
	return _weights;
}

/**
 * Calculates the activation for the given input by multipling the inputs with their given weights.
 * @param inputs vector of doubles with the inputs.
 */
void Neuron::calculateActivation(vector< double > inputs)
{
	activation = 0;
	
	//The activation value is the sum of all inputs multiplied by their weights
	for(unsigned int i = 0; i < inputs.size(); ++i)
	{
		activation += inputs[i] * weights[i];
	}
}

/**
 * Calls activation calculation and then squashes the activation value through an output function. Currently a Sigmoid.
 * @param inputs The input vector to be passed to calculateActivation
 * @return The output of the network in the form of vector with values for every output neuron
 */
double Neuron::calculateOutput(const std::vector< double >& inputs) throw (Exception)
{
	calculateActivation(inputs);
	output = (1.0 / (1.0 + exp(0-activation)));

	return output;
}

/**
 * Returns the output of the neuron for the last set of inputs
 * @return Double output
 */
double Neuron::getOutput() const
{
	return output;
}

/**
 * Replaces current weights vector
 * @param newWeights new vector of double
 */
void Neuron::setWeights(const std::vector< double >& newWeights)
{
	weights.clear();
	weights = newWeights;
}

/**
 * Returns the changes to the weights made during backpropagation
 * @return Vector of doubles with the change to every weight of the neuron
 */
const std::vector< double >& Neuron::getWeightChanges() const
{
	const std::vector< double >& _weightChanges = weightChanges;
	return _weightChanges;
}

/**
 * Stores a new vector of weight changes
 * @param theValue The new vector
 */
void Neuron::setWeightChanges ( const std::vector< double >& theValue )
{
	weightChanges = theValue;
}


bool Neuron::checkInput()
{
	return isInput;
}

double Neuron::passInput(double input)
{
	output = input;

	return output;
}


int Neuron::getNumOfInputs() const
{
	return numOfInputs;
}
