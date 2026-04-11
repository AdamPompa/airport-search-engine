#pragma once
#include <string>
#include <vector>
#include "DataManager.h"

class Logic {
	public:
		static std::vector<int> search_by_country(const std::string& query);
		static std::vector<int> search_by_name(const std::string& query);
		static std::vector<int> search_by_IATA(const std::string& query); 
		static std::vector<int> type_counter(const std::vector<Airport>& airports); 
};