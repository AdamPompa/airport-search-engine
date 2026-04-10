#include "UserInterface.h"
#include "DataManager.h"

int main() {
	DataManager::load_data("airport-test-codes.txt");
	UserInterface::main_menu();
	return 0;
}