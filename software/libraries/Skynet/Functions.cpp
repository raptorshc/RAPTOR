//
// Created by trystanmay on 10/30/18.
//

#include <cmath>
#include "Functions.h"
#include "Neuron.h"

double sum (const Layer &layer) {
	double     out = 0;
	for ( auto node : layer ) {
		out += node.getOutput();
	}
	return out;
}

// Leaky Relu activation function.
// With our negative slope defined to be 0.5
double leaky_relu (const double &input, const bool &derivative) {
	// If our input is not positive...
	if ( input <= 0 ) {

		return (derivative) ? 0.5 : input * 0.5;
	}
	// If we want the derivative for our positive input...
	// output 1 for the derivative
	// or just the input if we don't want the derivative.
	return (derivative) ? 1 : input;
}

// Wrapper function around the other relu function.
// Use this one if you don't want the derivative.
double leaky_relu (const double &input) {
	return leaky_relu( input, false );
}

// Sigmoid activation function.
double sigmoid (const double &input, const bool &derivative) {
	// If we want to take the derivative...
	if ( derivative ) {
		// Do it.
		return input * (1 - input);
	}
	// Otherwise just do the actual output.
	return input / (1 + abs( input ));
}

// Wrapper function around the other sigmoid function.
// This is to make it easier to just get the actual value
// from the function rather than its derivative.
double sigmoid (const double &input) {
	return sigmoid( input, false );
}

double softmax (const double &input, const double &sum, const bool &derivative) {
	return 0;
}

double softmax (const double &input, const double &sum) {
	return softmax( input, sum, false );
}

