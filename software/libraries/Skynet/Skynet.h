#pragma once

#include <vector>
#include <iostream>
#include <assert.h>
#include <fstream>
#include "Neuron.h"
#include "Layer.h"

using namespace std;

class Skynet {
private:
	vector < Layer > m_vLayers;                             // m_vLayers[layerNum][neuronNum] 2d grid in that format
	double           m_dError;                              //Error rate for training
	double           recentAverageError;                    //recent average error, purely to watch training progress
	double           recentAverageErrorSmoothing;           //smoothing of error curve to watch training process
public:
	Skynet (vector < unsigned int > &topology);             //constructor
	void feedForward (vector < double > &inputVals);        //input
	void backProp (vector < double > &targetVals);          //training
	void getResults (vector < double > &resultVals);        //output
	friend std::ofstream &operator << (std::ofstream &of, const Skynet &skynet);
	friend std::ifstream &operator >> (std::ifstream &ifs, Skynet &skynet);
};