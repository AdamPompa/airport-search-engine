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
	Coordinates coordinates;
};

class DataManager {

	public:
		static void load_data();

		static void add_airport(
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
			double longitude);
		
		static string coord_to_string(const Coordinates& c);
		static string escape_csv(const string& field);
		static void save_data(const vector <Airport>& airports);

	private:
		static bool data_change;
};
