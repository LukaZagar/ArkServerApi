#include "PlayerList.h"
#include "PlayerListCommands.h"
#include "PlayerListConfig.h"

#pragma comment(lib, "ArkApi.lib")

void Init()
{
	Log::Get().Init("PlayerList");
	InitConfig();
	InitCommands();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		RemoveCommands();
		break;
	}
	return TRUE;
}