#pragma once

#include "core/core.hpp"
#include "Memory/memory.hpp"
#include "base.hpp"

#define OFF_STRUCT(name, members) union { members } name



enum BloonTypes : u32
{
	BLOON_NULL = 0b0000'0000'0000'0000'0000'0000'0000'0000,
	BLOON_TEST_BLOON = 0b0000'0000'0000'0000'0000'0000'0000'0001,
	BLOON_RED = 0b0000'0000'0000'0000'0000'0000'0000'0010,
	BLOON_BLUE = 0b0000'0000'0000'0000'0000'0000'0000'0100,
	BLOON_GREEN = 0b0000'0000'0000'0000'0000'0000'0000'1000,
	BLOON_YELLOW = 0b0000'0000'0000'0000'0000'0000'0001'0000,
	BLOON_PINK = 0b0000'0000'0000'0000'0000'0000'0010'0000,
	BLOON_BLACK = 0b0000'0000'0000'0000'0000'0000'0100'0000,
	BLOON_WHITE = 0b0000'0000'0000'0000'0000'0000'1000'0000,
	BLOON_LEAD = 0b0000'0000'0000'0000'0000'0001'0000'0000,
	BLOON_ZEBRA = 0b0000'0000'0000'0000'0000'0010'0000'0000,
	BLOON_RAINBOW = 0b0000'0000'0000'0000'0000'0100'0000'0000,
	BLOON_CERAMIC = 0b0000'0000'0000'0000'0000'1000'0000'0000,
	BLOON_UNKNOWN = 0b0000'0000'0000'0000'0001'0000'0000'0000,    // Probably gold bloon
	BLOON_MOAB = 0b0000'0000'0000'0000'0010'0000'0000'0000,
	BLOON_BFB = 0b0000'0000'0000'0000'0100'0000'0000'0000,
	BLOON_ZOMG = 0b0000'0000'0000'0000'1000'0000'0000'0000
	// TODO: Boss bloons
};

class BloonType {
	char* Name;
	char* SpriteSheet;


};





class Bloon {

	//
	// Known Offets for Bloons:
	//
	// 0xA0		- SpriteX
	// 0xA4		- SpriteY
	// 0x1FC	- BloonType
	// 0x26C	- Distance on track
	// 0x278	- PosX
	// 0x27C	- PosY
	//

private:

	u32 BloonAddr;

public:

	Bloon(u32 Ptr);

	void SetSpriteX(float x);
	float GetSpriteX();

	void SetSpriteY(float y);
	float GetSpriteY();

	void SetBloonTypePtr(BloonType* ptr);
	BloonType GetBloonType();

	void SetDistanceOnTrack(float dist);
	float GetDistanceOnTrack();

	void SetPosX(float x);
	float GetPosX();

	void SetPosY(float y);
	float GetPosY();

public:

	__declspec(property(get = GetSPriteX, put = SetSpriteX)) float spriteX;
	__declspec(property(get = GetSpriteY, put = SetSpriteY)) float spriteY;
	__declspec(property(get = GetBloonType, put = SetBloonTypePtr)) BloonType bloonType;
	__declspec(property(get = GetDistanceOnTrack, put = SetDistanceOnTrack)) float Distance;
	__declspec(property(get = GetPosX, put = SetPosX)) float PosX;
	__declspec(property(get = GetPosY, put = GetPosY)) float PosY;


};






