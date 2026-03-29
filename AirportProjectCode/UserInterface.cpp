#include "UserInterface.h"
#include <iostream>
using namespace std;

void UserInterface::main_menu() {
	
	string title = " Main Menu ";
	int border_width = 25;

	cout << string(border_width, '=')
		<< title
		<< string(border_width, '=')
		<< endl;

}