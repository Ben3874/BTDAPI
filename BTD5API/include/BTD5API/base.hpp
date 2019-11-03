#pragma once
#include "Memory/Memory.hpp"
#include "bloons.hpp"


template<class T>
using Btd5Vec = MappedPtrVec<T, u32>;


// The static memory used for all calls in the API.

class BTD5API {

private:
	static WindowsMemory mem;

	void setBloonList(Btd5Vec<Bloon>* ptr);
	Btd5Vec<Bloon> getBloonList();

public:

	__declspec(property(get = getBloonList, put = setBloonList)) Btd5Vec<Bloon> BloonList;

	__declspec(property(get = GetSPriteX, put = SetSpriteX)) float spriteX;

};
