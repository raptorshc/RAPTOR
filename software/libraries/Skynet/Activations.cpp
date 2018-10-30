//
// Created by trystanmay on 10/30/18.
//

#include "Activations.h"

double SkyNet::activation (const SkyNet::Activations &function, const double &value, const double &sum) {
	switch ( function ) {
		case ReLU:
			return relu( value );
		case Sigmoid:
			return sigmoid( value );
		case Softmax:
			return softmax( value, sum );
		default:
			return 0;
	}
}

double SkyNet::activation (const SkyNet::Activations &function, const double &value) {
	// Since softmax requires us to divide by the summation of our layer,
	// we'll try not to crash our program by making sure that we don't
	// divide by 0.
	return SkyNet::activation( function, value, 1.0 );
}

double SkyNet::activationDerivative (const SkyNet::Activations &function, const double &value, const double &sum) {
	switch ( function ) {
		case ReLU:
			return relu( value, true );
		case Sigmoid:
			return sigmoid( value, true );
		case Softmax:
			return softmax( value, sum, true );
		default:
			return 0;
	}
}

double SkyNet::activationDerivative (const SkyNet::Activations &function, const double &value) {
	// See the notes in activation(Activations, double)
	return SkyNet::activationDerivative( function, value, 1.0 );
}

