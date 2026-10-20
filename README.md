# Airport-Search-Engine
This search engine is a console-based C++ application, which can search, sort and analyze airport data. Users can also add new airports to the database.

This project makes use of C++, CSV file handling and object-oriented programming. Data management, program logic and the user interface are handled by separate classes. The IDE used was Visual Studio.

This project helped me learn to separate responsibilities between classes, processing a CSV and implementing searching and sorting logic.

(This program cannot be successfully ran as the data I was provided for this coursework is no longer available to me. However, the code making use of that data can still be viewed and ran.)

## Project Plan

data structure = struct + vector. This will hold the main database

I will also use:
- An unordered map for IATA search
- A multi-map for country, municipality search, type, latitude/longitude, elevation
- and the find() method for partial name search.

## Features
- searching (by country, name, IATA)
- sorting (municipality, name, country, type, elevation, coordinates)
- count by type (small, large, heliport)
- get latitude/longitude
- find airport with lowest/highest elevation
- find distance between two given airports
- find distance to nearest airport from given point
- find airports in given radius from given point

## Classes 

### DataManager

attributes: data_change

data_change tracks whether the CSV has been changed at all and determines if the CSV should be overwritten.

methods: load_data(), add_airport(), save_data()

load_data() reads from the CSV and creates a vector of structs in working memory for the program to use.


- Logic class will handle all searching, sorting, analysis etc.
- Display class will handle menus and displaying data in a readable way

![AirportProjectUML](AirportProjectUML.png)
