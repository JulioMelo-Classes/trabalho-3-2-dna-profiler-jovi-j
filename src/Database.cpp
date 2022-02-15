#include "Database.h"
#include <string>
#include <algorithm>
#include <map>

#include <iostream>

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

	this->current_working_STRs = workingSTRs;
	return true;
}

bool Database::checkDNAString(std::string DNA_string_file){
	std::ifstream DNA_string_file_stream(DNA_string_file);
	if (!DNA_string_file_stream.is_open()){
		return false;
	}
	std::string line;
	while(getline(DNA_string_file_stream, line)){
		if(line.empty()){
			continue;
		}
		if(line.length() < 4){
			return false;
		}
		for(int i = 0; i < line.length(); i++){
			if(line[i] != 'A' && line[i] != 'C' && line[i] != 'G' && line[i] != 'T'){
				return false;
			}
		}
		this->unknown_DNA_string = line;
	}
	return true;
}

std::string Database::get_unknown_DNA_string(){
	return this->unknown_DNA_string;
}

std::map<std::string, unsigned int> Database::identifySTRs(std::string DNA_string){
	std::map<std::string, unsigned int> STRs;
	for(int i = 0; i < DNA_string.length() - 3; i++){
		std::string STR = DNA_string.substr(i, 4);
		if(std::find(this->current_working_STRs.begin(), this->current_working_STRs.end(), STR) != this->current_working_STRs.end()){
			STRs[STR] += 1;
		}
	}
	return STRs;
}

std::vector<DNAProfile> Database::search_database(){
	std::map<std::string, unsigned int> STRs_in_DNA_string_file = identifySTRs(this->unknown_DNA_string);

	DNAProfile unknownProfile("");
	unknownProfile.setSTRs(STRs_in_DNA_string_file);

	std::vector<DNAProfile> most_matching_profiles;

	most_matching_profiles.push_back(unknownProfile);

	for(int i = 0; i < this->all_profiles_from_csv.size(); i++){
		if(this->all_profiles_from_csv[i].getMatchPercentage(unknownProfile) > 40){
			most_matching_profiles.push_back(this->all_profiles_from_csv[i]);
		}
	}
	return most_matching_profiles;
}