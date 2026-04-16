#pragma once
#include <vector>
#include "DataManager.h"

class UserInterface {
	public:
	// menus
	static void count_by_type_menu();
	static void add_new_airport_menu();
	static void main_menu();
	static void search_by_country_menu();
	static void search_by_name_menu();
	static void search_by_iata_menu();
	static void advanced_options_menu();
	static bool exit_menu();

	// helper functions
	static std::string input_check();
	static std::string trim(const std::string& input);
	static int type_select();
	static double double_validator();

	// sub menus
	static void iata_searchbar();
	static void fill_new_airport(Airport& a);
	static void country_searchbar();
	static int name_searchbar();
	static void high_low_display();
	static void between_airports_menu();
	static void nearest_loc_menu(const std::vector<Airport>& airports);
	static void radius_menu();

	// display functions
	static void display_result(const std::vector <Airport>& airport, int index);
	static int search_results(const std::vector<int>& index);
};
