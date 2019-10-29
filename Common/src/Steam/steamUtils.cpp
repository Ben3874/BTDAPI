#include "Core/core.hpp"
#include "Steam/steamUtils.hpp"
#include <iostream>
#include <vector>
#include <fstream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <tchar.h>
#include <WinReg.h>

String SteamUtils::convertUnixPathToWindows(String unixPath) {
	for (int i = 0; i < unixPath.size(); i++) {
		if (unixPath[i] == '/') {
			unixPath[i] = '\\';
		}
	}
	return unixPath;
}

String SteamUtils::WindowsGetGameDirectory(u64 appid, std::string gameName) {

	BOOL ErrorCode;
	DWORD KeyType;

	//
	// Check if AppID is installed
	//

	HKEY GameKey = NULL;

	ErrorCode = RegOpenKeyEx(
		HKEY_CURRENT_USER,
		"Software\\Valve\\Steam\\Apps\\960090",
		NULL,	// 1 if the key is a symbolic link
		KEY_QUERY_VALUE,
		&GameKey
	);

	if (ErrorCode == ERROR_FILE_NOT_FOUND || 
		ErrorCode == ERROR_PATH_NOT_FOUND || 
		ErrorCode == ERROR_BAD_PATHNAME) {

		LOGW("WARNING: " << gameName << " not found!");
		return "";
	}

	if (ErrorCode != ERROR_SUCCESS) {
		LOGE("ERROR: " << TO_STRING(appid) << "'s key failed. WinAPI error code: " << TO_STRING(ErrorCode));
	}

	DWORD installed = false;
	DWORD sizeofInstalled = sizeof(installed);

	ErrorCode = RegQueryValueEx(
		GameKey,
		"Installed",
		NULL, // Reserved
		&KeyType,
		(LPBYTE)& installed,
		&sizeofInstalled
	);

	if (ErrorCode != ERROR_SUCCESS) {
		LOGE("ERROR: Failed to query " << TO_STRING(appid) << "'s value. WinAPI error code: " + TO_STRING(ErrorCode));
	}

	if (installed != true) {
		LOGW("WARNING: " << gameName << " is not installed!");
		return "";
	}

	RegCloseKey(GameKey);

	
	//
	// Get steam install dir
	//

	String steamInstallDir = "<UNKNOWN>";

	HKEY SteamDirKey = NULL;

	ErrorCode = RegOpenKeyEx(
		HKEY_CURRENT_USER,
		"Software\\Valve\\Steam",
		NULL, // 1 if the key is a symbolic link
		KEY_QUERY_VALUE,
		&SteamDirKey	// Return Key
	);

	if (ErrorCode != ERROR_SUCCESS) {
		LOGE("ERROR: Failed to open Steam Dir Registry Key, WinAPI error code: " << TO_STRING(ErrorCode));
	}

	if (SteamDirKey == NULL) {
		LOGE("ERROR: The SteamDIR registry key was null!");
	}

	char* SteamDIR = new char[MAX_PATH];
	DWORD maxPathVar = MAX_PATH;

	ErrorCode = RegQueryValueEx(
		SteamDirKey,
		"SteamPath",
		NULL, // Reserved
		&KeyType,
		(LPBYTE)SteamDIR,
		&maxPathVar
	);

	if (ErrorCode != ERROR_SUCCESS) {
		LOGE("ERROR: Failed to query Steam Dir Registry Key, WinAPI error code: " << TO_STRING(ErrorCode));
	}

	if (KeyType != REG_SZ) {
		LOGE("ERROR: Steam path should be type REG_SZ, instead got: " << "0x" << std::hex << KeyType);
	}

	RegCloseKey(SteamDirKey);

	steamInstallDir = SteamDIR;

	String ConfigDir = steamInstallDir + "/steamapps/libraryfolders.vdf";

	std::vector<String> SteamInstallDirs;
	SteamInstallDirs.push_back(convertUnixPathToWindows(steamInstallDir));

	//
	// Read config file for steam dirs
	//

	std::ifstream infile(ConfigDir);

	std::string line;
	while (std::getline(infile, line)) { // Loops over file line by line

		// Get position of all quotes

		std::vector<u32> QuoteIndexes;

		for (u32 i = 0; i < line.length(); i++) {

			if (line[i] == '"') {
				QuoteIndexes.push_back(i);
			}

		}

		if (QuoteIndexes.size() != 4) {
			continue;
		}

		String key = line.substr((QuoteIndexes[0] + 1), (QuoteIndexes[1] - 2));
		String value = line.substr((QuoteIndexes[2] + 1), (QuoteIndexes[3] - 2));

		bool isNumeric = true;

		// All drive values are numeric
		for (int d = 0; d < key.size(); d++) {
			if (!isdigit(key[d])) {
				isNumeric = false;
				break;
			}
		}

		if (isNumeric == false) {
			continue;
		}

		// I have no clue why, but the last quote always gets included in value

		value = value.substr(0, (value.size() - 1));

		SteamInstallDirs.push_back(value);

	}

	//
	// Scan for the game in the directories
	//

	String GameDirectory = "";

	for (int i = 0; i < SteamInstallDirs.size(); i++) {

		SteamInstallDirs[i] += "\\steamapps\\common\\" + gameName;

		BOOL ReturnCode = GetFileAttributes(SteamInstallDirs[i].c_str());

		if (ReturnCode == INVALID_FILE_ATTRIBUTES) {
			continue;
		}

		if (ReturnCode & FILE_ATTRIBUTE_DIRECTORY) {
			GameDirectory = SteamInstallDirs[i].c_str();
			break;
		}

	}

	if (GameDirectory == "") {
		LOGW("WARNING: " << gameName << "'s directory not found!");
		return "";
	}

	return GameDirectory;

}
