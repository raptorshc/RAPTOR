//
// Created by trystanmay on 10/30/18.
//

#ifndef SKYNET_DATALOADER_H
#define SKYNET_DATALOADER_H

#include <fstream>
#include <vector>
#include <string>

struct LandingSiteData {
	int    landingSite;
	double area;
	double distance;
};

struct Data {
	std::vector < LandingSiteData > landingSites;
	int                             bestLandingSite;
};

class DataLoader {
private:
	std::string          filename;
	std::ifstream        dataFile;
	// Data to be given out
	std::vector < Data > data;
	// Data that this->data is to be resetted to.
	std::vector < Data > totalData;


public:
	DataLoader (const std::string &filename);

	void getDataFromFile ( );
	Data getData ( );
	bool givenAllData ( );

};


#endif //SKYNET_DATALOADER_H

