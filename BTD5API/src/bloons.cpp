#include "BTD5API/api.hpp"
#include "BTD5API/bloons.hpp"
//
// Bloon Type
//

BloonTypes BloonType::GetType() {
	return (BloonTypes)ReadOffsetField(OFF_FIELD_TYPE);
}

void BloonType::SetType(BloonTypes type) {
	LOGW("WARNING: Set type not implemented yet!");
}

String BloonType::GetNameFromType(BloonTypes bloon) {

	switch (bloon) {

	case BLOON_TEST_BLOON:
		return "Test";
		break;

	case BLOON_RED:
		return "Red";
		break;

	case BLOON_BLUE:
		return "Blue";
		break;

	case BLOON_GREEN:
		return "Green";
		break;

	case BLOON_YELLOW:
		return "Yellow";
		break;

	case BLOON_PINK:
		return "Pink";
		break;

	case BLOON_BLACK:
		return "Black";
		break;

	case BLOON_WHITE:
		return "White";
		break;

	case BLOON_LEAD:
		return "Lead";
		break;

	case BLOON_ZEBRA:
		return "Zebra";
		break;

	case BLOON_RAINBOW:
		return "Rainbow";
		break;

	case BLOON_CERAMIC:
		return "Ceramic";
		break;

	case BLOON_UNKNOWN:
		LOGW("WARNING: Unknown bloon detected. Please report what bloon this is!");
		return "Unknown";
		break;

	case BLOON_MOAB:
		return "Moab";
		break;

	case BLOON_BFB:
		return "BFB";
		break;

	case BLOON_ZOMG:
		return "ZOMG";
		break;

	default:
		LOGW("WARNING: Bloon name not found!. Bloon ID 0x" << TO_STRING(bloon));
		return "unknown";
	}

	LOGE("Error: Unreachable code, GetNameFromType reached.");
	return "Error: Bloon type not found!";
}


//
// Bloon
//

// 0xA0

void Bloon::SetSpriteX(float x) {
	WriteOffsetField(OFF_FIELD_SPRITEX, (u32*)&x);
}

float Bloon::GetSpriteX(){
	u32 floatBytes = ReadOffsetField(OFF_FIELD_SPRITEX);
	float SpriteX = reinterpret_cast<float&>(floatBytes);
	return SpriteX;
}

// 0xA4

void Bloon::SetSpriteY(float y) {
	WriteOffsetField(OFF_FIELD_SPRITEY, (u32*)&y);
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
	u32 PtrToBloonType = ReadOffsetField(OFF_FIELD_BLOONTYPE);
	BloonType type(PtrToBloonType);
	return type;
}

// 0x26C

void Bloon::SetDistanceOnTrack(float dist) {
	WriteOffsetField(OFF_FIELD_DISTANCE, (u32*)&dist);
}

float Bloon::GetDistanceOnTrack() {
	u32 DistBytes = ReadOffsetField(OFF_FIELD_DISTANCE);
	float Distance = reinterpret_cast<float&>(DistBytes);
	
	return Distance;
}

// 0x278

void Bloon::SetPosX(float x) {
	WriteOffsetField(OFF_FIELD_SPRITEX, (u32*)&x);
}

float Bloon::GetPosX() {
	u32 FloatBytes = ReadOffsetField(OFF_FIELD_POSX);
	float PosX = reinterpret_cast<float&>(FloatBytes);
	return PosX;
}

// 0x26C

void Bloon::SetPosY(float y) {
	WriteOffsetField(OFF_FIELD_SPRITEY, (u32*)&y);
}

float Bloon::GetPosY() {
	u32 FloatBytes = ReadOffsetField(OFF_FIELD_POSY);
	float PosY = reinterpret_cast<float&>(FloatBytes);
	return PosY;
}