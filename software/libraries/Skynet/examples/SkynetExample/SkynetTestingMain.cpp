#include "../../Skynet.h"
#include "../../DataLoader.h"

using namespace std;

typedef vector < Neuron > Layer;

double utility (double weight, double distance);
std::vector < double > utility (const Data &data);
std::vector < double > getTarget (const Data &data);

int main ( ) {
	double maxActivation     = 0;            //double to hold highest activation value of an output layer
	int    outputNeuronIndex = 0;            //index of highest activation neuron

	vector < unsigned int > topology;
	topology.push_back( 10 );
	topology.push_back( 7 );

	topology.push_back( 7 );
	topology.push_back( 10 );

	Skynet     testNet( topology );
	DataLoader database      = DataLoader( "generatedOutputs.txt" );
	database.getDataFromFile();

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

	std::vector < double > inputVals, targetVals, resultVals;

	int  totalEpochs = 10000;
	Data currData;

	for ( int epoch = 0; epoch < totalEpochs; epoch++ ) {

		if ( epoch % 1000 == 0 ) {
			std::cout << double( epoch ) / double( totalEpochs ) * 100 << "% finished" << std::endl;
		}

		while ( !database.givenAllData() ) {
			currData = database.getData();

			inputVals  = utility( currData );
			targetVals = getTarget( currData );

			testNet.feedForward( inputVals );
			testNet.backProp( targetVals );
			testNet.getResults( resultVals );

			inputVals.clear();
			targetVals.clear();


		}
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

std::vector < double > utility (const Data &data) {
	std::vector < double > out( 10 );
	LandingSiteData        landingSite;

	for ( int i = 0; i < data.landingSites.size(); i++ ) {
		landingSite = data.landingSites[ i ];
		out[ i ] = utility( landingSite.area, landingSite.distance );
	}

	return out;
}

std::vector < double > getTarget (const Data &data) {
	std::vector < double > out( 10, 0.0 );
	out[ data.bestLandingSite ] = 1.0;
	return out;
}
