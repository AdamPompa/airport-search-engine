#include "Logic.h"
#include <iostream>
using namespace std;

vector<int> Logic::type_counter(const std::vector<Airport>& airports) {
	int small_airport_count = 0;
	int large_airport_count = 0;
	int heliport_count = 0;

	for (const Airport& a : airports) {
		if (a.type == "small_airport") 
		{
			small_airport_count++;
		}
		else if (a.type == "large_airport")
		{
			large_airport_count++;
		}
		else if (a.type == "heliport")
		{
			heliport_count++;
		}
	}

	vector<int> type_count = {
		small_airport_count,
		large_airport_count,
		heliport_count
	};

	return type_count;
}

vector<int> Logic::search_by_country(const std::string& query) {
	vector<int> results;

	auto range = DataManager::country_map.equal_range(query);
	for (auto itr = range.first; itr != range.second; itr++) {
		results.push_back(itr->second);
	}
	return results;
}

vector<int> Logic::search_by_name(const std::string& query, const std::vector<Airport>& airports) {
	vector<int> results;

	for (int i = 0; i < airports.size(); i++) {
		if (airports[i].name.find(query) != true) {
			results.push_back(i);
		}
	}

	return results;
}

int Logic::search_by_IATA(const std::string& query) {
	int result;
	
	auto itr = DataManager::iata_map.find(query);
	result = itr->second;
	
	return result;
}