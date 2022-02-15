#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "DNAProfile.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class UserInterface{
	private:
		std::string green_color = "\033[1;32m";
		std::string red_color = "\033[1;31m";

		std::string end_reset_color = "\033[0m";

	public:
		void print_message(std::string message, std::string color = "none");
		void print_error_message(std::string message);
		void print_welcome_message();
		void print_matches(std::vector<DNAProfile> matches, std::string DNAString);
		void print_match_places(DNAProfile match, DNAProfile matchedProfile, std::string DNAString);
};

#endif // USERINTERFACE_H