#include <iostream>
#include "Steam/steamUtils.hpp"
#include "Memory/memory.hpp"
#include "BTD5API/api.hpp"

String FormatBool(bool Bool) {
	// Uses ANSI escape codes
	if (Bool == true) {
		return "\x1B[92m[True]\033[0m";
	}
	else {
		return "\x1B[91m[False]\033[0m";;
	}

};

HANDLE Btd5Handle;
HANDLE BtdBHandle;
HANDLE Btd6Handle;


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
		cout << "BTD Game is running... Attempting to attach...\n ";
		if (BTD5Running) {
			cout << "Bloons TD 5 is currently running...\n";
			}
		if (BTDBRunning) {
			cout << "Bloons TDB is currently running...\n";
		}
		if (BTD6Running) {
			cout << "Bloons TD6 is currently running...\n";
		}

	}
	else {
		cout << "No game is running...\n";
	}
}

const u64 BASEPTR = 0x00884280;

int main(int argc, char* argv[]) {

	cout << "===Bloons TD API Command Line===\n";
	cout << "Detecting BTD game installations...\n";

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

	HMODULE Btd5Mod = LoadMemory::GetModulePointer(Btd5Handle, BTD5PROCNAME);

	WindowsMemory BTD5(Btd5Handle, Btd5Mod);



	//for (;;) {
	//	
	//	

	//	u32 firstPtrTest = BTD5.OffsetFromMod((u32)0x0088'4280);
	//	u32 BaseAddr;
	//	BTD5.Read((u32)firstPtrTest, &BaseAddr);


	//	const std::vector<u32> OffsetList = { 0x0, 0x74, 0x4, 0x0, 0x26C };

	//	u32 Dist = (u32)BTD5.MultiLevelPtr(BaseAddr, OffsetList);
	//	float dis1 = reinterpret_cast<float&>(Dist);
	//	


	//	int x = 5;
	//}
	



	// Detect games
	

	return EXIT_SUCCESS;
}