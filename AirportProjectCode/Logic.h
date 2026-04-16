#pragma once
#include <string>
#include <vector>
#include "DataManager.h"
#include <sstream>

class Logic {
	public:
		// search functions
		static std::vector<int> search_by_country(
			const std::string& query, 
			const std::multimap<std::string, int>& countries);

		static std::vector<int> search_by_name(
			std::string& query, 
			const std::vector<Airport>& airports);

		static int search_by_IATA(
			const std::string& query,
			const std::unordered_map<std::string, int>& iatas); 

		// helper functions
		static std::vector<int> type_counter(const std::vector<Airport>& airports); 
		static double get_latitude(const std::string& coord);
		static double get_longitude(const std::string& coord);
		static double convert_to_double(const std::string& elevation);

		// calculation functions
		static int lowest_elevation(const std::vector<Airport>& airports);
		static int highest_elevation(const std::vector<Airport>& airports);
		static double distance_calculator(double lat1, double long1, double lat2, double long2);
		static int nearest_calculator(double lat1, double long1);
		static std::vector<int> radius_calculator(double lat1, double long1, double radius);
};