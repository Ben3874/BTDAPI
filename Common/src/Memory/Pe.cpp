#include "Memory/Pe.hpp"

DLL_PRIVATE u64 RVAtoOffset(DWORD rva, _IMAGE_NT_HEADERS64& ntHeaders) {

	PIMAGE_SECTION_HEADER secTables = IMAGE_FIRST_SECTION(&ntHeaders);

	for (int i = 0; i < ntHeaders.FileHeader.NumberOfSections; i++) {

		PIMAGE_SECTION_HEADER secHdr = reinterpret_cast<PIMAGE_SECTION_HEADER>(&secTables[i]);

		if (secHdr->VirtualAddress <= rva && rva < secHdr->VirtualAddress + secHdr->Misc.VirtualSize) {

			return static_cast<u64>(rva) + secHdr->PointerToRawData - secHdr->VirtualAddress;
		}
	}

	LOGE("ERROR: Failed to covert RVA to offset. RVA: 0x" << std::hex << rva);

}

DLL_PRIVATE inline u64 VAtoOffset(DWORD va, _IMAGE_NT_HEADERS64& ntHeaders) {

	DWORD rva = va - ntHeaders.OptionalHeader.ImageBase;

	return RVAtoOffset(rva, ntHeaders);

}



DLL_PRIVATE void Memory64DumpExports(std::map<String, u64>& ret, u8* peFile) {

	PIMAGE_DOS_HEADER dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(peFile);


	if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE) {
		LOGE("ERROR: File provided was not PE!");
	}

	PIMAGE_NT_HEADERS64 ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS64>(peFile + dosHeader->e_lfanew);

	if (ntHeaders->Signature != IMAGE_NT_PEHEADER_SIGNATURE) {
		LOGE("ERROR: File provided was an invalid PE file")
	}

	if (ntHeaders->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
		LOGI("INFO: Dumping exports of 64 bit DLL...");
	}
	else if (ntHeaders->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC) {
		LOGI("INFO: Dumping exports of 32 bit DLL..");
	}
	else {
		LOGE("ERROR: Header magic is invalid!");
	}

	PIMAGE_EXPORT_DIRECTORY exportDir =
		reinterpret_cast<PIMAGE_EXPORT_DIRECTORY>(peFile +
			ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);

	if (ntHeaders->OptionalHeader.NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_EXPORT) {
		//There will be no exports here.
		LOGW("WARNING: No exports detected!");
		return;
	}


	for (int i = 0; i < exportDir->NumberOfNames; i++) {

		DWORD rva = (*reinterpret_cast<PDWORD>(peFile +
			exportDir->AddressOfFunctions + i * sizeof(rva)));

		DWORD namePointer = exportDir->AddressOfNames + (i * sizeof(namePointer));

		std::string methodName = std::string(reinterpret_cast<char*>
			(peFile + (*reinterpret_cast<PDWORD>(peFile + namePointer))));

		std::string xethodName = std::string((char*)
			(peFile + (*(DWORD*)(peFile + namePointer))));

		ret.insert(std::pair <std::string, uint64_t>(methodName, rva));

	}

}

DLL_PRIVATE void FileAddExportsToImports32(u8* pBinExports, u8* pBinImports) {

	// First get all the Exports (Offset, )


}
