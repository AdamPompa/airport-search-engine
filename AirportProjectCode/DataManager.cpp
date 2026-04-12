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

unordered_map<string, int> DataManager::iata_map;
multimap<string, int> DataManager::country_map;

vector<string> DataManager::parse_csv(const string& row) {
	vector<string> results;
	string field;
	bool in_quotes = false;

	for (int i = 0; i < row.length(); i++) {
		char c = row[i];

		if (c == '"') {
			if (in_quotes && i + 1 < row.length() && row[i + 1] == '"') {
				field += '"';
				i++;
			}
			else {
				in_quotes = !in_quotes;
			}
		}
		else if (c == ',' && in_quotes == false) {
			results.push_back(field);
			field.clear();
		}
		else {
			field += c;
		}
	}
	results.push_back(field);
	return results;
}

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
		vector<string> field = parse_csv(row);
		Airport a;

		a.ident = field[0];
		a.type = field[1];
		a.name = field[2];
		a.elevation = field[3];
		a.continent = field[4];
		a.iso_country = field[5];
		a.iso_region = field[6];
		a.municipality = field[7];
		a.icao_code = field[8];
		a.iata_code = field[9];
		a.gps_code = field[10];
		a.local_code = field[11];
		a.coordinates = field[12];

		airports.push_back(a);
	}
}

void DataManager::add_airport () {

	Airport new_airport;
	UserInterface::fill_new_airport(new_airport);
	DataManager::airports.push_back(new_airport);
	data_change = true;
	make_maps(DataManager::airports);
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
		ofstream file("airport-test-codes.txt");

		if (!file) {
			throw runtime_error("failed to open file");
		}

		file << "ident,type,name,elevation_ft,continent,iso_country,iso_region,municipality,icao_code,iata_code,gps_code,local_code,coordinates\n";
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

void DataManager::make_maps(const std::vector<Airport>& airports) {
	for (int i = 0; i < airports.size(); i++) {
		iata_map [airports[i].iata_code] = i;
		country_map.insert({airports[i].iso_country, i});
	}
}


