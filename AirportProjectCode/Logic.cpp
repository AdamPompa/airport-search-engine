#include "Logic.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
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

vector<int> Logic::search_by_country(
const std::string& query,
const std::multimap<std::string, int>& countries) {

	vector<int> results;

	auto range = countries.equal_range(query);
	for (auto itr = range.first; itr != range.second; itr++) {
		results.push_back(itr->second);
	}
	return results;
}

vector<int> Logic::search_by_name(
std::string& query,
const std::vector<Airport>& airports) {
	vector<int> results;

	for (int i = 0; i < airports.size(); i++) {
		string lower_name = airports[i].name;
		transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);

		if (lower_name.find(query) != string::npos) {
			results.push_back(i);
		}
	}
	return results;
}

int Logic::search_by_IATA(
const std::string& query,
const std::unordered_map<std::string, int>& iatas) {
	int result;
	
	auto itr = iatas.find(query);
	if (itr == iatas.end()) {
		return -1;
	}
	else {
		result = itr->second;
		return result;
	}
}

double Logic::get_latitude(const std::string& coord) {
	stringstream ss(coord);
	string latitude;

	getline(ss, latitude, ',');
	return stod(latitude);
}

double Logic::get_longitude(const std::string& coord) {
	stringstream ss(coord);
	string latitude;
	string longitude;

	getline(ss, latitude, ',');
	getline(ss, longitude, '"');

	return stod(longitude);
}

double Logic::convert_to_double(const std::string& elevation) {
	return stod(elevation);
}

int Logic::lowest_elevation(const vector<Airport>& airports) {
	double lowest = convert_to_double(airports[0].elevation);
	int index;

	for (int i = 0; i < airports.size(); i++) {
		if (lowest > convert_to_double(airports[i].elevation)) {
			index = i;
		}
	}
	return index;
}

int Logic::highest_elevation(const vector<Airport>& airports) {
	double highest = convert_to_double(airports[0].elevation);
	int index;

	for (int i = 0; i < airports.size(); i++) {
		if (highest < convert_to_double(airports[i].elevation)) {
			index = i;
		}
	}
	return index;
}