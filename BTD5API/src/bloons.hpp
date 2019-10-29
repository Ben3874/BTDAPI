#pragma once
#include "core/core.hpp"
#include "Memory/memory.hpp"


enum BloonTypes : u32
{
	BLOON_NULL =		0b0000'0000'0000'0000'0000'0000'0000'0000,
	BLOON_TEST_BLOON =	0b0000'0000'0000'0000'0000'0000'0000'0001,
	BLOON_RED =			0b0000'0000'0000'0000'0000'0000'0000'0010,
	BLOON_BLUE =		0b0000'0000'0000'0000'0000'0000'0000'0100,
	BLOON_GREEN =		0b0000'0000'0000'0000'0000'0000'0000'1000,
	BLOON_YELLOW =		0b0000'0000'0000'0000'0000'0000'0001'0000,
	BLOON_PINK =		0b0000'0000'0000'0000'0000'0000'0010'0000,
	BLOON_BLACK =		0b0000'0000'0000'0000'0000'0000'0100'0000,
	BLOON_WHITE =		0b0000'0000'0000'0000'0000'0000'1000'0000,
	BLOON_LEAD =		0b0000'0000'0000'0000'0000'0001'0000'0000,
	BLOON_ZEBRA =		0b0000'0000'0000'0000'0000'0010'0000'0000,
	BLOON_RAINBOW =		0b0000'0000'0000'0000'0000'0100'0000'0000,
	BLOON_CERAMIC =		0b0000'0000'0000'0000'0000'1000'0000'0000,
	BLOON_UNKNOWN =		0b0000'0000'0000'0000'0001'0000'0000'0000,    // Probably gold bloon
	BLOON_MOAB =		0b0000'0000'0000'0000'0010'0000'0000'0000,
	BLOON_BFB =			0b0000'0000'0000'0000'0100'0000'0000'0000,
	BLOON_ZOMG =		0b0000'0000'0000'0000'1000'0000'0000'0000,
	// TODO: Boss bloons
}

struct BloonType {
	char* Name;
	char* SpriteSheet;


};

struct Bloon {

	u64 Unknown;

};

