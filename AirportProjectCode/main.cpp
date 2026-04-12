#include "UserInterface.h"
#include "DataManager.h"

int main() {
	DataManager::load_data("airport-test-codes.txt");
	UserInterface::display_result(DataManager::airports, 3);
	UserInterface::main_menu();
	return 0;
}