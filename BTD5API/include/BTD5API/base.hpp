#pragma once
#include "Memory/Memory.hpp"
#include "bloons.hpp"


template<class T>
using Btd5Vec = MappedPtrVec<T, u32>;


// The static memory used for all calls in the API.

class BTD5API {

private:
	WindowsMemory* mem;

public:

	Btd5Vec<Bloon> BloonList;

	DLL_PUBLIC void Initialise(WindowsMemory *memory);

};
