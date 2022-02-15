#include "Database.h"
#include "UserInterface.h"
#include "DNAProfile.h"

int main(int argc, char* argv[]){
	UserInterface ui;
	if(argc != 3){
		ui.print_message("Usage: ./dna_profiler <database_file.csv> <DNA_string_file>");
		return 1;
	}
	std::string database_file = argv[1];
	std::string DNA_string_file = argv[2];
	Database database;
	if(!database.load_database(database_file)){
		ui.print_error_message("Error with the database, please check your file.");
		return 1;
	}
	if(!database.checkDNAString(DNA_string_file)){
		ui.print_error_message("Error with the DNA string, please check your file.\nNote: A DNA string must contain at least 4 nucleotides and only the letters \"T\", \"G\" \"A\" and \"C\".");
		return 1;
	}

	ui.print_welcome_message();
	ui.print_message("Searching for the dna in your database...", "green");
	std::vector<DNAProfile> threeMatches = database.search_database();
	ui.print_matches(threeMatches, database.get_unknown_DNA_string());
	
	return 0;
}