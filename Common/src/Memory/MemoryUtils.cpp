#include "Memory/MemoryUtils.hpp"

void WindowsMemory::Initialise(HANDLE ProcHandle, HMODULE ModHandle) {
	Hproc = ProcHandle;
	Hmod = ModHandle;
}

u32 WindowsMemory::OffsetFromMod(u32 offset) {
	return (u32)(Hmod) + offset;
}

u64 WindowsMemory::OffsetFromMod(u64 offset) {
	return (u64)(Hmod) + offset;
}

u32 WindowsMemory::PtrFromMod(u32 offset) {
	u32 BaseAddr = (u32)(Hmod)+offset;
	return Deref(BaseAddr);
}

u64 WindowsMemory::PtrFromMod(u64 offset) {
	u64 BaseAddr = (u64)(Hmod)+offset;
	return Deref(BaseAddr);
}

void WindowsMemory::ReadMemory(u64 Addr, u8* Buffer, u64 Len) {
	if (ReadProcessMemory(
		Hproc,
		(void*)Addr,
		Buffer,
		Len,
		NULL
	) == 0) {
		u32 error = GetLastError();
		if (error == ERROR_PARTIAL_COPY) {
			LOGW("WARNING: ReadProcessMemory errored: Partial copy occured (0x12b)\n" <<
			"You're likely reading from unacessable memory");
		}
		else {
			LOGW("WARNING: ReadProcessMemory errored! WinAPI error code 0x" << std::hex << error);
		}
		
	}
}

void WindowsMemory::Read(u32 Addr, u32* Ret) {
	ReadMemory(Addr, (u8*)Ret, sizeof(u32));
}

void WindowsMemory::Read(u64 Addr, u64* Ret) {
	ReadMemory(Addr, (u8*)Ret, sizeof(u64));
}

u32 WindowsMemory::Deref(u32 Addr) {
	u32 buf;
	Read(Addr, &buf);
	return buf;
}

u32 WindowsMemory::Deref(u32* Addr) {
	u32 buf;
	Read((u32)Addr, &buf);
	return buf;
}

u64 WindowsMemory::Deref(u64 Addr) {
	u64 buf;
	Read(Addr, &buf);
	return buf;
}

u64 WindowsMemory::Deref(u64* Addr) {
	u64 buf;
	Read((u64)Addr, &buf);
	return buf;
}

TL32 WindowsMemory::MultiLevelPtr(u32 BasePtr, std::vector<u32> Offsets) {

	u32 WorkingPtr = BasePtr;

	for (u8 i = 0; i < Offsets.size(); i++) {
		WorkingPtr = Deref(WorkingPtr + Offsets[i]);
	}

	return (TL32)WorkingPtr;
	
}

TL64 WindowsMemory::MultiLevelPtr(u64 BasePtr, std::vector<u64> Offsets) {

	u64 WorkingPtr = BasePtr;

	for (u8 i = 0; i < Offsets.size(); i++) {
		WorkingPtr = Deref(WorkingPtr + Offsets[i]);
	}

	return (TL64)WorkingPtr;

}