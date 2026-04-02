#pragma once
#include <iostream>
using namespace std;


struct Coordinates {
	double latitude;
	double longitude;
};

struct Airport {
	string ident;
	string type;
	string name;
	int elevation;
	string continent;
	string iso_country;
	string iso_region;
	string municipality;
	string icao_code;
	string iata_code;
	string gps_code;
	string local_code;
	Coordinates airport_coordinates;
};

class DataManager {

	public:
		static void load_data();
		static void add_airport(string ident, string type, string name, int elevation,string continent, string iso_country,string iso_region, string municipality,string icao_code, string iata_code,string gps_code, string local_code, Coordinates airport_coordinates);
		static void save_data();

	private:
		static bool data_change;
};
