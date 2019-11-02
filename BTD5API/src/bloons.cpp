#include "bloons.hpp"


Bloon::Bloon(u32 Ptr) {
	BloonPtr = Ptr;
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
	BloonType NulLType;
	return NulLType;
}

// 0x26C

void Bloon::SetDistanceOnTrack(float dist) {
	LOGW("WARNING: SetDistanceOnTrack not yet implemented!");
}

float Bloon::GetDistanceOnTrack() {
	LOGW("WARNING: GetDistanceOnTrack not yet implemented!");
	return 0;
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