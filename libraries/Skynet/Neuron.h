#pragma once

#include <vector>
#include <stdlib.h>
#include <math.h>
#include "Connections.h"
#include "Layer.h"
//#include "Skynet.h"

using namespace std;

//typedef vector<Neuron> Layer;


class Neuron 
{
private:
	double m_dOutput;							//output
	vector<Connections>m_vOutputWeight;			//vector to represent the weighted connections to next layer
	int m_iIndex;								//index of that neuron
	double m_dGradient;							//Gradient value for training
	double m_dEta;								//training rate
	double m_dAlpha;							//momentum

	double activation(double val);				//returns activated value using fast sigmoid function
	double activationDerivative(double val);	//returns derivative of activated value
	
	



public:
	Neuron(int numOutputs, int index);			//constructor
	void setOutput(double val);					//set Output for that neuron
	double getOutput();							//get Output for that neuron
	double randWeight();						//generates random double between 0 and 1 for weights
	void feedForward(Layer &prevLayer);			//neuron's feedForward, different from Skynet

	double getOutputGradient(double targetVal);	//calculates new Gradient for output layer neuron
	double getHiddenGradient(Layer &nextLayer);	//calculates new Gradient for hidden layer neuron
	double sumLayer(Layer &nextLayer);			//training stuff, don't worry abouut it
	void updateWeights(Layer &prevLayer);		//updates weights for training
};
