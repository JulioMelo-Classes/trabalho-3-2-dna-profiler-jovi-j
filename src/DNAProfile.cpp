#include "DNAProfile.h"

DNAProfile::DNAProfile(std::string owner_of_profile){
	this->owner_of_profile = owner_of_profile;
}

void DNAProfile::addSTR(std::string STR, int times){
	if(this->STRs.find(STR) == this->STRs.end()){
		this->STRs[STR] = times;
	}
	else{
		this->STRs[STR] += times;
	}
}

void DNAProfile::setOwner(std::string owner){
	this->owner_of_profile = owner;
}

std::map<std::string, unsigned int> DNAProfile::getSTRs(){
	return this->STRs;
}

std::string DNAProfile::getOwner(){
	return this->owner_of_profile;
}



bool DNAProfile::isSTROnProfile(std::string STR){
	if(this->STRs.find(STR) != this->STRs.end()){
		return true;
	}
	return false;
}

void DNAProfile::setSTRs(std::map<std::string, unsigned int> STRs){
	this->STRs = STRs;
}
unsigned int DNAProfile::getTimesOfSTR(std::string STR){
	return this->STRs[STR];
}

float DNAProfile::getMatchPercentage(DNAProfile other_profile){
	float match_percentage = 0;
	for(auto STR : this->STRs){
		if(other_profile.getTimesOfSTR(STR.first) == STR.second){
			match_percentage += 1;
		}
	}
	match_percentage = match_percentage / this->STRs.size();
	return match_percentage * 100;
}

bool DNAProfile::operator==(DNAProfile other_profile){
	if(this->STRs == other_profile.getSTRs()){
		return true;
	}
	return false;
}