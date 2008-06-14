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
#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <cmath>
#include "exception.h"
#include <iostream>
#include <cmath>

using namespace std;
/**
	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class Neuron{
public:
    	Neuron(int _numIfInputs,bool _isInput);

	double calculateOutput(const std::vector< double >& inputs) throw (Exception);
	
	const std::vector<double>& getWeights();
	void setWeights(const std::vector<double>& newWeights);

	double getOutput() const;	

	void setWeightChanges ( const std::vector< double >& theValue );
	const std::vector< double >& getWeightChanges() const;

	bool checkInput();
	double passInput(double input);

	int getNumOfInputs() const;
	
	

private:
	double getRandomWeight();
	void calculateActivation(vector<double> inputs);

	vector<double> weights;
	vector<double> weightChanges;
	int numOfInputs;
	double output;
	double activation;
	bool isInput;
};

#endif
