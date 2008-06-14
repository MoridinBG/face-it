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
#ifndef LAYER_H
#define LAYER_H

#include "neuron.h"
#include <QDebug>
#include "exception.h"

/**
	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class Layer{
public:
    	Layer(unsigned int _numOfNeurons, unsigned int inputsPerNeuron,bool isInput);
	Layer(const Layer& layer);
    	~Layer();

	Layer& operator=(const Layer& other);

	void calculateOutputs(const std::vector<double>& input);
	
	const std::vector<Neuron*>& getNeurons();
	const std::vector<double>& getOutputs();
	
	unsigned int numNeurons() const;

	void setErrorSignal ( const std::vector< double >& theValue );
	const std::vector< double >& getErrorSignal() const;

	unsigned int getNumOfInputs() const;
	bool isInput() const;
	
private:
	std::vector<Neuron*> neurons;
	std::vector<double> outputs;
	std::vector<double> errorSignal;
	unsigned int numOfNeurons;

	void calculateInputLayer(const std::vector< double >& input);

};

#endif
