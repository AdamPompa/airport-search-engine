#pragma once
#include <string>
#include <vector>
#include "DataManager.h"

class Logic {
	public:
		static std::vector<int> search_by_country(
			const std::string& query, 
			const std::multimap<std::string, int>& countries);

		static std::vector<int> search_by_name(
			const std::string& query, 
			const std::vector<Airport>& airports);

		static int search_by_IATA(
			const std::string& query,
			const std::unordered_map<std::string, int>& iatas); 

		static std::vector<int> type_counter(const std::vector<Airport>& airports); 
};