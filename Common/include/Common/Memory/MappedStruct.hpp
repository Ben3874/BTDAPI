#pragma once
#include "Core/core.hpp"
#include "MemoryUtils.hpp"


// :( More templates, all code has to be in the header
template<class SizeT>
class MappedStruct {

public:
	SizeT StructAddr;
	WindowsMemory* procMem;

	MappedStruct(u32 Addr, WindowsMemory* memory) {
		StructAddr = Addr;
		procMem = memory;
	}

protected:
	SizeT ReadOffsetField(SizeT Offset) {
		SizeT ret;
		procMem->Read((SizeT)StructAddr + Offset, &ret);
		return ret;
	}

	void WriteOffsetField(SizeT Offset, SizeT* bytes) {
		procMem->Write((SizeT)(StructAddr)+Offset, (SizeT*)bytes);
	}

	// Ptr to a buffer.
	void ReadOffsetAggregate(SizeT Offset, void* Buffer) {
		procMem->Read((SizeT)StructAddr + Offset, (SizeT*)Buffer);
	}

	void WriteOffsetAggregate(SizeT Offset, void* Bytes) {
		procMem->Write((SizeT)(StructAddr)+Offset, (SizeT*)Bytes);
	}

};