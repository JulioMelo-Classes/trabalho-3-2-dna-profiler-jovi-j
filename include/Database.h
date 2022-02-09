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

	public:
		Database();
		Database(std::string CSV_file_name);
		bool load_database(std::string CSV_file_name);
};

#endif // DATABASE_H