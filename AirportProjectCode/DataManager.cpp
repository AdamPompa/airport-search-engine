#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include "DataManager.h"
#include "UserInterface.h"
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
		string field;
		Airport a;

		getline(ss, a.ident, ',');
		getline(ss, a.type, ',');
		getline(ss, a.name, ',');
		getline(ss, a.elevation, ',');
		getline(ss, a.continent, ',');		
		getline(ss, a.iso_country, ',');
		getline(ss, a.iso_region, ',');		
		getline(ss, a.municipality, ',');
		getline(ss, a.icao_code, ',');		
		getline(ss, a.iata_code, ',');
		getline(ss, a.gps_code, ',');	
		getline(ss, a.local_code, ',');
		getline(ss, a.coordinates, ',');

		airports.push_back(a);
	}
}

void DataManager::add_airport () {

	Airport new_airport;
	UserInterface::fill_new_airport(new_airport);
	DataManager::airports.push_back(new_airport);
	data_change = true;
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
				<< escape_csv(a.elevation) << ","
				<< escape_csv(a.continent) << ","
				<< escape_csv(a.iso_country) << ","
				<< escape_csv(a.iso_region) << ","
				<< escape_csv(a.municipality) << ","
				<< escape_csv(a.icao_code) << ","
				<< escape_csv(a.iata_code) << ","
				<< escape_csv(a.gps_code) << ","
				<< escape_csv(a.local_code) << ","
				<< escape_csv(a.coordinates) << "\n";
		}
		file.close();
	}
}


