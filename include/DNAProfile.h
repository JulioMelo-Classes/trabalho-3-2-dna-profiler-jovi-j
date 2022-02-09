#ifndef DNAPROFILE_H
#define DNAPROFILE_H
#include <string>
#include <map>

class DNAProfile{
	private:
		std::map<std::string, int> STRs;
		std::string owner_of_profile;

	public:
		DNAProfile(std::string owner_of_profile);
		float getMatchPercentage(DNAProfile other_profile);
		void addSTR(std::string STR, int times);
		void setOwner(std::string owner);
		std::string getOwner();
		std::map<std::string, int> getSTRs();

};

#endif // DNAPROFILE_H