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

std::ostream &operator << (std::ostream &ofs, const Data &data);
std::ostream &operator << (std::ostream &ofs, const LandingSiteData &data);

class DataLoader {
private:
	std::string          filename;
	std::ifstream        dataFile;
	// Data to be given out
	std::vector < Data > data;
	// Data that this->data is to be resetted to.
	std::vector < Data > totalData;

	LandingSiteData parseDataLine (const std::string &line);

public:
	explicit DataLoader (const std::string &filename);

	void getDataFromFile ( );
	Data getData ( );
	bool givenAllData ( );

	void printData (std::ostream &ofs);

	friend std::ostream &operator << (std::ostream &ofs, const DataLoader &database);
};


#endif //SKYNET_DATALOADER_H

