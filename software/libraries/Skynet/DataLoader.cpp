//
// Created by trystanmay on 10/30/18.
//

#include <cassert>
#include <iostream>
#include "DataLoader.h"

DataLoader::DataLoader (const std::string &filename) {
	this->filename = filename;
}

void DataLoader::getDataFromFile ( ) {
	this->dataFile.open( this->filename );
	assert( this->dataFile.good() );

	// Reset all of our data.
	this->totalData.clear();
	this->data.clear();

	// The beginning words for when the best spot is about
	// to be announced in the file.
	const std::string bestSpotBeginning = "Expected";

	char                            c;
	double                          area, distance;
	int                             landingSiteIndex, bestSpotIndex;
	std::string                     s;
	std::vector < LandingSiteData > landingSites;
	Data                            currData;
	double                          temp;
	while ( this->dataFile.good() ) {
		// Get the next character without taking it away from
		// the input buffer.
		c = this->dataFile.peek();
		// If it's a letter...
		if ( isalpha( c ) ) {
			// Get a full string.
			// This shouldn't hurt us as the only thing that has a letter is
			// when the file tells us it's about to announce the best landing site.
			this->dataFile >> s;
			// If it is telling us the best landing site...
			if ( s == bestSpotBeginning ) {
				// An ideal solution would be to going until
				// there is a number in the string, since
				// that means the string is now our best
				// landing site.
				// But oh well. We'll hard code it for now.

				// Get the junk text (output: )
				this->dataFile >> s;
				// Get the best landing site.
				this->dataFile >> bestSpotIndex;
				// Setup current data
				currData = {landingSites, bestSpotIndex};
				// Add the current data to our database.
				this->data.push_back( currData );
				// Clear our landing sites.
				landingSites.clear();
			}
		} else if ( isdigit( c ) ) {
			// If we have a number, it's probably the
			// current landing site's data
			// (meaning which landing site it is, its area, and distance)

			// Get the actual number.
			this->dataFile >> temp;
			// Get the character after the number.
			c = this->dataFile.peek();
			// If it's something like xx:
			// where x is a number
			if ( c == ':' ) {
				// We are at the landing site index.
				landingSiteIndex = static_cast<int>(temp);
			} else if ( c == '>' ) {
				// If it's something like xxx>,
				// then we are at our area.
				area = temp;
			} else if ( c == ')' ) {
				// If it's something like xxx),
				// we're getting our distance.
				distance = temp;
				// Since distance is the last metric of the line,
				// we'll just save everything we have right now to our
				// current list of landing sites.
				landingSites.push_back( {landingSiteIndex, area, distance} );
			}
		} else {
			// If none of these are true...
			// Just keep on going along.
			this->dataFile >> c;
		}
	}
	this->totalData = this->data;
}


// Get a random data that we haven't already given out.
// If we've given out all of our data, then reset
// this->data to this->totalData
Data DataLoader::getData ( ) {
	// If we have run out of data to give out...
	if ( this->data.size() == 0 ) {
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
