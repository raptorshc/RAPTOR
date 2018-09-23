#include "Skynet.h"

typedef vector<Neuron>Layer;

Skynet::Skynet(vector<unsigned int> &topology)
{
	int numOutputs;
	unsigned int numLayers = topology.size();
	for (unsigned int i = 0; i < numLayers; i++) //where i is the current layer
	{
		m_vLayers.push_back(Layer());
		if (i == topology.size() - 1)			//if current layer is the final layer
			numOutputs = 0;
		else
			numOutputs = topology[i + 1];

		for (int n = 0; n <= topology[i]; n++) //where n is the current neuron
		{
			m_vLayers.back().push_back(Neuron(numOutputs, n));
			cout << "Made a neuron" << endl;
		}
		m_vLayers.back().back().setOutput(1.0); //set bias
	}
}

void Skynet::feedForward(vector<double> &inputVals)
{
	assert(inputVals.size() == m_vLayers[0].size() - 1);

	//assign inputVals to input neurons
	for (int i = 0; i < inputVals.size(); i++)
	{
		m_vLayers.at(0).at(i).setOutput(inputVals[i]);
	}

	//forward propogation step
	//loops through each neuron in each layer
	for (int i = 1; i < m_vLayers.size(); i++)			//where i is the current layer
	{
		Layer &prevLayer = m_vLayers.at(i - 1);			//reference to previous layer for Neuron to use in its feedForward
		for (int n = 0; n < m_vLayers.at(i).size() - 1; n++)	//where n is the current neuron
		{
			m_vLayers.at(i).at(n).feedForward(prevLayer);
		}
	}
}

void Skynet::backProp(vector<double> &targetVals)
{
	//Calculate errors using root mean square errors
	m_dError = 0.0;
	Layer &output = m_vLayers.back();					//self commenting code for below

	for (int n = 0; n < output.size() - 1; n++)			//loop through neurons in layer excluding bias neuron
	{
		double delta = targetVals[n] - output[n].getOutput();
		m_dError += delta * delta;
	}
	
	//get root mean square
	m_dError /= output.size();							
	m_dError = sqrt(m_dError);

	//stuff for observing training
	recentAverageError = (recentAverageError * recentAverageErrorSmoothing + m_dError)
		/ recentAverageErrorSmoothing + 1.0;

	//Calculate output layer gradients
	for (int n = 0; n < output.size() - 1; n++)			//loop through neurons in layer excluding bias neuron
	{
		output[n].getOutputGradient(targetVals[n]);
	}

	//Calculate hidden layer gradients
	for (int i = m_vLayers.size() - 2; i > 0; i--)		//where i is the current layer because I don't like using l
	{
		Layer &hiddenLayer = m_vLayers[i];				//self commenting code, easier to understand than
		Layer &nextLayer = m_vLayers[i + 1];			//using m_vLayers[whatever]

		for (int n = 0; n < hiddenLayer.size(); n++)
		{
			hiddenLayer[n].getHiddenGradient(nextLayer);
		}
	}

	//update weights
	for (int i = m_vLayers.size() - 1; i > 0; i--)		//Going backwards through the layers starting at rightmost layer
	{
		Layer &prevLayer = m_vLayers[i - 1];			//more self commenting code
		Layer &currentLayer = m_vLayers[i];

		for (int n = 0; n < currentLayer.size() - 1; n++)
		{
			currentLayer[n].updateWeights(prevLayer);
		}
	}
}

void Skynet::getResults(vector<double> &resultVals)
{
	resultVals.clear();
	for (int n = 0; n < m_vLayers.back().size() - 1; n++)
	{
		resultVals.push_back(m_vLayers.back().at(n).getOutput());
	}
}