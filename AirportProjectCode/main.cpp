#include "UserInterface.h"
#include "DataManager.h"
#include "Logic.h"

int main() {
	DataManager::load_data("airport - codes.csv");
	DataManager::make_maps(DataManager::airports);
	UserInterface::main_menu();
	return 0;
}