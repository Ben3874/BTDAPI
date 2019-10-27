#pragma once
#include "Core/core.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#define BTD6PROCNAME "BloonsTD6.exe"
#define BTD5PROCNAME "BTD5-Win.exe"

class LoadMemory {
public:
	static HANDLE GetProcessPointer(String procName);
	static HMODULE GetModulePointer(HANDLE ProcessHandle, String moduleName);

};