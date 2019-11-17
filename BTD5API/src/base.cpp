#include "BTD5API/base.hpp"
#include "BTD5API/bloons.hpp"
#include "BTD5API/Global.hpp"


void BTD5API::Initialise(WindowsMemory *memory) {

	MEMNAME = memory;
	// Set Vector

	const u32 BloonListBasePtr = 0x00884280;

	u32 BasePtr = MEMNAME->OffsetFromMod(BloonListBasePtr);
	u32 BaseAddr = 0;
	MEMNAME->Read((u32)BasePtr, &BaseAddr);

	const std::vector<u32> BloonListVectorOffsets = { 0x0, 0x74 };
	u32 VecDataOffset = (u32)MEMNAME->MultiLevelPtr(BaseAddr, BloonListVectorOffsets);
	BloonList.Map(VecDataOffset + 0x4, MEMNAME);


}