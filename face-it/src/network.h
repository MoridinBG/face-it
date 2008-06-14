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
#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include <vector>

/**
	@author Ivan Dilchovski <root.darkstar@gmail.com>
*/
class Network{
public:
    	Network(unsigned int numInput, unsigned int numOutput, std::vector<unsigned int> hidden);
    	~Network();
	Network();
	Network(const Network & network);
	Network& operator=(Network& other);
	
	std::vector< double > calculateOutput(const std::vector< double >& input);
	const std::vector< double >& getOutput();

	Layer* getOutputLayer() const;
	const std::vector< Layer * >& getHiddenLayers() const;
	Layer* getInputLayer() const;

	unsigned int getInputSize() const;
	unsigned int getHiddenSize() const;
	unsigned int getOutputSize() const;

	void setInputLayer(Layer* layer);
	void setOutputLayer(Layer* layer);
	void setHiddenLayers ( const std::vector< Layer*>& layers);
	
	
private:
	Layer *inputLayer;
	Layer *outputLayer;
	std::vector<Layer*> hiddenLayers;
	std::vector<double> outputs;
};

#endif
