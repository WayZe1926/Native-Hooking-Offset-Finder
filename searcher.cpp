int DumpedNatives;
int IsHookWorkingTickMax = 50;
int BaseHookTickMax = 50;
int LastChecked;
 
void DumpToFile()
{
        //CAUSE DX12 HOOK SUCKS HUGE PP
        //FILE CAN BE FOUND IN RDR2 FOLDER. THIS ADDS TO ALREADY EXISTING FILE. IF YOU WANT TO DO THIS TWICE, DELETE THE FILE FIRST OR IT WILL START ADDING TO THE OLD DUMP
       //You do not need to create the file yourself ofcourse
	ofstream foutput;
	ifstream finput;
	finput.open("NATIVES_FOR_HOOKING_DUMP.txt");
	foutput.open("NATIVES_FOR_HOOKING_DUMP.txt", ios::app);
 
	if (HookAllArraySize != LastChecked)
	{
		if (finput.is_open())
		{
			foutput << "\n  OFFSET : " << std::hex << "0x" << (HookAll[HookAllArraySize] - (uintptr_t)GetModuleHandleA(0)) << std::dec << "  BASETICKCOUNT : " << BaseHookTick << " OFFSET TICKRATE : " << IsHookWorkingTick << "/" << IsHookWorkingTickMax;
			LastChecked = HookAllArraySize;
			DumpedNatives = DumpedNatives + 1;
		}
		IsHookWorkingTick = 0;
		BaseHookTick = IsHookWorkingTickMax;
	}
	finput.close();
	foutput.close();
}
int __fastcall is_hook_working(__int64 a1, DWORD dlcHash) // you can remove the arguments but if you do also remove them below. im lazy coder so copy pasted from is_dlc_present.
{
 
	IsHookWorkingTick = IsHookWorkingTick + 1;
	if (IsHookWorkingTick >= IsHookWorkingTickMax)
	{
		DumpToFile();
		IsHookWorkingTick = 0;
	}
 
	return o_hooking_switch(a1, dlcHash);
}
 
bool NativeHookingDumper;
void HookChecker()
{
	CloseFileNow = false;
	MH_STATUS status;
	BaseHookTick = BaseHookTick + 1;
	status = MH_CreateHook((PVOID)HookAll[HookAllArraySize], is_hook_working, reinterpret_cast<void**>(&o_hooking_switch));
	MH_EnableHook((PVOID)HookAll[HookAllArraySize]);
	if (BaseHookTick > BaseHookTickMax)
	{
		MH_DisableHook((PVOID)HookAll[HookAllArraySize]); 
		MH_RemoveHook((PVOID)HookAll[HookAllArraySize]));
		HookAllArraySize = HookAllArraySize + 1;
		IsHookWorkingTick = 0;
		BaseHookTick = 0;
	}
	if (HookAllArraySize >= 6930)
	{
		CloseFileNow = true;
		HookAllArraySize = 1;
		//NativeHookingDumper = false;// disable bool you call with here.
	}
 
}