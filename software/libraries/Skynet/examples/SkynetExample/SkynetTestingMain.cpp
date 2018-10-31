#include "../../Skynet.h"

using namespace std;

typedef vector < Neuron > Layer;

double utility (double weight, double distance);


int main ( ) {
	double maxActivation     = 0;            //double to hold highest activation value of an output layer
	int    outputNeuronIndex = 0;            //index of highest activation neuron

	vector < unsigned int > topology;
	topology.push_back( 10 );
	topology.push_back( 5 );

	topology.push_back( 5 );
	topology.push_back( 10 );

	Skynet            testNet( topology );
	vector < double > inputVals;
	vector < double > targetVals;
	vector < double > resultVals;

	std::cout << "Loading network from file." << std::endl;
	/*
	 * If you are getting -nan's as results and as your saved weights,
	 * create network.dat as an empty text file and then rerun the program.
	 */
	std::ifstream inFile( "network.dat" );
	if ( inFile.good() ) {
		std::cout << "The old file exists." << std::endl;
		inFile >> testNet;
	}
	inFile.close();

	int totalEpochs = 10000;

	for ( int k = 0; k < totalEpochs; k++ ) {

		if ( k % 1000 == 0 ) {
			cout << ( double ) k / ( double ) totalEpochs * 100 << "% finished" << endl;
		}

		//Set 1
		inputVals.push_back( utility( 0.725, 6.562 ) );        //1
		inputVals.push_back( utility( 0.422, 5.736 ) );        //2
		inputVals.push_back( utility( 0.924, 4.215 ) );        //3
		inputVals.push_back( utility( 0.680, 4.822 ) );        //4
		inputVals.push_back( utility( 0.370, 2.609 ) );        //5
		inputVals.push_back( utility( 0.441, 2.498 ) );        //6
		inputVals.push_back( utility( 0.831, 2.865 ) );        //7
		inputVals.push_back( utility( 0.681, 2.945 ) );        //8
		inputVals.push_back( utility( 0.351, 1.406 ) );        //9
		inputVals.push_back( utility( 0.961, 2.591 ) );        //10

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 1 );                        //10

		//train 1
		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		//set 2
		inputVals.push_back( utility( 0.150, 1.782 ) );        //1
		inputVals.push_back( utility( 0.890, 1.625 ) );        //2
		inputVals.push_back( utility( 0.908, 4.515 ) );        //3
		inputVals.push_back( utility( 0.915, 1.330 ) );        //4
		inputVals.push_back( utility( 0.086, 5.679 ) );        //5
		inputVals.push_back( utility( 0.207, 2.697 ) );        //6
		inputVals.push_back( utility( 0.680, 1.765 ) );        //7
		inputVals.push_back( utility( 0.754, 2.076 ) );        //8
		inputVals.push_back( utility( 0.434, 4.207 ) );        //9
		inputVals.push_back( utility( 0.896, 2.344 ) );        //10

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 1 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		//train 2
		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();

		//set 3
		inputVals.push_back( utility( 0.858, 3.658 ) );        //1
		inputVals.push_back( utility( 0.479, 4.032 ) );        //2
		inputVals.push_back( utility( 0.783, 4.266 ) );        //3
		inputVals.push_back( utility( 0.947, 2.378 ) );        //4
		inputVals.push_back( utility( 0.377, 5.842 ) );        //5
		inputVals.push_back( utility( 0.367, 2.586 ) );        //6
		inputVals.push_back( utility( 0.042, 3.837 ) );        //7
		inputVals.push_back( utility( 0.664, 2.970 ) );        //8
		inputVals.push_back( utility( 0.571, 6.642 ) );        //9
		inputVals.push_back( utility( 0.074, 5.124 ) );        //10

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 1 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		//train 3
		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();

		//set 4
		inputVals.push_back( utility( 0.601, 1.714 ) );        //1
		inputVals.push_back( utility( 0.094, 2.318 ) );        //2
		inputVals.push_back( utility( 0.897, 4.013 ) );        //3
		inputVals.push_back( utility( 0.392, 1.575 ) );        //4
		inputVals.push_back( utility( 0.138, 3.498 ) );        //5
		inputVals.push_back( utility( 0.968, 2.995 ) );        //6
		inputVals.push_back( utility( 0.206, 4.337 ) );        //7
		inputVals.push_back( utility( 0.337, 2.326 ) );        //8
		inputVals.push_back( utility( 0.619, 3.378 ) );        //9
		inputVals.push_back( utility( 0.052, 2.620 ) );        //10

		targetVals.push_back( 1 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.016, 3.270 ) );
		inputVals.push_back( utility( 0.060, 2.018 ) );
		inputVals.push_back( utility( 0.854, 2.228 ) );
		inputVals.push_back( utility( 0.106, 4.216 ) );
		inputVals.push_back( utility( 0.341, 5.999 ) );
		inputVals.push_back( utility( 0.766, 5.050 ) );
		inputVals.push_back( utility( 0.737, 2.281 ) );
		inputVals.push_back( utility( 0.374, 1.402 ) );
		inputVals.push_back( utility( 0.585, 6.398 ) );
		inputVals.push_back( utility( 0.852, 3.308 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 1 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.500, 2.505 ) );
		inputVals.push_back( utility( 0.943, 4.445 ) );
		inputVals.push_back( utility( 0.144, 0.952 ) );
		inputVals.push_back( utility( 0.761, 3.548 ) );
		inputVals.push_back( utility( 0.708, 0.843 ) );
		inputVals.push_back( utility( 0.491, 3.419 ) );
		inputVals.push_back( utility( 0.530, 3.970 ) );
		inputVals.push_back( utility( 0.443, 2.174 ) );
		inputVals.push_back( utility( 0.948, 4.649 ) );
		inputVals.push_back( utility( 0.651, 3.037 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 1 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.697, 3.024 ) );
		inputVals.push_back( utility( 0.675, 5.135 ) );
		inputVals.push_back( utility( 0.958, 2.371 ) );
		inputVals.push_back( utility( 0.011, 2.227 ) );
		inputVals.push_back( utility( 0.791, 7.133 ) );
		inputVals.push_back( utility( 0.242, 3.717 ) );
		inputVals.push_back( utility( 0.211, 0.643 ) );
		inputVals.push_back( utility( 0.702, 2.264 ) );
		inputVals.push_back( utility( 0.744, 6.787 ) );
		inputVals.push_back( utility( 0.430, 4.999 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 1 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.453, 3.535 ) );
		inputVals.push_back( utility( 0.700, 6.053 ) );
		inputVals.push_back( utility( 0.239, 1.521 ) );
		inputVals.push_back( utility( 0.997, 3.256 ) );
		inputVals.push_back( utility( 0.698, 2.034 ) );
		inputVals.push_back( utility( 0.525, 2.391 ) );
		inputVals.push_back( utility( 0.177, 3.568 ) );
		inputVals.push_back( utility( 0.680, 1.230 ) );
		inputVals.push_back( utility( 0.846, 3.446 ) );
		inputVals.push_back( utility( 0.314, 6.673 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 1 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.778, 5.950 ) );
		inputVals.push_back( utility( 0.512, 1.691 ) );
		inputVals.push_back( utility( 0.952, 3.867 ) );
		inputVals.push_back( utility( 0.030, 4.828 ) );
		inputVals.push_back( utility( 0.308, 3.480 ) );
		inputVals.push_back( utility( 0.106, 4.213 ) );
		inputVals.push_back( utility( 0.592, 1.598 ) );
		inputVals.push_back( utility( 0.685, 3.012 ) );
		inputVals.push_back( utility( 0.718, 5.961 ) );
		inputVals.push_back( utility( 0.066, 1.633 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 1 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.203, 2.729 ) );
		inputVals.push_back( utility( 0.742, 4.197 ) );
		inputVals.push_back( utility( 0.652, 5.369 ) );
		inputVals.push_back( utility( 0.763, 0.970 ) );
		inputVals.push_back( utility( 0.301, 3.050 ) );
		inputVals.push_back( utility( 0.829, 3.341 ) );
		inputVals.push_back( utility( 0.687, 4.626 ) );
		inputVals.push_back( utility( 0.115, 2.121 ) );
		inputVals.push_back( utility( 0.856, 4.282 ) );
		inputVals.push_back( utility( 0.719, 2.235 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 1 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.470, 3.500 ) );
		inputVals.push_back( utility( 0.615, 5.262 ) );
		inputVals.push_back( utility( 0.138, 4.654 ) );
		inputVals.push_back( utility( 0.942, 3.408 ) );
		inputVals.push_back( utility( 0.974, 2.654 ) );
		inputVals.push_back( utility( 0.306, 2.107 ) );
		inputVals.push_back( utility( 0.450, 6.202 ) );
		inputVals.push_back( utility( 0.292, 6.816 ) );
		inputVals.push_back( utility( 0.869, 5.753 ) );
		inputVals.push_back( utility( 0.719, 2.516 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 1 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.142, 2.948 ) );
		inputVals.push_back( utility( 0.465, 5.420 ) );
		inputVals.push_back( utility( 0.488, 3.706 ) );
		inputVals.push_back( utility( 0.480, 5.347 ) );
		inputVals.push_back( utility( 0.249, 6.429 ) );
		inputVals.push_back( utility( 0.519, 5.510 ) );
		inputVals.push_back( utility( 0.569, 4.036 ) );
		inputVals.push_back( utility( 0.300, 4.468 ) );
		inputVals.push_back( utility( 0.065, 2.044 ) );
		inputVals.push_back( utility( 0.487, 1.776 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 1 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.664, 6.994 ) );
		inputVals.push_back( utility( 0.675, 3.127 ) );
		inputVals.push_back( utility( 0.403, 6.746 ) );
		inputVals.push_back( utility( 0.671, 1.262 ) );
		inputVals.push_back( utility( 0.005, 1.201 ) );
		inputVals.push_back( utility( 0.080, 3.495 ) );
		inputVals.push_back( utility( 0.333, 1.049 ) );
		inputVals.push_back( utility( 0.873, 6.854 ) );
		inputVals.push_back( utility( 0.160, 6.934 ) );
		inputVals.push_back( utility( 0.429, 4.051 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 1 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.489, 2.087 ) );
		inputVals.push_back( utility( 0.632, 2.971 ) );
		inputVals.push_back( utility( 0.740, 3.699 ) );
		inputVals.push_back( utility( 0.166, 2.275 ) );
		inputVals.push_back( utility( 0.181, 3.391 ) );
		inputVals.push_back( utility( 0.732, 3.305 ) );
		inputVals.push_back( utility( 0.179, 1.223 ) );
		inputVals.push_back( utility( 0.719, 4.463 ) );
		inputVals.push_back( utility( 0.834, 4.221 ) );
		inputVals.push_back( utility( 0.711, 6.467 ) );

		targetVals.push_back( 1 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.380, 3.775 ) );
		inputVals.push_back( utility( 0.465, 3.123 ) );
		inputVals.push_back( utility( 0.080, 0.709 ) );
		inputVals.push_back( utility( 0.851, 4.465 ) );
		inputVals.push_back( utility( 0.791, 3.608 ) );
		inputVals.push_back( utility( 0.483, 3.090 ) );
		inputVals.push_back( utility( 0.709, 1.445 ) );
		inputVals.push_back( utility( 0.623, 6.850 ) );
		inputVals.push_back( utility( 0.503, 1.329 ) );
		inputVals.push_back( utility( 0.797, 3.081 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 1 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.171, 5.446 ) );
		inputVals.push_back( utility( 0.625, 3.106 ) );
		inputVals.push_back( utility( 0.951, 2.799 ) );
		inputVals.push_back( utility( 0.277, 4.656 ) );
		inputVals.push_back( utility( 0.150, 6.899 ) );
		inputVals.push_back( utility( 0.817, 3.135 ) );
		inputVals.push_back( utility( 0.914, 3.382 ) );
		inputVals.push_back( utility( 0.586, 5.247 ) );
		inputVals.push_back( utility( 0.568, 6.371 ) );
		inputVals.push_back( utility( 0.161, 3.225 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 1 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.221, 1.647 ) );
		inputVals.push_back( utility( 0.983, 3.790 ) );
		inputVals.push_back( utility( 0.586, 6.236 ) );
		inputVals.push_back( utility( 0.243, 5.433 ) );
		inputVals.push_back( utility( 0.833, 4.957 ) );
		inputVals.push_back( utility( 0.872, 3.415 ) );
		inputVals.push_back( utility( 0.731, 6.624 ) );
		inputVals.push_back( utility( 0.755, 6.107 ) );
		inputVals.push_back( utility( 0.443, 3.565 ) );
		inputVals.push_back( utility( 0.142, 4.184 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 1 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.944, 2.930 ) );
		inputVals.push_back( utility( 0.221, 5.289 ) );
		inputVals.push_back( utility( 0.979, 3.671 ) );
		inputVals.push_back( utility( 0.004, 3.621 ) );
		inputVals.push_back( utility( 0.265, 6.572 ) );
		inputVals.push_back( utility( 0.954, 4.911 ) );
		inputVals.push_back( utility( 0.646, 5.598 ) );
		inputVals.push_back( utility( 0.673, 1.087 ) );
		inputVals.push_back( utility( 0.380, 5.248 ) );
		inputVals.push_back( utility( 0.625, 6.335 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 1 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.335, 2.971 ) );
		inputVals.push_back( utility( 0.464, 4.721 ) );
		inputVals.push_back( utility( 0.845, 2.840 ) );
		inputVals.push_back( utility( 0.831, 6.275 ) );
		inputVals.push_back( utility( 0.597, 4.313 ) );
		inputVals.push_back( utility( 0.818, 3.763 ) );
		inputVals.push_back( utility( 0.933, 2.299 ) );
		inputVals.push_back( utility( 0.716, 1.592 ) );
		inputVals.push_back( utility( 0.060, 1.882 ) );
		inputVals.push_back( utility( 0.953, 2.197 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 1 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.911, 1.031 ) );
		inputVals.push_back( utility( 0.005, 4.067 ) );
		inputVals.push_back( utility( 0.894, 5.072 ) );
		inputVals.push_back( utility( 0.678, 5.201 ) );
		inputVals.push_back( utility( 0.697, 4.310 ) );
		inputVals.push_back( utility( 0.730, 5.279 ) );
		inputVals.push_back( utility( 0.062, 4.785 ) );
		inputVals.push_back( utility( 0.525, 2.218 ) );
		inputVals.push_back( utility( 0.694, 3.132 ) );
		inputVals.push_back( utility( 0.218, 4.237 ) );

		targetVals.push_back( 1 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.114, 2.201 ) );
		inputVals.push_back( utility( 0.910, 3.284 ) );
		inputVals.push_back( utility( 0.681, 5.657 ) );
		inputVals.push_back( utility( 0.139, 2.015 ) );
		inputVals.push_back( utility( 0.423, 2.466 ) );
		inputVals.push_back( utility( 0.613, 5.623 ) );
		inputVals.push_back( utility( 0.310, 0.913 ) );
		inputVals.push_back( utility( 0.928, 3.278 ) );
		inputVals.push_back( utility( 0.011, 1.595 ) );
		inputVals.push_back( utility( 0.547, 3.003 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 1 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.022, 3.215 ) );
		inputVals.push_back( utility( 0.667, 2.589 ) );
		inputVals.push_back( utility( 0.796, 0.360 ) );
		inputVals.push_back( utility( 0.012, 2.556 ) );
		inputVals.push_back( utility( 0.011, 4.826 ) );
		inputVals.push_back( utility( 0.672, 4.736 ) );
		inputVals.push_back( utility( 0.636, 4.501 ) );
		inputVals.push_back( utility( 0.759, 6.136 ) );
		inputVals.push_back( utility( 0.661, 2.788 ) );
		inputVals.push_back( utility( 0.491, 5.568 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 1 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.466, 3.206 ) );
		inputVals.push_back( utility( 0.014, 3.558 ) );
		inputVals.push_back( utility( 0.801, 2.390 ) );
		inputVals.push_back( utility( 0.067, 3.614 ) );
		inputVals.push_back( utility( 0.414, 2.982 ) );
		inputVals.push_back( utility( 0.593, 3.049 ) );
		inputVals.push_back( utility( 0.722, 3.310 ) );
		inputVals.push_back( utility( 0.149, 5.561 ) );
		inputVals.push_back( utility( 0.301, 1.780 ) );
		inputVals.push_back( utility( 0.350, 2.531 ) );

		targetVals.push_back( 0 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 1 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


		inputVals.push_back( utility( 0.639, 0.909 ) );
		inputVals.push_back( utility( 0.596, 3.716 ) );
		inputVals.push_back( utility( 0.440, 6.398 ) );
		inputVals.push_back( utility( 0.032, 4.482 ) );
		inputVals.push_back( utility( 0.976, 3.659 ) );
		inputVals.push_back( utility( 0.540, 6.471 ) );
		inputVals.push_back( utility( 0.202, 4.433 ) );
		inputVals.push_back( utility( 0.406, 2.091 ) );
		inputVals.push_back( utility( 0.933, 5.966 ) );
		inputVals.push_back( utility( 0.198, 0.926 ) );

		targetVals.push_back( 1 );                        //1
		targetVals.push_back( 0 );                        //2
		targetVals.push_back( 0 );                        //3
		targetVals.push_back( 0 );                        //4
		targetVals.push_back( 0 );                        //5
		targetVals.push_back( 0 );                        //6
		targetVals.push_back( 0 );                        //7
		targetVals.push_back( 0 );                        //8
		targetVals.push_back( 0 );                        //9
		targetVals.push_back( 0 );                        //10

		testNet.feedForward( inputVals );
		testNet.backProp( targetVals );
		testNet.getResults( resultVals );

		inputVals.clear();
		targetVals.clear();


	}

	//test set 1
	inputVals.push_back( utility( 0.548, 2.214 ) );        //1
	inputVals.push_back( utility( 0.520, 4.011 ) );        //2
	inputVals.push_back( utility( 0.861, 0.529 ) );        //3
	inputVals.push_back( utility( 0.514, 3.128 ) );        //4
	inputVals.push_back( utility( 0.344, 1.737 ) );        //5
	inputVals.push_back( utility( 0.328, 6.283 ) );        //6
	inputVals.push_back( utility( 0.499, 0.716 ) );        //7
	inputVals.push_back( utility( 0.309, 4.302 ) );        //8
	inputVals.push_back( utility( 0.473, 2.978 ) );        //9
	inputVals.push_back( utility( 0.377, 3.250 ) );        //10

	/*targetVals.push_back(0);						//1
	targetVals.push_back(0);						//2
	targetVals.push_back(1);						//3
	targetVals.push_back(0);						//4
	targetVals.push_back(0);						//5
	targetVals.push_back(0);						//6
	targetVals.push_back(0);						//7
	targetVals.push_back(0);						//8
	targetVals.push_back(0);						//9
	targetVals.push_back(0);						//10*/

	//test 1
	testNet.feedForward( inputVals );
	//testNet.backProp(targetVals);
	testNet.getResults( resultVals );


	for ( int i = 0; i < resultVals.size(); i++ ) {
		if ( resultVals[ i ] > maxActivation ) {
			outputNeuronIndex = i;
			maxActivation     = resultVals[ i ];
		}
		cout << resultVals[ i ] << endl;
	}

	cout << endl;
	cout << "Desired landing site: " << outputNeuronIndex << " with activation value of " << maxActivation << endl;
	//desired output is 2, 3rd landing site counted from 0
	cout << "Actual landing site: 2" << endl;

	std::cout << "Saving network to file." << std::endl;
	std::ofstream outFile( "network.dat" );
	outFile << testNet;
	outFile.close();
}

double utility (double weight, double distance) {
	return (weight * 0.25) / distance;
}