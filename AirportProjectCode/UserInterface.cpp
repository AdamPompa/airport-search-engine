#include "UserInterface.h"
#include "Datamanager.h"
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

void UserInterface::fill_new_airport(Airport& a) {
	cout << "Enter Identification: ";
	getline(cin, a.ident);
	if (a.ident.find_first_not_of(" \t\n\r") == string::npos) {
		a.ident = "";
	}

	cout << "Enter Type: ";
	getline(cin, a.type);
	if (a.type.find_first_not_of(" \t\n\r") == string::npos) {
		a.type = "";
	}

	cout << "Enter Name: ";
	getline(cin, a.name);
	if (a.name.find_first_not_of(" \t\n\r") == string::npos) {
		a.name = "";
	}

	cout << "Enter Elevation: ";
	getline(cin, a.elevation);
	if (a.elevation.find_first_not_of(" \t\n\r") == string::npos) {
		a.elevation = "";
	}

	cout << "Enter Continent: ";
	getline(cin, a.continent);
	if (a.continent.find_first_not_of(" \t\n\r") == string::npos) {
		a.continent = "";
	}

	cout << "Enter Country: ";
	getline(cin, a.iso_country);
	if (a.iso_country.find_first_not_of(" \t\n\r") == string::npos) {
		a.iso_country = "";
	}

	cout << "Enter Region: ";
	getline(cin, a.iso_region);
	if (a.iso_region.find_first_not_of(" \t\n\r") == string::npos) {
		a.iso_region = "";
	}

	cout << "Enter Municipality: ";
	getline(cin, a.municipality);
	if (a.municipality.find_first_not_of(" \t\n\r") == string::npos) {
		a.municipality = "";
	}

	cout << "Enter ICAO Code: ";
	getline(cin, a.icao_code);
	if (a.icao_code.find_first_not_of(" \t\n\r") == string::npos) {
		a.icao_code = "";
	}

	cout << "Enter IATA Code: ";
	getline(cin, a.iata_code);
	if (a.iata_code.find_first_not_of(" \t\n\r") == string::npos) {
		a.iata_code = "";
	}

	cout << "Enter GPS Code: ";
	getline(cin, a.gps_code);
	if (a.gps_code.find_first_not_of(" \t\n\r") == string::npos) {
		a.gps_code = "";
	}

	cout << "Enter Local Code: ";
	getline(cin, a.local_code);
	if (a.local_code.find_first_not_of(" \t\n\r") == string::npos) {
		a.local_code = "";
	}

	cout << "Enter Coordinates: ";
	getline(cin, a.coordinates);
	if (a.coordinates.find_first_not_of(" \t\n\r") == string::npos) {
		a.coordinates = "";
	}
}

void UserInterface::display_results(const vector<Airport>& airports, int index) {
	Airport selected = airports[index];
	string airport_name = " " + selected.name + " ";
	int border_space = 75;
	int name_border = round((border_space - airport_name.length()) / 2);

	cout << string(name_border, '=')
		<< airport_name 
		<< string(name_border, '=')
		<< endl;
	
	cout << setw(35) << "Identification: " << selected.ident
		<< setw(35) << "Type: " << selected.type << endl

		<< setw(35) << "Elevation: " << selected.elevation
		<< setw(35) << "Continent: " << selected.continent << endl

		<< setw(35) << "Country: " << selected.iso_country
		<< setw(35) << "Region: " << selected.iso_region << endl

		<< setw(35) << "Municipality: " << selected.municipality
		<< setw(35) << "ICAO Code: " << selected.icao_code << endl

		<< setw(35) << "IATA Code: " << selected.iata_code
		<< setw(35) << "GPS Code: " << selected.gps_code << endl

		<< setw(35) << "Local Code: " << selected.local_code
		<< setw(35) << "Coordinates: " << selected.coordinates << endl;
	
	string input;
	cout << "Press any key to exit: ";
	getline(cin, input);

	if (!input.empty()) {
		return;
	}
}

void UserInterface::exit_menu() {

	string title = " Exit ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << "1. Exit (Any additions to the database will be saved)" << endl
			<< "2. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			if (choice < 1 || choice > 2) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			cout << "success";
			break;
		case 2:
			return;
		}
	}
}

void UserInterface::advanced_options_menu() {

	string title = " Advanced Options ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << "1. Add New Airport" << endl
			<< "2. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			if (choice < 1 || choice > 2) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			cout << "success";
			break;
		case 2:
			return;
		}
	}
}

void UserInterface::add_new_airport_menu() {

	string title = " Add New Airport ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << "1. Add New Airport" << endl
			<< "2. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			if (choice < 1 || choice > 2) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			cout << "success";
			break;
		case 2:
			return;
		}
	}
}

void UserInterface::count_by_type_menu() {

	string title = " Count by Type ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		// count function here

		cout << "1. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1)";
				continue;
			}

			if (choice != 1) {
				cout << endl << "Choose Valid Option (1)";
				continue;
			}
			break;
		}
		return;
	}
}

void UserInterface::search_by_iata_menu() {

	string title = " Search by IATA ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << "Choose an Option:" << endl
			<< "1. Search" << endl
			<< "2. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			if (choice < 1 || choice > 2) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			cout << "success";
			break;
		case 2:
			return;
		}
	}
}

void UserInterface::search_by_name_menu() {

	string title = " Search by Name ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << "Choose an Option:" << endl
			<< "1. Search" << endl
			<< "2. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			if (choice < 1 || choice > 2) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			cout << "success";
			break;
		case 2:
			return;
		}
	}
}

void UserInterface::search_by_country_menu() {

	string title = " Search by Country ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << "Choose an Option:" << endl
			<< "1. Search" << endl
			<< "2. Back to Main Menu";

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty())
			{
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}

			if (choice < 1 || choice > 2) {
				cout << endl << "Choose Valid Option (1-2)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			cout << "success";
			break;
		case 2:
			return;
		}
	}
}

void UserInterface::main_menu() {
	string title = " Main Menu ";
	int border_space = 50;
	int menu_border = round((border_space - title.length()) / 2);

	while (true) {
		cout << string(menu_border, '=')
			<< title
			<< string(menu_border, '=')
			<< endl;

		cout << endl << "Choose an Option:" << endl
			<< "1. Search by Country" << endl
			<< "2. Search by Name" << endl
			<< "3. Search by IATA" << endl
			<< "4. Count by Type" << endl
			<< "5. Add New Airport" << endl
			<< "6. Advanced Options" << endl
			<< "7. Exit" << endl;

		string string_choice;
		int choice;
		while (true) {
			cout << endl << "Option: ";
			getline(cin, string_choice);

			if (string_choice.empty()) 
			{
				cout << endl << "Choose Valid Option (1-7)";
				continue;
			}

			try {
				choice = stoi(string_choice);
			}
			catch (...) {
				cout << endl << "Choose Valid Option (1-7)";
				continue;
			}

			if (choice < 1 || choice > 7) {
				cout << endl << "Choose Valid Option (1-7)";
				continue;
			}
			break;
		}

		switch (choice) {
		case 1:
			search_by_country_menu();
			break;
		case 2:
			search_by_name_menu();
			break;
		case 3:
			search_by_iata_menu();
			break;
		case 4:
			count_by_type_menu();
			break;
		case 5:
			add_new_airport_menu();
			break;
		case 6:
			advanced_options_menu();
			break;
		case 7:
			exit_menu();
			break; // this will need to end the entire program
		default:
			cout << "Choose Valid Option (1-7)";
		}
	}
}
