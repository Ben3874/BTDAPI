#pragma once

#include "core/core.hpp"
#include "Memory/memory.hpp"

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

	enum Offsets {
		OFF_FIELD_SPRITEX = 0xA0,
		OFF_FIELD_SPRITEY = 0xA4,
		OFF_FIELD_BLOONTYPE = 0x1FC,
		OFF_FIELD_DISTANCE = 0x26c,
		OFF_FIELD_POSX = 0x278,
		OFF_FIELD_POSY = 0x27c
	};

private:

	
	static WindowsMemory* mem;

	DLL_PRIVATE inline u32 ReadOffsetField(u32 Offset);

public:

	// READONLY. DO NOT SET!
	u32 BloonAddr;

	DLL_PUBLIC void SetSpriteX(float x);
	DLL_PUBLIC float GetSpriteX();

	DLL_PUBLIC void SetSpriteY(float y);
	DLL_PUBLIC float GetSpriteY();

	DLL_PUBLIC void SetBloonTypePtr(BloonType* ptr);
	DLL_PUBLIC BloonType GetBloonType();

	DLL_PUBLIC void SetDistanceOnTrack(float dist);
	DLL_PUBLIC float GetDistanceOnTrack();

	DLL_PUBLIC void SetPosX(float x);
	DLL_PUBLIC float GetPosX();

	DLL_PUBLIC void SetPosY(float y);
	DLL_PUBLIC float GetPosY();

	DLL_PUBLIC Bloon(u32 Ptr);
	DLL_PUBLIC void SetMem(WindowsMemory* mem);
	

	__declspec(property(get = GetSpriteX, put = SetSpriteX)) float spriteX;
	__declspec(property(get = GetSpriteY, put = SetSpriteY)) float spriteY;
	__declspec(property(get = GetBloonType, put = SetBloonTypePtr)) BloonType bloonType;
	__declspec(property(get = GetDistanceOnTrack, put = SetDistanceOnTrack)) float Distance;
	__declspec(property(get = GetPosX, put = SetPosX)) float PosX;
	__declspec(property(get = GetPosY, put = GetPosY)) float PosY;


};






