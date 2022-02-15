#include "UserInterface.h"
void UserInterface::print_message(std::string message, std::string color){
	if(color == "green"){
		std::cout << green_color << message << end_reset_color << std::endl;
	}
	else if(color == "red"){
		std::cout << red_color << message << end_reset_color << std::endl;
	}
	else{
		std::cout << message << std::endl;
	}
}


void UserInterface::print_error_message(std::string message){
	std::cout << red_color << message << end_reset_color << std::endl;
}

void UserInterface::print_welcome_message(){
	std::cout << std::endl;
	std::cout << "\033[1;32m\t\tWelcome to DNA Profiler!\033[0m" << std::endl
			  << std::endl;
	std::cout << "Please wait while we search for the dna in your database file..." << std::endl;
}
void UserInterface::print_match_places(DNAProfile match, DNAProfile matchedProfile, std::string DNAString){
	std::cout << "Match ID(" << match.getMatchPercentage(matchedProfile) << "%): " << match.getOwner() << std::endl;

	// for (int i = 0; i < DNAString.length() - 3; i++)
	// {
	// 	std::string STR = DNAString.substr(i, 4);
	// 	if(match.isSTROnProfile(STR)){
	// 		std::cout << "[" << STR << "x" << match.getTimesOfSTR(STR) << "]";
	// 		i += 7;
	// 	}
	// 	else{
	// 		std::cout << " ";
	// 	}
	// }

	// std::cout << std::endl;

	// for (int i = 0; i < DNAString.length() - 3; i++){
	// 	std::string STR = DNAString.substr(i, 4);
	// 	if(match.isSTROnProfile(STR)){
	// 		for (int j = 0; j < match.getTimesOfSTR(STR); j++){
	// 			std::cout << "vvvv";
	// 			i+= 4;
	// 		}
	// 	}
	// 	else{
	// 		std::cout << " ";
	// 	}
	// }

	// std::cout << std::endl;

	std::cout << "[";
	for (int i = 0; i < DNAString.length() - 3; i++){
		std::string STR = DNAString.substr(i, 4);
		if(match.isSTROnProfile(STR)){
			std::cout << green_color << STR << end_reset_color;
			i += 3;
		}
		else{
			std::cout << STR.substr(0, 1);
		}
	}

	std::cout << "]" << std::endl;

	std::cout << "STRs: ";
	for (auto str : match.getSTRs()){
		std::cout << str.first << "x" << str.second << " ";
	}

}


void UserInterface::print_matches(std::vector<DNAProfile> matches, std::string DNAString){
	if(matches.size() == 1){
		print_error_message("No matches found!");
		return;
	}
	else if (matches.size() == 2){
		print_message("Match found!", "green");
	}
	else{
		print_message("Matches found!", "green");
	}
	for(int i = 1; i < matches.size(); i++){
			print_match_places(matches[i], matches[0], DNAString);
	}
}
