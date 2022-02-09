#include "Database.h"
#include "DNAProfile.h"
#include <iostream>

int main(int argc, char* argv[]){
	if(argc != 3){
		std::cout << "Usage: " << argv[0] << " <database_file.csv> <DNA_string_file>" << std::endl;
		return 1;
	}
	std::string database_file = argv[1];
	std::string DNA_string_file = argv[2];
	Database database;
	if(!database.load_database(database_file)){
		std::cout << "Error loading database, please check your file." << std::endl;
		return 1;
	}
	return 0;
}