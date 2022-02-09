#include "Database.h"
#include <string>

Database::Database(){
}

bool Database::load_database(std::string csv_filename){
	std::ifstream csv_file(csv_filename);
	if (!csv_file.is_open()){
		return false;
	}
	std::string line;
	std::string name;
	std::string STR;
	std::vector<std::string> workingSTRs;
	int STR_count;
	getline(csv_file, line);
	std::stringstream ss(line);
	while(getline(ss, STR, ',')){
		workingSTRs.push_back(STR);
	}
	workingSTRs.erase(workingSTRs.begin());

	while(getline(csv_file, line)){
		std::stringstream ss(line);
		getline(ss, name, ',');
		DNAProfile new_profile(name);
		for(int i = 0; i < workingSTRs.size(); i++){
			getline(ss, STR, ',');
			STR_count = std::stoi(STR);
			new_profile.addSTR(workingSTRs[i], STR_count);
		}
		all_profiles_from_csv.push_back(new_profile);
	}
	return true;
}