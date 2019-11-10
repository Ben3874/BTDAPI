#include "BTD5API/base.hpp"
#include "BTD5API/bloons.hpp"

void BTD5API::Initialise(WindowsMemory *memory) {

	mem = memory;
	// Set Vector

	const u32 BloonListBasePtr = 0x00884280;

	u32 BasePtr = mem->OffsetFromMod(BloonListBasePtr);
	u32 BaseAddr = 0;
	mem->Read((u32)BasePtr, &BaseAddr);

	const std::vector<u32> BloonListVectorOffsets = { 0x0, 0x74 };
	u32 VecDataOffset = (u32)mem->MultiLevelPtr(BaseAddr, BloonListVectorOffsets);
	BloonList.Map(VecDataOffset + 0x4, mem);

	Bloon BloonDummyInstance(0x0);
	BloonDummyInstance.SetMem(memory);

	BloonType TypeDummyInstance(0x0);
	TypeDummyInstance.SetMem(memory);


}