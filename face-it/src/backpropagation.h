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
#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include <vector>
#include <iostream>
#include <QThread>
#include <cmath>

#include "network.h"
#include "errorsignalcalculator.h"
#include "weightchanger.h"
/**
	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class Backpropagation : public QThread
{
Q_OBJECT
public:
	Backpropagation(Network* _network,
			unsigned int _iterations,
			QObject *parent = 0);
	Backpropagation(Network* _network,
			double _error,
   			QObject *parent = 0);
    	~Backpropagation();

	void loadParameters(	std::vector<std::vector<double> > _inputs,
				std::vector<std::vector<double> > _targets,
				std::vector<std::vector<double> > _untrainedInputs,
				std::vector<std::vector<double> > _untrainedTargets,
				double _learningRate,
				double _momentum);
	
	void appendTrainedParameters(	std::vector<std::vector<double> > _inputs,
				  	std::vector<std::vector<double> > _targets);
	
	void appendUntrainedParameters(  std::vector<std::vector<double> > _untrainedInputs,
				 	 std::vector<std::vector<double> > _untrainedTargets);

private:
	Network* network;
	std::vector<std::vector<double> > inputs;
	std::vector<std::vector<double> > targets;

	std::vector<double> input;
	std::vector<double> target;

	std::vector<std::vector<double> > untrainedInputs;
	std::vector<std::vector<double> > untrainedTargets;
	
	std::vector<double> actual;
	std::vector<double> outputErrorSignals;
	
	std::vector<Layer*> networkLayers;
	std::vector<Layer*> hiddenLayers;
	
	double learningRate;
	double momentum;
    	static const unsigned int UNCHECKED_BACKPROPAGATIONS = 5;
	
	bool byErrorRate;
	int iterations;
	unsigned int currentIterration;
	double error;
	
//Members
	void checkData(Network* _network);
	bool checkTargets(std::vector<double>& target);
	
	void calculateErrorSignals();
    	double calculateError();
	
	void backpropagate();
private slots:
	void changeWeights();
	void checkProgress();
signals:
	void exception(const char *message);
	void propagated();
	void cycleFinished();
protected:
	void run();
};

#endif
