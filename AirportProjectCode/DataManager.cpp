#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "DataManager.h"
using namespace std;

bool DataManager::data_change = false;

vector <Airport> DataManager::airports;

void DataManager::load_data(const string& csv) {
	ifstream original_file(csv);
	if (!original_file.is_open()) {
		cout << "Failed to open file" << endl;
		return;
	}
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

		c = a.coordinates;

		airports.push_back(a);
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
	new_airport.coordinates.latitude = latitude;
	new_airport.coordinates.longitude = longitude;

	airports.push_back(new_airport);
	data_change = true;
}

string DataManager::coord_to_string(const Coordinates& c) {
	return to_string(c.latitude) + "," + to_string(c.longitude);
}

string DataManager::escape_csv(const string& element) {
	bool escape = false;
	string result;

	for (char c : element) {
		if (c == '"') {
			result += "\"\"";
			escape = true;
		}
		else if (c == ',' || c == '\n' || c == '\r') {
			result += c;
			escape = true;
		}
		else {
			result += c;
		}
	}

	if (escape == true) {
		return ("\"" + result + "\"");
	}
	else {
		return result;
	}
}

void DataManager::save_data(const vector <Airport>& airports) {
	
	if (data_change == true) {
		ofstream file("airport-codes");

		if (!file) {
			throw runtime_error("failed to open file");
		}

		file << "ident, type, name, elevation_ft, continent, iso_country, iso_region, municipality, icao_code, iata_code, gps_code, local_code, coordinates\n";

		for (const auto& a : airports) {
			file << escape_csv(a.ident) << ","
				 << escape_csv(a.type) << ","
				<< escape_csv(a.name) << ","
				<< escape_csv(to_string(a.elevation)) << ","
				<< escape_csv(a.continent) << ","
				<< escape_csv(a.iso_country) << ","
				<< escape_csv(a.iso_region) << ","
				<< escape_csv(a.municipality) << ","
				<< escape_csv(a.icao_code) << ","
				<< escape_csv(a.iata_code) << ","
				<< escape_csv(a.gps_code) << ","
				<< escape_csv(a.local_code) << ","
				<< escape_csv(coord_to_string(a.coordinates)) << "\n";
		}
		file.close();
	}
}


