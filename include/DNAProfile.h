#ifndef DNAPROFILE_H
#define DNAPROFILE_H
#include <string>
#include <map>

class DNAProfile{
	private:
		std::map<std::string, unsigned int> STRs;
		std::string owner_of_profile;

	public:
		DNAProfile(std::string owner_of_profile);
		float getMatchPercentage(DNAProfile other_profile);
		void addSTR(std::string STR, int times);
		unsigned int getTimesOfSTR(std::string STR);
		void setOwner(std::string owner);
		std::string getOwner();
		void setSTRs(std::map<std::string, unsigned int> STRs);
		std::map<std::string, unsigned int> getSTRs();
		bool isSTROnProfile(std::string STR);
		bool operator==(DNAProfile other_profile);

};

#endif // DNAPROFILE_H