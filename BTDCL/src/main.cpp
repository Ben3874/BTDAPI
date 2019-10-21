#include <iostream>
#include "Steam/steamUtils.hpp"

int main(int argc, char* argv[]) {
	// Detect games
	SteamUtils::WindowsGetGameDirectory(BTD6AppId, BTD6Name);

	return EXIT_SUCCESS;
}