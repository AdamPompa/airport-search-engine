#include "UserInterface.h"
#include "DataManager.h"

int main() {
	DataManager::load_data("airport-test-codes.txt");
	UserInterface::display_results(DataManager::airports, 1);
	return 0;
}