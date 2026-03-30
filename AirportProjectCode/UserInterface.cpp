#include "UserInterface.h"
#include <iostream>
#include <cmath>
using namespace std;

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

		cout << endl << "Option: ";
		int choice;

		if (!(cin >> choice)) {
			cout << "Choose Valid Option (1-2)";
			cin.clear();
			cin.ignore(10000, '\n');
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

		cout << endl << "Option: ";
		int choice;

		if (!(cin >> choice)) {
			cout << "Choose Valid Option (1-2)";
			cin.clear();
			cin.ignore(10000, '\n');
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

		cout << endl << "Option: ";
		int choice;

		if (!(cin >> choice)) {
			cout << "Choose Valid Option (1-7)";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		switch (choice) {
			case 1:
				UserInterface::search_by_country_menu();
				break;
			case 2:
				cout << "success";
				break;
			case 3:
				cout << "success";
				break;
			case 4:
				cout << "success";
				break;
			case 5:
				cout << "success";
				break;
			case 6:
				cout << "success";
				break;
			case 7:
				cout << "success";				
				break;
			default:
				cout << "Choose Valid Option (1-7)";
		}
	}
}
