#pragma once
//
// This should be a normally accessable vector that uses MemUtils
// PLEASE NOTE: THIS IS NOT A FULL IMPLEMENTATION OF VECTOR
// THESE ARE JUST THE PARTS I USE
//


template<typename T, typename SizeT>
class MappedVector {

private:
	struct VectorInternals {
		SizeT FirstPtr;
		SizeT LastPtr;
		SizeT MaxPtr; // Max value vector can hold before reallocating.
	} VecMap;

	inline SizeT MaxSize() {
		return (ProcMem->Deref(VecMap.FirstPtr)) - (ProcMem->Deref(VecMap.MaxPtr)) / sizeof(SizeT);
	}

public:

	WindowsMemory* ProcMem;
	

	MappedVector(SizeT addr, WindowsMemory* Mem) {
		ProcMem = Mem;
		ProcMem->ReadMemory(addr, (u8*)&VecMap, sizeof(VecMap));
	};

	MappedVector(SizeT* addr, WindowsMemory* Mem) {
		ProcMem = Mem;
		ProcMem->ReadMemory((SizeT)addr, (u8*)&VecMap, sizeof(VecMap));
	};

	T operator[](SizeT Index) {
		SizeT First = ProcMem->Deref(VecMap.FirstPtr);
		return ProcMem->Deref(First + (Index * sizeof(T)));
	};

	SizeT size() {
		SizeT First = ProcMem->Deref(VecMap.FirstPtr);
		SizeT Last = ProcMem->Deref(VecMap.LastPtr);
		return (First - Last) / sizeof(SizeT);
	}

	SizeT data() {
		return ProcMem->Deref(VecMap.FirstPtr);
	}

	void Push_Back(T data) {
		SizeT Size = size();
		
	}

};