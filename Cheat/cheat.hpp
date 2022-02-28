#pragma once

#include <Windows.h>

#define BASE_ADDRESS 0x006A9EC0

LPVOID GetAddress(HANDLE hProcess, LPVOID pBase, int *off, int cnt)
{
    int buf;
    LPVOID pBuf = (LPVOID)&buf;

    ReadProcessMemory(hProcess, pBase, pBuf, 4, NULL);
    for (int i = 0; i < cnt; ++i)
        ReadProcessMemory(hProcess, (LPVOID)(buf + off[i]), pBuf, 4, NULL);

    return (LPVOID)buf;
}

extern "C"
{
    __declspec(dllexport) HANDLE PVZGetHandle()
    {
        HWND hgame = FindWindowA("MainWindow", "Plants vs. Zombies");
        DWORD pid;
        GetWindowThreadProcessId(hgame, &pid);
        return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    }

    __declspec(dllexport) void PVZSetSun(HANDLE hProcess, int val)
    {
        int off[] = {0x768, 0x160, 0x4, 0x5560};
        LPVOID pSun = GetAddress(hProcess, (LPVOID)BASE_ADDRESS, off, 4);
        WriteProcessMemory(hProcess, pSun, (LPVOID)&val, 4, NULL);
    }

    __declspec(dllexport) void PVZSetCoin(HANDLE hProcess, int val)
    {
        int off[] = {0x82C, 0x28};
        LPVOID pCoin = GetAddress(hProcess, (LPVOID)BASE_ADDRESS, off, 2);
        WriteProcessMemory(hProcess, pCoin, (LPVOID)&val, 4, NULL);
    }

    __declspec(dllexport) void PVZSetAdvProg(HANDLE hProcess, int val)
    {
        int off[] = {0x82C, 0x24};
        LPVOID AdvProg = GetAddress(hProcess, (LPVOID)BASE_ADDRESS, off, 2);
        WriteProcessMemory(hProcess, AdvProg, (LPVOID)&val, 4, NULL);
    }
}