#pragma once
//
// This should be a normally accessable vector that uses MemUtils
// PLEASE NOTE: THIS IS NOT A FULL IMPLEMENTATION OF VECTOR
// THESE ARE JUST THE USEFUL PARTS OF IT
//


template<typename SizeT, typename T>
class MappedVector {

public:
	SizeT FirstPtr;
	SizeT LastPtr;

	MappedVector(SizeT firstPtr, SizeT lastPtr) {
		FirstPtr = firstPtr;
		LastPtr = lastPtr;
	};

	MappedVector(SizeT* firstPtr, SizeT* lastPtr) {
		FirstPtr = (SizeT)(firstPtr);
		LastPtr = (SizeT)(lastPtr);
	};

	SizeT operator[](SizeT Index) {
		SizeT First = Deref(FirstPtr);
		return Deref(First + (Index * sizeof(SizeT)));
	};

	SizeT size() {
		SizeT First = Deref(FirstPtr);
		SizeT LastPtr = Deref(LastPtr);
		return (LastPtr - FirstPtr) / sizeof(SizeT);
	}

};