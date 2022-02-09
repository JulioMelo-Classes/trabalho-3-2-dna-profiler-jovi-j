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

std::string DNAProfile::getOwner(){
	return this->owner_of_profile;
}

std::map<std::string, int> DNAProfile::getSTRs(){
	return this->STRs;
}

float DNAProfile::getMatchPercentage(DNAProfile other_profile){
	float match_percentage = 0;
	std::map<std::string, int> other_STRs = other_profile.getSTRs();
	for(std::map<std::string, int>::iterator it = this->STRs.begin(); it != this->STRs.end(); it++){
		if(other_STRs.find(it->first) != other_STRs.end()){
			match_percentage += (float)it->second / (float)other_STRs[it->first];
		}
	}
	return match_percentage;
}