#pragma once

#include <Windows.h>

#define BASE_ADDRESS 0x006A9EC0

HANDLE GetHandle(HWND hwnd)
{
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

LPVOID GetAddress(HANDLE hProc, LPVOID pBase, int *offset, int cnt)
{
    SIZE_T buf = 0;
    ReadProcessMemory(hProc, pBase, &buf, 4, NULL);
    for (int i = 0; i < cnt; ++i)
    {
        pBase = (LPVOID)(buf + offset[i]);
        ReadProcessMemory(hProc, pBase, &buf, 4, NULL);
    }
    return pBase;
}

extern "C"
{
    __declspec(dllexport) HANDLE PVZGetHWND()
    {
        return FindWindowA("MainWindow", "Plants vs. Zombies");
    }

    __declspec(dllexport) void PVZSetSun(HWND hPVZ, int val)
    {
        int off[] = {0x768, 0x5560};
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pSun = GetAddress(hProc, (LPVOID)BASE_ADDRESS, off, 2);
        WriteProcessMemory(hProc, pSun, (LPVOID)&val, 4, NULL);
    }

    __declspec(dllexport) void PVZSetCoin(HWND hPVZ, int val)
    {
        int off[] = {0x82C, 0x28};
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pCoin = GetAddress(hProc, (LPVOID)BASE_ADDRESS, off, 2);
        WriteProcessMemory(hProc, pCoin, (LPVOID)&val, 4, NULL);
    }

    __declspec(dllexport) void PVZSetAdvProg(HWND hPVZ, int val)
    {
        int off[] = {0x82C, 0x24};
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pAdvProg = GetAddress(hProc, (LPVOID)BASE_ADDRESS, off, 2);
        WriteProcessMemory(hProc, pAdvProg, (LPVOID)&val, 4, NULL);
    }
}