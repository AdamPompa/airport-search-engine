#include "UserInterface.h"
#include "DataManager.h"

int main() {
	DataManager::load_data("airport-test-codes.txt");
	DataManager::make_maps(DataManager::airports);
	UserInterface::main_menu();
	return 0;
}