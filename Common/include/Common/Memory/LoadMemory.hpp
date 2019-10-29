#pragma once
#include "Core/core.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define BTD6PROCNAME "BloonsTD6.exe"
#define BTD5PROCNAME "BTD5-Win.exe"
#define BTDBPROCNAME "Battles-Win.exe"

class LoadMemory {
public:
	DLL_PUBLIC static HANDLE GetProcessPointer(String procName);
	DLL_PUBLIC static HMODULE GetModulePointer(HANDLE ProcessHandle, String moduleName);

};