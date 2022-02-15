#ifndef DATABASE_H
#define DATABASE_H
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "DNAProfile.h"
class Database{
	private:
		std::vector<DNAProfile> all_profiles_from_csv;
		std::vector<std::string> current_working_STRs;
		std::string unknown_DNA_string;

	public:
		Database();
		Database(std::string CSV_file_name);
		bool load_database(std::string CSV_file_name);
		bool checkDNAString(std::string DNA_string_file);
		std::string get_unknown_DNA_string();
		std::map<std::string, unsigned int> identifySTRs(std::string DNA_string);
		std::vector<DNAProfile> search_database();
		
};

#endif // DATABASE_H