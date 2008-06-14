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
#include "backpropagation.h"

/**
 * Dummy constructor. Creates an empty Backpropagation object.
 */
Backpropagation::Backpropagation(Network* _network,
		unsigned int _iterations,
  		QObject *parent) :QThread(parent)
{
	iterations = _iterations;
	byErrorRate = false;
	network = _network;
	
	connect(this,SIGNAL(cycleFinished()),this,SLOT(checkProgress()));
}

Backpropagation::Backpropagation(Network* _network,
		double _error,
		QObject *parent) :QThread(parent)
{
	error = _error;
	byErrorRate = true;
	network = _network;
	connect(this,SIGNAL(cycleFinished()),this,SLOT(checkProgress()));
}

Backpropagation::~Backpropagation()
{
}

/**
 * Overloaded function provided for loading more than one input/target pair
 * @param _inputs Vector of input vectors 
 * @param _targets Vector of target vectors
 * @param _learningRate Rate for changing the weights. Higher values would provide faster, but less accurate teaching, smaller for slower and more accurate one.0.2 is a common value.
 * @param _momentum Used to provide momentum to the teaching. Uses part of the previous change in the weights. 0.8 is common value.t
 */
void Backpropagation::loadParameters(	std::vector<std::vector<double> > _inputs,
					std::vector<std::vector<double> > _targets,
     					std::vector<std::vector<double> > _untrainedInputs,
     					std::vector<std::vector<double> > _untrainedTargets,
     					double _learningRate,
     					double _momentum)
{
	if (_inputs.size() != _targets.size())
		emit exception("[BACKPROPAGATION] Number of targets must equal number of inputs.");

	if (_untrainedInputs.size() != _untrainedTargets.size())
		emit exception("[BACKPROPAGATION] Number of targets must equal number of inputs.");
		
	for(unsigned int i = 0; i < _targets.size(); ++i)
		if(!checkTargets(_targets[i]))
			emit exception("[BACKPROPAGATION] Incorrect target vector fed.");

	for(unsigned int i = 0; i < _untrainedTargets.size(); ++i)
		if(!checkTargets(_untrainedTargets[i]))
			emit exception("[BACKPROPAGATION] Incorrect untrained target vector fed.");
	
	targets = _targets;
	inputs = _inputs;

	untrainedInputs = _untrainedInputs;
	untrainedTargets = _untrainedTargets;
	
	momentum = _momentum;
	learningRate = _learningRate;
}
/**
 * Performs the backpropagation,
 * @param _network Network on which to perform backpropagation
 * @param iterations Number of iterations to perform
 * @return True for successful backpropagation, otherwise false.
 */
void Backpropagation::backpropagate()
{
	//Clear all vectors from previous iterrations
	actual.clear();
	outputErrorSignals.clear();
	networkLayers.clear();
	hiddenLayers.clear();

	//Pick up a random pair of Input and Targeted output
	int lotary = rand() % inputs.size();
	target = targets[lotary];
	input = inputs[lotary];

	//Calculate the output of the layer for this input
	network->calculateOutput(input);
	actual = network->getOutput();

	//Calculate the error of the network and make a small adjustement to the weights of the neurons.
	calculateErrorSignals();
}

/**
 * Checks if expected values are in the 0 to 1 range.
 * @param target Target vector
 * @return True for correct target vector, otherwise false.
 */
bool Backpropagation::checkTargets(std::vector<double>& target)
{
	for (unsigned int i = 0; i < target.size(); ++i)
		if ((target[i] < 0) || (target[i] > 1))
			return false;

	return true;
}

/**
 * Calculates the error caused by wrong weight values
 */
void Backpropagation::calculateErrorSignals()
{
	ErrorSignalCalculator *calculator = new ErrorSignalCalculator();
	connect(calculator,SIGNAL(signalsCalculated()),this,SLOT(changeWeights()));
	
	//Calculate the error signal of the output layer
	for(unsigned int i = 0; i < actual.size(); i++)
	{
		double errorSignal = actual[i] * ((1 - actual[i]) * (target[i] - actual[i]));
		outputErrorSignals.push_back(errorSignal);
	}
	network->getOutputLayer()->setErrorSignal(outputErrorSignals);
	
	calculator->calculateErrorSignals(network);
}

