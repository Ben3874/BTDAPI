#pragma once
//
// This should be a normally accessable vector that uses MemUtils
// PLEASE NOTE: THIS IS NOT A FULL IMPLEMENTATION OF VECTOR
// THESE ARE JUST THE PARTS I USE
//

// A vector that automaticaly derefs pointers
template<class T, typename SizeT>
class MappedPtrVec {

private:
	struct ListInternals {
		SizeT FirstPtr;
		SizeT LastPtr;
		SizeT MaxPtr; // Max value vector can hold before reallocating.
	} VecMap;

	inline SizeT MaxSize() {
		return (ProcMem->Deref(VecMap.FirstPtr)) - (ProcMem->Deref(VecMap.MaxPtr)) / sizeof(SizeT);
	}

public:

	WindowsMemory* ProcMem;

	DLL_PUBLIC void Map(SizeT addr, WindowsMemory* Mem) {
		ProcMem = Mem;
		VecMap.FirstPtr = addr;
		VecMap.LastPtr = addr + (u32)0x4;
		VecMap.MaxPtr = addr + (u32)0x8;
	}

	DLL_PUBLIC void Map(SizeT* addr, WindowsMemory* Mem) {
		ProcMem = Mem;
		ProcMem->ReadMemory((SizeT)addr, (u8*)(& VecMap), sizeof(VecMap));
	}

	DLL_PUBLIC T operator[](SizeT Index) {
		SizeT First = ProcMem->Deref(VecMap.FirstPtr);
		T t = (T(ProcMem->Deref(First + (Index * sizeof(T)))));
		return t;
	};

	DLL_PUBLIC SizeT size() {
		SizeT First = ProcMem->Deref(VecMap.FirstPtr);
		SizeT Last = ProcMem->Deref(VecMap.LastPtr);
		return ((Last - First) / sizeof(SizeT));
	}

	DLL_PUBLIC SizeT data() {
		return ProcMem->Deref(VecMap.FirstPtr);
	}

	DLL_PUBLIC void Push_Back(T data) {
		SizeT Size = size();
		
	}

};