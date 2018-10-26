#include "Skynet.h"
#include "Neuron.h"
#include <vector>

using namespace std;

typedef vector<Neuron> Layer;


int main()
{
	vector<unsigned int> topology;
	topology.push_back(2);
	topology.push_back(4);
	topology.push_back(1);

	Skynet testNet(topology);

	vector<double>inputVals;
	inputVals.push_back(1);
	inputVals.push_back(0);
	vector<double>targetVals;
	/*targetVals.push_back(0);
	targetVals.push_back(0);*/
	targetVals.push_back(1);
	//targetVals.push_back(0);

	vector<double>resultVals;

	for (int i = 0; i < 1000; i++)
	{
		testNet.feedForward(inputVals);
		testNet.backProp(targetVals);
		testNet.getResults(resultVals);
		for (int j = 0; j < resultVals.size(); j++)
		{
			cout << resultVals.at(j);
			cout << endl;
		}
	}

	//inputVals.at(0) = 0;
	//inputVals.at(1) = 0;
	//targetVals.at(0) = 0;
	//testNet.feedForward(inputVals);
	////testNet.backProp(targetVals);
	//testNet.getResults(resultVals);
	//for (int j = 0; j < resultVals.size(); j++)
	//{
	//	cout << resultVals.at(j);
	//	cout << endl;
	//}

	//inputVals.at(0) = 1;
	//inputVals.at(1) = 1;
	//targetVals.at(0) = 0;
	//testNet.feedForward(inputVals);
	////testNet.backProp(targetVals);
	//testNet.getResults(resultVals);
	//for (int j = 0; j < resultVals.size(); j++)
	//{
	//	cout << resultVals.at(j);
	//	cout << endl;
	//}

	//inputVals.at(0) = 0;
	//inputVals.at(1) = 1;
	//targetVals.at(0) = 1;
	//testNet.feedForward(inputVals);
	////testNet.backProp(targetVals);
	//testNet.getResults(resultVals);
	//for (int j = 0; j < resultVals.size(); j++)
	//{
	//	cout << resultVals.at(j);
	//	cout << endl;
	//}


	/*for (int i = 0; i < 100; i++)
	{
		testNet.feedForward(inputVals);
		testNet.backProp(targetVals);
		testNet.getResults(resultVals);
		for (int j = 0; j < resultVals.size(); j++)
		{
			cout << resultVals.at(j);
			cout << endl;
		}
		cout << endl;
	}

	inputVals.at(1) = 1;
	inputVals.at(0) = 1;
	targetVals.at(0) = 0;

	for (int i = 0; i < 100; i++)
	{
		testNet.feedForward(inputVals);
		testNet.backProp(targetVals);
		testNet.getResults(resultVals);
		for (int j = 0; j < resultVals.size(); j++)
		{
			cout << resultVals.at(j);
			cout << endl;
		}
		cout << endl;
	}

	inputVals.at(0) = 0;
	inputVals.at(1) = 1;
	targetVals.at(0) = 1;

	for (int i = 0; i < 100; i++)
	{
		testNet.feedForward(inputVals);
		testNet.backProp(targetVals);
		testNet.getResults(resultVals);
		for (int j = 0; j < resultVals.size(); j++)
		{
			cout << resultVals.at(j);
			cout << endl;
		}
		cout << endl;
	}*/

}