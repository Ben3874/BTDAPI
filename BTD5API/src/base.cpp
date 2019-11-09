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

	Bloon DummyInstance(0x0);
	DummyInstance.SetMem(memory);


}



//
//
//WindowsMemory BTD5(Btd5Handle, Btd5Mod);
//
//for (;;) {
//
//
//	u32 firstPtrTest = BTD5.OffsetFromMod((u32)0x0088'4280);
//	u32 BaseAddr;
//	BTD5.Read((u32)firstPtrTest, &BaseAddr);
//
//
//	const std::vector<u32> OffsetList = { 0x0, 0x74, 0x4, 0x0, 0x26C };
//
//	u32 Dist = (u32)BTD5.MultiLevelPtr(BaseAddr, OffsetList);
//	float dis1 = reinterpret_cast<float&>(Dist);
//
//	std::cout << "" << dist1 << "\n";
//
//
//	int x = 5;
//}