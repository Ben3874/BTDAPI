#include "BTD5API/api.hpp"

WindowsMemory* Bloon::mem;

Bloon::Bloon(u32 Ptr) {
	BloonAddr = Ptr;
}

void Bloon::SetMem(WindowsMemory* memory) {
	mem = memory;
}

u32 Bloon::ReadOffsetField(u32 Offset) {
	u32 ret;
	mem->Read((u32)BloonAddr + Offset, &ret);
	return ret;
}

// 0xA0

void Bloon::SetSpriteX(float x) {
	LOGW("WARNING: SetSpriteX not yet implemented!");
}

float Bloon::GetSpriteX(){
	u32 floatBytes = ReadOffsetField(OFF_FIELD_SPRITEX);
	float SpriteX = reinterpret_cast<float&>(floatBytes);
	return SpriteX;
}

// 0xA4

void Bloon::SetSpriteY(float y) {
	LOGW("WARNING: SetSpriteY not yet implemented!");
}

float Bloon::GetSpriteY() {
	u32 floatBytes = ReadOffsetField(OFF_FIELD_SPRITEY);
	float SpriteY = reinterpret_cast<float&>(floatBytes);
	return SpriteY;
}

//0x1FC

void Bloon::SetBloonTypePtr(BloonType* ptr) {
	LOGW("WARNING: SetBloonTypePtr not yet implemented!");
}

BloonType Bloon::GetBloonType() {
	LOGW("WARNING: GetBloonType not yet implemented!");
	BloonType NullType;
	return NullType;
}

// 0x26C

void Bloon::SetDistanceOnTrack(float dist) {
	LOGW("WARNING: SetDistanceOnTrack not yet implemented!");
}

float Bloon::GetDistanceOnTrack() {
	u32 DistBytes = ReadOffsetField(OFF_FIELD_DISTANCE);
	float Distance = reinterpret_cast<float&>(DistBytes);
	
	return Distance;
}

// 0x278

void Bloon::SetPosX(float x) {
	LOGW("WARNING: SetPosX not yet implemented!");
}

float Bloon::GetPosX() {
	u32 FloatBytes = ReadOffsetField(OFF_FIELD_SPRITEX);
	float PosX = reinterpret_cast<float&>(FloatBytes);
	return PosX;
}

// 0x26C

void Bloon::SetPosY(float y) {
	LOGW("WARNING: SetPosY not yet implemented!");
}

float Bloon::GetPosY() {
	u32 FloatBytes = ReadOffsetField(OFF_FIELD_SPRITEY);
	float PosY = reinterpret_cast<float&>(FloatBytes);
	return PosY;
}