# Airport-Search-Engine
Project coursework for programming


## Project Plan

data structure = struct + vector. This will hold the main database

I will also use:
- An unordered map for IATA search
- A multimap for country, municipality search, type, latitude/longitude, elevation
- and the find() method for partial name search.


## Classes 

### DataManager

attributes: data_change

data_change tracks wether the csv has been changed at all and determines if the csv should be overwritten.

methods: load_data(), add_airport(), save_data()

load_data() reads from the csv and creates a vector of structs in working memory for the program to use.


- Logic class will handle all searching, sorting, analysis etc.
- Display class will handle menus and displaying data in a readable way

![AirportProjectUML](AirportProjectUML.png)
