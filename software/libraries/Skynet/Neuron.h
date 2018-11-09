#pragma once

#include <vector>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include "Layer.h"
#include "Activations.h"
#include "Connections.h"

using namespace std;

class Neuron {
private:
	double                 m_dOutput;                            //output
	vector < Connections > m_vOutputWeight;            //vector to represent the weighted connections to next layer
	int                    m_iIndex;                                //index of that neuron
	double                 m_dGradient;                            //Gradient value for training
	double                 m_dEta;                                //training rate
	double                 m_dAlpha;                            //momentum
	SkyNet::Activations    m_activation;

	double activation (double val);                //returns activated value using fast sigmoid function
	double activationDerivative (double val);    //returns derivative of activated value

public:

	//constructor
	Neuron (const int &numOutputs, const int &index, const SkyNet::Activations &function);

	// constructor
	Neuron (int numOutputs, int index);
	//set Output for that neuron
	void setOutput (double val);
	//get Output for that neuron
	double getOutput ( );
	//generates random double between 0 and 1 for weights
	double randWeight ( );
	//neuron's feedForward, different from SkyNet
	void feedForward (Layer &prevLayer);

	//calculates new Gradient for output layer neuron
	double getOutputGradient (double targetVal);
	//calculates new Gradient for hidden layer neuron
	double getHiddenGradient (Layer &nextLayer);
	//training stuff, don't worry about it
	double sumLayer (Layer &nextLayer);
	//updates weights for training
	void updateWeights (Layer &prevLayer);
	// Loading neuron from file
	friend std::ofstream &operator << (std::ofstream &ofs, const Neuron &node);
	// Saving neuron to file
	friend std::ifstream &operator >> (std::ifstream &ifs, Neuron &node);
	friend std::ostream &operator << (std::ostream &os, const Neuron &node);
};

