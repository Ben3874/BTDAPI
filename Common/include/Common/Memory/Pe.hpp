#pragma once
#include "Core/core.hpp"
//
// Windows DLL's are the only ones supported as of now.
//


#define IMAGE_NT_PEHEADER_SIGNATURE 0x4550


// RVA = VA - ImageBase
// VA = RVA + Image base

// Releative Virtual Address = RVA
// Virtual Address = VA


//
// Addresses are stored as VA's/RVA's on a file, however these are the addresses once loaded into memory
// This is used to get the actual location of said addresses.
//
DLL_PRIVATE u64 RVAtoOffset(DWORD rva, _IMAGE_NT_HEADERS64& ntHeaders);

DLL_PRIVATE inline u64 VAtoOffset(DWORD va, _IMAGE_NT_HEADERS64& ntHeaders);

DLL_PRIVATE PIMAGE_NT_HEADERS64 GetNTHeaders();

// When the PBYTE is loaded in memory. Alternative to GetProcAddress()
DLL_PRIVATE void Memory64DumpExports(std::map<String, u64>& ret, u8* peFile);


// For Hooking in BTD5/B

DLL_PRIVATE void File32AddToImportTable(std::vector<std::pair<std::string, u32>> TableEntries);

// Takes the exports of a DLL and makes another dllImport them.
DLL_PRIVATE void FileAddExportsToImports32(u8* pBinExports, u8* pBinImports);
