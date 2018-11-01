//
// Created by trystanmay on 10/30/18.
//

#include <cassert>
#include <iostream>
#include "DataLoader.h"

DataLoader::DataLoader (const std::string &filename) {
	this->filename = filename;
}

LandingSiteData DataLoader::parseDataLine (const std::string &line) {
	const char      delimiter = ':';
	LandingSiteData out;

	// Find the first colon
	auto        firstColon = line.find( delimiter );
	// Get the data that we haven't processed yet.
	std::string restOfData = line.substr( firstColon + 1, std::string::npos );
	// Parse the landing site from the line.
	out.landingSite = std::stoi( line.substr( 0, firstColon + 1 ) );

	// Find the next colon.
	auto secondColon = restOfData.find( delimiter );

	// Parse the area from that data.
	out.area = std::stod( restOfData.substr( 0, secondColon ) );
	// Get the remaining data that we need.
	restOfData = restOfData.substr( secondColon + 1, std::string::npos );

	// We have all the data that we need to parse distance.
	out.distance = std::stod( restOfData );

	return out;
}

void DataLoader::getDataFromFile ( ) {
	// TODO: Fix this function so that it actually works.
	// Cuz that's important!
	this->dataFile.open( this->filename );
	assert( this->dataFile.good() );

	// Reset all of our data.
	this->totalData.clear();
	this->data.clear();

	char                            c;
	double                          area, distance;
	int                             landingSiteIndex, bestSpotIndex;
	std::string                     s;
	std::vector < LandingSiteData > landingSites;
	Data                            currData;
	std::string                     line;
	// Get the next line in the data file.
	while ( std::getline( this->dataFile, line ) ) {
		// If we don't have a lot of data...
		if ( line.size() <= 1 ) {
			// Skip this line.
			continue;
		}

		c = line.at( 0 );
		// If our current character is the beginning of
		// our landing site data...
		if ( isdigit( c ) ) {
			// Parse the line and add it to landingSites.
			landingSites.push_back( this->parseDataLine( line ) );
		} else if ( c == '>' ) {
			// If our current character is the beginning of our
			// declaration of what the best landing site would be...

			// Get the index of the best landing spot.
			bestSpotIndex = std::stoi( line.substr( 1, std::string::npos ) );
			// Save all of the information for our current data.
			currData      = {landingSites, bestSpotIndex};
			// Save our current data to our big database.
			this->totalData.push_back( currData );

			// Clear the landing sites that we have already saved.
			landingSites.clear();
		}
	}
	this->data = this->totalData;
}


// Get a random data that we haven't already given out.
// If we've given out all of our data, then reset
// this->data to this->totalData
Data DataLoader::getData ( ) {
	// If we have run out of data to give out...
	if ( this->givenAllData() ) {
		// reset data to our total data.
		this->data = this->totalData;
	}
	// Get a random index.
	int  index  = rand() % this->data.size();
	// Get the data at that random index.
	Data output = this->data[ index ];
	// Remove the data that we have just received.
	this->data.erase( this->data.begin() + index );

	// Return our data to give out.
	return output;
}

bool DataLoader::givenAllData ( ) {
	return this->data.size() == 0;
}

std::ostream &operator << (std::ostream &ofs, const DataLoader &database) {
	for ( auto d : database.totalData ) {
		ofs << d << std::endl;
	}
	return ofs;
}

std::ostream &operator << (std::ostream &ofs, const Data &data) {
	for ( auto d : data.landingSites ) {
		ofs << d << std::endl;
	}
	ofs << "Best Landing Site: " << data.bestLandingSite << std::endl;
	return ofs;
}

std::ostream &operator << (std::ostream &ofs, const LandingSiteData &data) {
	ofs << data.landingSite << ": <" << data.area << "> (" << data.distance << ")";
	return ofs;
}

void DataLoader::printData (std::ostream &ofs) {
	for ( auto d : this->totalData ) {
		ofs << d;
	}
}
