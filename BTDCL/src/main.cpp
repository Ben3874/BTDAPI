#include <iostream>
#include "Steam/steamUtils.hpp"

String FormatBool(bool Bool) {
	// Uses ANSI escape codes
	if (Bool == true) {
		return "\x1B[92m[True]\033[0m";
	}
	else {
		return "\x1B[91m[False]\033[0m";;
	}

};

int main(int argc, char* argv[]) {

	std::cout << "===Bloons TD API Command Line===\n";
	std::cout << "Detecting BTD games...\n";

	String BTD5Dir = SteamUtils::WindowsGetGameDirectory(BTD5AppId, BTD5Name);
	String BTDBDir = SteamUtils::WindowsGetGameDirectory(BTDBAppId, BTDBName);
	String BTD6Dir = SteamUtils::WindowsGetGameDirectory(BTD6AppId, BTD6Name);

	bool BTD5Detected = false;
	if (BTD5Dir != "") {
		BTD5Detected = true;
	}

	bool BTDBDetected = false;
	if (BTDBDir != "") {
		BTDBDetected = true;
	}

	bool BTD6Detected = false;
	if (BTD6Dir != "") {
		BTD6Detected = true;
	}

	std::cout << "BTD5 Detected: " << FormatBool(BTD5Detected) << "\n";
	std::cout << "BTDB Detected: " << FormatBool(BTDBDetected) << "\n";
	std::cout << "BTD6 Detected: " << FormatBool(BTD6Detected) << "\n";

	std::cout << "Success! Initialised succesfully.\n";
	std::cout << "Type help for a list of commands\n";




	// Detect games
	

	return EXIT_SUCCESS;
}