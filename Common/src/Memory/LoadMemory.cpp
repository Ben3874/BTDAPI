#include "Core/core.hpp"
#include <vector>
#include "Memory/memory.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Psapi.h>
#include <tchar.h>

HANDLE LoadMemory::GetProcessPointer(String procName) {

	// Enumerate all proccesses

	std::vector<DWORD> ProcIds;
	DWORD ProcIdsSize = 0;
	DWORD bytesNeeded = 0;

	while (bytesNeeded / sizeof(DWORD) == ProcIdsSize) {
		ProcIdsSize += 512;

		ProcIds = std::vector<DWORD>(ProcIdsSize);

		if (EnumProcesses(
			ProcIds.data(),
			ProcIdsSize * sizeof(DWORD),
			&bytesNeeded
		) == 0) {
			DWORD ErrorCode = GetLastError();
			LOGE("ERROR: Failed to enumerate processes. WinAPI error code: " << TO_STRING(ErrorCode));
		}

	}

	// Now loop over them

	for (int i = 0; i < bytesNeeded / sizeof(DWORD); i++) {
		
		// This is the default value for unaccessable proccesses anyway.
		TCHAR ProcName[MAX_PATH] = TEXT("<unknown>");

		HANDLE hproc = OpenProcess(
			PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_OPERATION,
			FALSE, // Do not inherit handle
			ProcIds[i]
		);

		if (hproc != NULL) {
			GetModuleBaseName(
				hproc,
				NULL, // Base = Name of exe
				ProcName,
				MAX_PATH
			);
		}

		std::basic_string<TCHAR> ProcNameStr = ProcName;

		if (ProcNameStr == procName) {
			if (hproc != NULL) {
				CloseHandle(hproc);

				hproc = OpenProcess(
					PROCESS_ALL_ACCESS,
					FALSE, // Do not inherit handle
					ProcIds[i]
				);

				if (hproc == NULL) {
					DWORD error = GetLastError();
					LOGW("WARNING: Could not open BTD game with all rights. WinAPI error code: " << error);
				}

				return hproc;
			}
		}
	}
	
	//LOGW("WARNING: " << procName << " not found!");

	return INVALID_HANDLE_VALUE;
}

HMODULE LoadMemory::GetModulePointer(HANDLE HProc, String moduleName) {
	
	// Enumerate all modules

	std::vector<HMODULE> Modules;
	DWORD ModulesSize = 0;
	DWORD bytesNeeded = 0;

	while (bytesNeeded / sizeof(DWORD) == ModulesSize) {
		ModulesSize += 512;

		Modules = std::vector<HMODULE>(ModulesSize);

		if (EnumProcessModules(
			HProc,
			Modules.data(),
			ModulesSize * sizeof(DWORD),
			&bytesNeeded
		) == 0) {
			DWORD ErrorCode = GetLastError();
			LOGE("ERROR: Failed to enumerate modules. WinAPI error code: " << TO_STRING(ErrorCode));
		}

	}

	// This is the default value for unaccessable modules anyway.
	TCHAR ModName[MAX_PATH] = TEXT("<unknown>");

	for (int i = 0; i < bytesNeeded / sizeof(HMODULE); i++) {

		GetModuleBaseName(
			HProc,
			Modules[i],
			ModName,
			MAX_PATH
		);

		std::basic_string<TCHAR> ModNameStr = ModName;

		if (ModNameStr == moduleName) {
			return Modules[i];
		}

	}

	LOGW("WARNING: " << moduleName << " to process not found");
	return NULL;
}