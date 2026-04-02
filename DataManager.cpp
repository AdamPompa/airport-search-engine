#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DataManager.h"
using namespace std;

bool DataManager::data_change = false;

vector <Airport> airport_vector;

void DataManager::load_data() {
	ifstream original_file("airport-codes");
	string header;
	string row;

	getline(original_file, header);

	while (getline(original_file, row)) {
		stringstream ss(row);
		string column;
		Airport a;

		getline(ss, column, ',');
		a.ident = column;

		getline(ss, column, ',');
		a.type = column;

		getline(ss, column, ',');
		a.name = column;

		getline(ss, column, ',');
		a.elevation = stoi(column);

		getline(ss, column, ',');
		a.continent = column;
		
		getline(ss, column, ',');
		a.iso_country = column;

		getline(ss, column, ',');
		a.iso_region = column;
		
		getline(ss, column, ',');
		a.municipality = column;

		getline(ss, column, ',');
		a.icao_code = column;
		
		getline(ss, column, ',');
		a.iata_code = column;

		getline(ss, column, ',');
		a.gps_code = column;
	
		getline(ss, column, ',');
		a.local_code = column;
		
		getline(ss, column, ',');
		stringstream cs(column);
		string part;
		Coordinates c;

		getline (cs, part, ',');
		c.latitude = stod(part);

		getline(cs, part, ',');
		c.longitude = stod(part);

		c = a.airport_coordinates;

		airport_vector.push_back(a);
	}

}

void DataManager::add_airport (
	string ident, 
	string type, 
	string name, 
	int elevation, 
	string continent, 
	string iso_country, 
	string iso_region, 
	string municipality, 
	string icao_code, 
	string iata_code, 
	string gps_code, 
	string local_code, 
	double latitude,
	double longitude) {

	Airport new_airport;

	new_airport.ident = ident;
	new_airport.type = type;
	new_airport.name = name;
	new_airport.elevation = elevation;
	new_airport.continent = continent;
	new_airport.iso_country = iso_country;
	new_airport.iso_region = iso_region;
	new_airport.municipality = municipality;
	new_airport.icao_code = icao_code;
	new_airport.iata_code = iata_code;
	new_airport.gps_code = gps_code;
	new_airport.local_code = local_code;
	new_airport.airport_coordinates.latitude = latitude;
	new_airport.airport_coordinates.longitude = longitude;

	airport_vector.push_back(new_airport);
	data_change = true;
}

string DataManager::coord_to_string(Coordinates& c) {
	return to_string(c.latitude) + "," + to_string(c.longitude);
}

string DataManager::escape_csv() {

}

void DataManager::save_data() {
	if (data_change == true) {

	}

}


