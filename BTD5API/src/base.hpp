#pragma once
#include "Memory/Memory.hpp"
#include "bloons.hpp"


template<typename T>
using Btd5Vec = MappedVector<T, u32>;


// The static memory used for all calls in the API.

class BTD5API {

private:
	static WindowsMemory mem;

	Btd5Vec<Bloon> getBloonList();
	void setBloonList(Btd5Vec<Bloon>);

public:

	__declspec(property(get = getBloonList, put = setBloonList)) Btd5Vec<Bloon> BloonList;

};
