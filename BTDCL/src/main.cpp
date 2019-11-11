#include <iostream>
#include "Steam/steamUtils.hpp"
#include "Memory/memory.hpp"
#include "BTD5API/api.hpp"

String FormatBool(bool Bool) {
	// Uses ANSI escape codes
	if (Bool == true) {
		//return "\x1B[92m[True]\033[0m";
		return "[True]";
	}
	else {
		//return "\x1B[91m[False]\033[0m";;
		return "[False]";
	}

};

HANDLE Btd5Handle;
HANDLE BtdBHandle;
HANDLE Btd6Handle;

BTD5API Btd5API;

void TestBTD5() {
	LOGM("Running Tests for BTD5...");

	HMODULE Btd5Mod = LoadMemory::GetModulePointer(Btd5Handle, BTD5PROCNAME);

	WindowsMemory BTD5;
	BTD5.Initialise(Btd5Handle, Btd5Mod);

	Btd5API.Initialise(&BTD5);

	for (;;) {
		for (int i = 0; i < Btd5API.BloonList.size(); i++) {
			Bloon bloon = Btd5API.BloonList[i];
			String type = bloon.bloonType.GetNameFromType(bloon.bloonType.type);
			std::cout << "Dumping information about bloon " << i + 1 << ":\n"
				<< "Address: " << std::hex << bloon.BloonAddr << std::dec << "\n"
				<< "Scale X: " << bloon.spriteX << "\n"
				<< "Scale Y: " << bloon.spriteY << "\n"
				<< "Distance on track: " << bloon.Distance << "\n"
				<< "Pos X: " << bloon.PosX << "\n"
				<< "Pos Y: " << bloon.PosY << "\n"
				//<< "Bloon Type: " << type << "\n"
				;

			Btd5API.BloonList[i].spriteX += 0.1f;
		}
		Sleep(1000);
	}

}

void Run() {

	Btd5Handle = LoadMemory::GetProcessPointer(BTD5PROCNAME);
	BtdBHandle = LoadMemory::GetProcessPointer(BTDBPROCNAME);
	Btd6Handle = LoadMemory::GetProcessPointer(BTD6PROCNAME);

	bool AnyGameRunning = false;

	bool BTD5Running = false;
	if (Btd5Handle != INVALID_HANDLE_VALUE) {
		BTD5Running = true;
	}

	bool BTDBRunning = false;
	if (BtdBHandle != INVALID_HANDLE_VALUE) {
		BTDBRunning = true;
	}

	bool BTD6Running = false;
	if (Btd6Handle != INVALID_HANDLE_VALUE) {
		BTD6Running = true;
	}

	AnyGameRunning = AnyGameRunning | BTD5Running | BTDBRunning | BTD6Running;

	if (AnyGameRunning) {
		cout << "BTD Game is running... Attempting to attach...\n";
		if (BTD5Running) {
			cout << "Bloons TD 5 is currently running!\n";
			TestBTD5();
			}
		if (BTDBRunning) {
			cout << "Bloons TDB is currently running!\n";
		}
		if (BTD6Running) {
			cout << "Bloons TD6 is currently running!\n";
		}

	}
	else {
		cout << "No game is running...\n";
	}
}




int main(int argc, char* argv[]) {

	LOGI("===Bloons TD API Command Line===");
	LOGI("Version: 1");
	LOGM("Detecting BTD game installations...");

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

	cout << "BTD5 Detected: " << FormatBool(BTD5Detected) << "\n";
	cout << "BTDB Detected: " << FormatBool(BTDBDetected) << "\n";
	cout << "BTD6 Detected: " << FormatBool(BTD6Detected) << "\n";

	cout << "Success! Initialised succesfully.\n";

	cout << "\nChecking if any games are running...\n";

	Run();

	cout << "Type help for a list of commands\n";




	



	// Detect games
	

	return EXIT_SUCCESS;
}