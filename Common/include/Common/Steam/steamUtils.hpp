#pragma once
#include "Core/core.hpp"

#define BTD6AppId	960090
#define BTD6Name	"BloonsTD6"


class SteamUtils {
public:

	DLL_PUBLIC static String WindowsGetGameDirectory(uint64 appid, std::string gameName);

private:

	static String convertUnixPathToWindows(String unixPath);


};