#pragma once
#include <iostream>
using namespace std;


struct Coordinates {
	double latitude;
	double longitude;
};

struct Airport {
	string type;
	string name;
	int elevation;
	string iso_country;
	string municipality;
	string iata_code;
	Coordinates airport_coordinates;
};

class DataManager {

	public:
		DataManager();
		~DataManager();

		static void load_data();
		static void add_airport();
		static void save_data();

	private:
		static bool data_change;
};
