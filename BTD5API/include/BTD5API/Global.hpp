#pragma once
#include "core/core.hpp"
#include "memory/memory.hpp"

// Global types

template<class T>
using Btd5Vec = MappedPtrVec<T, u32>;
using Btd5Vec2 = Vec2d<float>;
using Btd5Struct = MappedStruct<u32>;

//WindowsMemory* BTD5mem;
class BTD5 {
public:
	static WindowsMemory* mem;
};



// To make it easier to change shit argh...
// Dont smite me plz
#define MEMNAME BTD5::mem


