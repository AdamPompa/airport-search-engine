#pragma once
#include <iostream>
#include <vector>

struct Airport {
	std::string ident;
	std::string type;
	std::string name;
	std::string elevation;
	std::string continent;
	std::string iso_country;
	std::string iso_region;
	std::string municipality;
	std::string icao_code;
	std::string iata_code;
	std::string gps_code;
	std::string local_code;
	std::string coordinates;
};

class DataManager {

	public:
		static std::vector <Airport> airports;
		static void load_data(const std::string& csv);
		static void add_airport ();
		static std::string escape_csv(const std::string& field);
		static void save_data(const std::vector <Airport>& airports);

	private:
		static bool data_change;
};
