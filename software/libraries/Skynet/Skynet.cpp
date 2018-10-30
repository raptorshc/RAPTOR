#include "Skynet.h"

typedef vector < Neuron > Layer;

Skynet::Skynet (vector < unsigned int > &topology) {
	int                numOutputs;
	unsigned int       numLayers = topology.size();
	//where i is the current layer
	for ( unsigned int i         = 0; i < numLayers; i++ ) {
		m_vLayers.push_back( Layer() );
		//if current layer is the final layer
		if ( i == topology.size() - 1 ) {
			numOutputs = 0;
		} else {
			numOutputs = topology[ i + 1 ];
		}

		//where n is the current neuron
		for ( int n = 0; n <= topology[ i ]; n++ ) {
			m_vLayers.back().push_back( Neuron( numOutputs, n ) );
			//cout << "Made a neuron" << endl;
		}
		//set bias
		m_vLayers.back().back().setOutput( 1.0 );
	}
}

void Skynet::feedForward (vector < double > &inputVals) {
	assert( inputVals.size() == m_vLayers[ 0 ].size() - 1 );

	//assign inputVals to input neurons
	for ( int i = 0; i < inputVals.size(); i++ ) {
		m_vLayers.at( 0 ).at( i ).setOutput( inputVals[ i ] );
	}

	//forward propogation step
	//loops through each neuron in each layer
	//where i is the current layer
	for ( int i = 1; i < m_vLayers.size(); i++ ) {
		//reference to previous layer for Neuron to use in its feedForward
		Layer     &prevLayer = m_vLayers.at( i - 1 );
		//where n is the current neuron
		for ( int n          = 0; n < m_vLayers.at( i ).size() - 1; n++ ) {
			m_vLayers.at( i ).at( n ).feedForward( prevLayer );
		}
	}
}

void Skynet::backProp (vector < double > &targetVals) {
	//Calculate errors using root mean square errors
	m_dError = 0.0;
	//self commenting code for below
	Layer &output = m_vLayers.back();

	//loop through neurons in layer excluding bias neuron
	for ( int n = 0; n < output.size() - 1; n++ ) {
		double delta = targetVals[ n ] - output[ n ].getOutput();
		m_dError += delta * delta;
	}

	//get root mean square
	m_dError /= output.size();
	m_dError    = sqrt( m_dError );

	//stuff for observing training
	recentAverageError = (recentAverageError * recentAverageErrorSmoothing + m_dError)
	                     / recentAverageErrorSmoothing + 1.0;

	//Calculate output layer gradients
	//loop through neurons in layer excluding bias neuron
	for ( int n = 0; n < output.size() - 1; n++ ) {
		output[ n ].getOutputGradient( targetVals[ n ] );
	}

	//Calculate hidden layer gradients
	//where i is the current layer
	for ( int i = m_vLayers.size() - 2; i > 0; i-- ) {
		//self commenting code, easier to understand than
		//using m_vLayers[whatever]
		Layer &hiddenLayer = m_vLayers[ i ];
		Layer &nextLayer   = m_vLayers[ i + 1 ];

		for ( int n = 0; n < hiddenLayer.size(); n++ ) {
			hiddenLayer[ n ].getHiddenGradient( nextLayer );
		}
	}

	//update weights
	//Going backwards through the layers starting at rightmost layer
	for ( int i = m_vLayers.size() - 1; i > 0; i-- ) {
		Layer &prevLayer    = m_vLayers[ i - 1 ];
		Layer &currentLayer = m_vLayers[ i ];

		for ( int n = 0; n < currentLayer.size() - 1; n++ ) {
			currentLayer[ n ].updateWeights( prevLayer );
		}
	}
}

void Skynet::getResults (vector < double > &resultVals) {
	resultVals.clear();
	for ( int n = 0; n < m_vLayers.back().size() - 1; n++ ) {
		resultVals.push_back( m_vLayers.back().at( n ).getOutput() );
	}
}

std::ofstream &operator << (std::ofstream &ofs, const Skynet &skynet) {
	// For all of our layers in SkyNet...
	for ( auto layer : skynet.m_vLayers ) {
		// Then for all of our nodes in each layer...
		for ( auto node : layer ) {
			// Save the weights of the node's connections to the next layer.
			ofs << node;
		}
		// Print an end line signifying the end of the layer.
		ofs << std::endl;
	}
	return ofs;
}

std::ifstream &operator >> (std::ifstream &ifs, Skynet &skynet) {
	for ( auto &layer : skynet.m_vLayers ) {
		for ( auto &node : layer ) {
			ifs >> node;
		}
	}
	return ifs;
}
