#include "Neuron.h"

Neuron::Neuron(int numOutputs, int index)
{
	m_iIndex = index;
	for (int numConnections = 0; numConnections < numOutputs; numConnections++) //Creates connections between layers
	{
		m_vOutputWeight.push_back(Connections()); //Adds new connection
		m_vOutputWeight.back().m_dWeight = randWeight(); // assigns random weight to connection

	}
	m_dEta = 0.25;
	m_dAlpha = 0.4;
}

double Neuron::activation(double val)
{
	return val / (1 + fabs(val));
}

double Neuron::activationDerivative(double val)
{
	return val * (1 - val);
}

void Neuron::setOutput(double val)
{
	m_dOutput = val;
}

double Neuron::getOutput()
{
	return m_dOutput;
}

double Neuron::randWeight() //returns random double between 0 and 1
{
	return rand() / double(RAND_MAX); 
}

void Neuron::feedForward(Layer &prevLayer)
{
	double sum = 0;

	for (int n = 0; n < prevLayer.size(); n++)
	{
			sum += prevLayer[n].getOutput() * prevLayer[n].m_vOutputWeight[m_iIndex].m_dWeight;
	}

	m_dOutput = activation(sum);
}

double Neuron::getOutputGradient(double targetVal)
{
	double delta = targetVal - m_dOutput;
	m_dGradient = delta * activationDerivative(m_dOutput);
	return m_dGradient;
}

double Neuron::getHiddenGradient(Layer &nextLayer)
{
	double sum = sumLayer(nextLayer);
	m_dGradient = sum * activationDerivative(m_dOutput);
	return m_dGradient;
}

double Neuron::sumLayer(Layer &nextLayer)
{
	double sum = 0.0;

	for (unsigned n = 0; n < nextLayer.size() - 1; ++n) 
	{
		sum += m_vOutputWeight[n].m_dWeight * nextLayer[n].m_dGradient;
	}

	return sum;
}

void Neuron::updateWeights(Layer &prevLayer)
{
	for (unsigned n = 0; n < prevLayer.size(); ++n)		//for each neuron in prevLayer including bias
	{
		Neuron &neuron = prevLayer[n];
		double oldDeltaWeight = neuron.m_vOutputWeight[m_iIndex].m_dDeltaWeight;

		// train rate *gradient * initial value + momentm + a fraction of previous deltaWeight;
		double newDeltaWeight = m_dEta * neuron.getOutput() * m_dGradient + m_dAlpha * oldDeltaWeight;

		neuron.m_vOutputWeight[m_iIndex].m_dDeltaWeight = newDeltaWeight;
		neuron.m_vOutputWeight[m_iIndex].m_dWeight += newDeltaWeight;
	}
}