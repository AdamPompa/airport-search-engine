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

		getline(ss, column, ',');

		getline(ss, column, ',');
		a.type = column;

		getline(ss, column, ',');
		a.name = column;

		getline(ss, column, ',');
		a.elevation = stoi(column);

		getline(ss, column, ',');
		
		getline(ss, column, ',');
		a.iso_country = column;

		getline(ss, column, ',');
		
		getline(ss, column, ',');
		a.municipality = column;

		getline(ss, column, ',');
		
		getline(ss, column, ',');
		a.iata_code = column;

		getline(ss, column, ',');
	
		getline(ss, column, ',');
		
		getline(ss, column, ',');
		stringstream cs(column);
		string part;
		Coordinates c;

		getline (cs, part, ',');
		c.latitude = stod(part);

		getline(cs, part, ',');
		c.longitude = stod(part);

		a.airport_coordinates = c;
		airport_vector.push_back(a);
	}

}

int main() {
	DataManager::load_data();
	cout << airport_vector[0];
}

