#pragma once 
#include "Core/core.hpp"
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef uint32 IntPtr;
typedef uint64 LongPtr;



//
// Why not use templates???
// Because you can use <T> in the .cpp files
//
class WindowsMemory {
public:
	DLL_PUBLIC WindowsMemory(HANDLE hproc, HMODULE hmod);

	DLL_PUBLIC uint32 DerefIntPointer(IntPtr ptr);
	DLL_PUBLIC uint64 DerefLongPointer(LongPtr ptr);

	DLL_PUBLIC uint32 DerefIntPointerChain(IntPtr ptr, std::vector<IntPtr> Offsets);
	DLL_PUBLIC uint64 DerefLongPointerChain(LongPtr ptr, std::vector<LongPtr> Offsets);

	// Pointer chain from 
	DLL_PUBLIC uint32 IntChainFromOffset(IntPtr offset, std::vector<IntPtr> Offsets);
	DLL_PUBLIC uint64 LongChainFromOffset(LongPtr offset, std::vector<LongPtr> Offsets);

	DLL_PUBLIC uint32 Read4Bytes(IntPtr addr);
	DLL_PUBLIC uint64 Read8Bytes(LongPtr addr);



private:
	HANDLE ProcHandle;
	HMODULE ModHandle;

	inline void ReadMemory(LongPtr addr, void* buff, uint64 buffSize);


};