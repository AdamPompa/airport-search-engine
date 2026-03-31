#include "UserInterface.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

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
