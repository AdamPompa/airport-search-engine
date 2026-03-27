#pragma once

class DataManager {

	public:
		DataManager();
		~DataManager();

		void load_data();
		void add_airport();
		void save_data();

	private:
		static bool data_change;
};
