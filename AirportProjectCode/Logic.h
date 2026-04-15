#pragma once
#include <string>
#include <vector>
#include "DataManager.h"
#include <sstream>

class Logic {
	public:
		static std::vector<int> search_by_country(
			const std::string& query, 
			const std::multimap<std::string, int>& countries);

		static std::vector<int> search_by_name(
			std::string& query, 
			const std::vector<Airport>& airports);

		static int search_by_IATA(
			const std::string& query,
			const std::unordered_map<std::string, int>& iatas); 

		static std::vector<int> type_counter(const std::vector<Airport>& airports); 
		static double get_latitude(const std::string& coord) {
			std::stringstream ss(coord);
			std::string latitude;

			getline(ss, latitude, ',');
			return std::stod(latitude);
		}

		double get_longitude(const std::string& coord) {
			std::stringstream ss(coord);
			std::string latitude;
			std::string longitude;

			getline(ss, latitude, ',');
			getline(ss, longitude, '"');

			return std::stod(longitude);
		}
};