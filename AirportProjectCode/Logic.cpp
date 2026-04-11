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

