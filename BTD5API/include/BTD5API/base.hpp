#pragma once
#include "Memory/Memory.hpp"
#include "bloons.hpp"


template<class T>
using Btd5Vec = MappedPtrVec<T, u32>;

using Btd5Vec2 = Vec2d<float>;


class BTD5API {

public:

	static WindowsMemory* mem;

	Btd5Vec<Bloon> BloonList;

	DLL_PUBLIC void Initialise(WindowsMemory *memory);

};
