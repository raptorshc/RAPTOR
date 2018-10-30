#include "Neuron.h"
#include "Activations.h"

Neuron::Neuron (int numOutputs, int index) {
	m_iIndex = index;
	//Creates connections between layers
	for ( int numConnections = 0; numConnections < numOutputs; numConnections++ ) {
		//Adds new connection
		m_vOutputWeight.push_back( Connections() );
		// assigns random weight to connection
		m_vOutputWeight.back().m_dWeight = randWeight();

	}
	m_dEta   = 0.25;
	m_dAlpha = 0.4;
	this->m_activation = SkyNet::Activations::Leaky_ReLU;
}

Neuron::Neuron (const int &numOutputs, const int &index, const SkyNet::Activations &function) {
	m_iIndex = index;
	//Creates connections between layers
	for ( int numConnections = 0; numConnections < numOutputs; numConnections++ ) {
		//Adds new connection
		m_vOutputWeight.push_back( Connections() );
		// assigns random weight to connection
		m_vOutputWeight.back().m_dWeight = randWeight();

	}
	m_dEta   = 0.25;
	m_dAlpha = 0.4;
	this->m_activation = function;
}

double Neuron::activation (double val) {
	return SkyNet::activation( this->m_activation, val );
}

double Neuron::activationDerivative (double val) {
	return SkyNet::activationDerivative( this->m_activation, val );
}

void Neuron::setOutput (double val) {
	m_dOutput = val;
}

double Neuron::getOutput ( ) {
	return m_dOutput;
}

//returns random double between 0 and 1
double Neuron::randWeight ( ) {
	return rand() / double( RAND_MAX );
}

void Neuron::feedForward (Layer &prevLayer) {
	double sum = 0;

	for ( auto node : prevLayer ) {
		sum += node.getOutput() * node.m_vOutputWeight[ m_iIndex ].m_dWeight;
	}

	m_dOutput = activation( sum );
}

double Neuron::getOutputGradient (double targetVal) {
	double delta = targetVal - m_dOutput;
	m_dGradient = delta * activationDerivative( m_dOutput );
	return m_dGradient;
}

double Neuron::getHiddenGradient (Layer &nextLayer) {
	double sum = sumLayer( nextLayer );
	m_dGradient = sum * activationDerivative( m_dOutput );
	return m_dGradient;
}

double Neuron::sumLayer (Layer &nextLayer) {
	double sum = 0.0;

	// TODO: Why -1?
	for ( unsigned n = 0; n < nextLayer.size() - 1; ++n ) {
		sum += m_vOutputWeight[ n ].m_dWeight * nextLayer[ n ].m_dGradient;
	}

	return sum;
}

void Neuron::updateWeights (Layer &prevLayer) {
	//for each neuron in prevLayer including bias
	for ( auto &neuron : prevLayer ) {
		double oldDeltaWeight = neuron.m_vOutputWeight[ m_iIndex ].m_dDeltaWeight;

		// train rate *gradient * initial value + momentm + a fraction of previous deltaWeight;
		double newDeltaWeight = m_dEta * neuron.getOutput() * m_dGradient + m_dAlpha * oldDeltaWeight;


		neuron.m_vOutputWeight[ m_iIndex ].m_dDeltaWeight = newDeltaWeight;
		neuron.m_vOutputWeight[ m_iIndex ].m_dWeight += newDeltaWeight;
	}
}

std::ofstream &operator << (std::ofstream &ofs, const Neuron &node) {
	for ( auto connection : node.m_vOutputWeight ) {
		ofs << connection.m_dWeight << " ";
	}
	ofs << std::endl;
	return ofs;
}

std::ifstream &operator >> (std::ifstream &ifs, Neuron &node) {
	double    temp_weight;
	for ( int i = 0; i < node.m_vOutputWeight.size(); i++ ) {
		ifs >> temp_weight;
		node.m_vOutputWeight[ i ].m_dWeight = temp_weight;
	}
	return ifs;
}
