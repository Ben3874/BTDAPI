#include "BTD5API/api.hpp"

WindowsMemory* Bloon::mem;

Bloon::Bloon(u32 Ptr) {
	BloonAddr = Ptr;
}

void Bloon::SetMem(WindowsMemory* memory) {
	mem = memory;
}

// 0xA0

void Bloon::SetSpriteX(float x) {
	LOGW("WARNING: SetSpriteX not yet implemented!");
}

float Bloon::GetSpriteX(){
	LOGW("WARNING: GetSpriteX not yet implemented!");
	return 0;
}

// 0xA4

void Bloon::SetSpriteY(float y) {
	LOGW("WARNING: SetSpriteY not yet implemented!");
}

float Bloon::GetSpriteY() {
	LOGW("WARNING: GetSpriteY not yet implemented!");
	return 0;
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
	//	u32 Dist = (u32)BTD5.MultiLevelPtr(BaseAddr, OffsetList);
//	float dis1 = reinterpret_cast<float&>(Dist);

	u32 DistBytes;
	mem->Read(BloonAddr + (u32)0x26c, &DistBytes);
	float Distance = reinterpret_cast<float&>(DistBytes);
	
	return Distance;
}

// 0x278

void Bloon::SetPosX(float x) {
	LOGW("WARNING: SetPosX not yet implemented!");
}

float Bloon::GetPosX() {
	LOGW("WARNING: SetPosX not yet implemented!");
	return 0;
}

// 0x26C

void Bloon::SetPosY(float y) {
	LOGW("WARNING: SetPosY not yet implemented!");
}

float Bloon::GetPosY() {
	LOGW("WARNING: GetPosY not yet implemented!");
	return 0;
}