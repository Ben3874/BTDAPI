#pragma once
#include "Core/core.hpp"

#define BTD6PROCNAME "BloonsTD6.exe"
#define BTD5PROCNAME "BTD5-Win.exe"
#define BTDBPROCNAME "Battles-Win.exe"

class LoadMemory {
public:
	DLL_PUBLIC static HANDLE GetProcessPointer(String procName);
	DLL_PUBLIC static HMODULE GetModulePointer(HANDLE ProcessHandle, String moduleName);

};