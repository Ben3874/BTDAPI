#include "Memory/MemoryUtils.hpp"

WindowsMemory::WindowsMemory(HANDLE ProcHandle, HMODULE ModHandle) {
	Hproc = ProcHandle;
	Hmod = ModHandle;
}

u32 WindowsMemory::OffsetFromMod(u32 offset) {
	return (u32)(Hmod) + offset;
}

u64 WindowsMemory::OffsetFromMod(u64 offset) {
	return (u64)(Hmod) + offset;
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
		LOGW("WARNING: ReadProcessMemory errored! WinAPI error code 0x" << std::hex << error);
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