/**
 * Makes corrections on the weights according to the error they cause.
 */
void Backpropagation::changeWeights()
{
	WeightChanger *changer = new WeightChanger();
	connect(changer,SIGNAL(weightsChanged()),this,SIGNAL(cycleFinished()));
	
	changer->changeWeights(network,
				momentum,
	 			learningRate);

}

void Backpropagation::appendTrainedParameters(std::vector< std::vector < double > > _inputs,
					      std::vector< std::vector < double > > _targets)
{
	if(_inputs.size() != _targets.size())
		emit exception("[BACKPROPAGATION] Mismatching number of inputs and targets provided.");
	
	inputs.insert(inputs.begin(),_inputs.begin(),_inputs.end());
	targets.insert(targets.begin(),_targets.begin(),_targets.end());
}

void Backpropagation::appendUntrainedParameters(std::vector< std::vector < double > > _untrainedInputs,
		 				std::vector< std::vector < double > > _untrainedTargets)
{
	if(_untrainedInputs.size() != _untrainedTargets.size())
		emit exception("[BACKPROPAGATION] Mismatching number of untrained inputs and untrained targets provided.");

	untrainedInputs.insert(untrainedInputs.begin(),_untrainedInputs.begin(),_untrainedInputs.end());
	untrainedTargets.insert(untrainedTargets.begin(),_untrainedTargets.begin(),_untrainedTargets.end());
}

/*!
    \fn Backpropagation::checkData()
 */
void Backpropagation::checkData(Network* _network)
{
	if(_network == 0)
		emit exception("[BACKPROPAGATION] Null network provided for training.");
	
	if((inputs.size() == 0) || (targets.size() == 0) || (learningRate == 0))
		emit exception("[BACKPROPAGATION] Learning parameters not correctly set.");

	for(unsigned int i = 0; i < inputs.size(); ++i)
		if(inputs[i].size() != _network->getInputSize())
		{
			emit exception("[BACKPROPAGATION] An input vector unsuitable for this network provided.");
		}

	for(unsigned int i = 0; i < untrainedInputs.size(); ++i)
		if(untrainedInputs[i].size() != _network->getInputSize())
		{
			emit exception("[BACKPROPAGATION] An untrained input vector unsuitable for this network provided.");
		}

	if(momentum == 0)
		std::cout << "WARNING: Momentum is 0. This may slow down training." << endl;
}

/*!
    \fn Backpropagation::calculateError()
 */
double Backpropagation::calculateError()
{
	double error = 0;
	int faces = 0;
	
    	for(unsigned int i = 0; i < untrainedInputs.size(); ++i)
    	{
		network->calculateOutput(untrainedInputs[i]);
		error += (untrainedTargets[i][0] - network->getOutput()[0]) * (untrainedTargets[i][0] - network->getOutput()[0]);
		if(network->getOutput()[0] > 0.6)
			faces += 1;
    	}

	error = error / untrainedInputs.size();
	std::cout << "Error : " << error;
	std::cout << " Faces: " << faces << " out of " << untrainedInputs.size() << " images." << std::endl;
	return error;
	
}

void Backpropagation::run()
{
	checkData(network);
	currentIterration = 0;
	backpropagate();
}


void Backpropagation::checkProgress()
{
	if(byErrorRate)
		if(currentIterration < UNCHECKED_BACKPROPAGATIONS)
		{
			currentIterration++;
			backpropagate();
		}
		else
			if (calculateError() > error)
			{
				currentIterration = 0;
				backpropagate();
			}
			else
			{
				emit propagated();
				return;
			}
	else
		if(iterations > 1)
		{
			iterations--;
			backpropagate();
		}
		else
		{
			emit propagated();
			return;
		}
		
}
