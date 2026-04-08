#pragma once
#include <vector>
#include "DataManager.h"

class UserInterface {
	public:
		
	static void main_menu();
	static void search_by_country_menu();
	static void search_by_name_menu();
	static void search_by_iata_menu();
	static void count_by_type_menu();
	static void add_new_airport_menu();
	static void advanced_options_menu();
	static void exit_menu();
	static void display_results(const std::vector <Airport>& airport, int index);
	static void display_count();
};
