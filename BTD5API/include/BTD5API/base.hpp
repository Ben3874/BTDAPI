#pragma once
#include "Memory/Memory.hpp"
#include "Global.hpp"
#include "bloons.hpp"

class BTD5API {

public:

	Btd5Vec<Bloon> BloonList;

	DLL_PUBLIC void Initialise(WindowsMemory *memory);

};



