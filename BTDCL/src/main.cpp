#include <iostream>
#include "Steam/steamUtils.hpp"
#include "Memory/memory.hpp"

String FormatBool(bool Bool) {
	// Uses ANSI escape codes
	if (Bool == true) {
		return "\x1B[92m[True]\033[0m";
	}
	else {
		return "\x1B[91m[False]\033[0m";;
	}

};

const uint32 BASEPTR = 0x00884280;

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

	HANDLE Btd5Handle = LoadMemory::GetProcessPointer(BTD5PROCNAME);
	HMODULE Btd5Mod = LoadMemory::GetModulePointer(Btd5Handle, BTD5PROCNAME);

	WindowsMemory Memory(Btd5Handle, Btd5Mod);

	const std::vector<uint32> FirstChain = { 0x0, 0x74 };
	const std::vector<uint32> LastChain = { 0x0, 0x74 };

	IntPtr FirstPtr = Memory.IntChainFromOffset(BASEPTR, FirstChain);
	IntPtr LastPtr = Memory.IntChainFromOffset(BASEPTR, LastChain);

	for (;;) {
		IntPtr First = FirstPtr + 0x4;
		IntPtr Last = LastPtr + 0x8;
		std::cout << "NumBloons: " << (First - Last / 4) << "\n";
	}

	



	// Detect games
	

	return EXIT_SUCCESS;
}