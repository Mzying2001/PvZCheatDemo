#pragma once

#include <Windows.h>
#include <vector>

#define BASE_ADDRESS 0x006A9EC0

using std::vector;

HANDLE GetHandle(HWND hwnd)
{
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

extern "C"
{
    __declspec(dllexport) HANDLE PVZGetHWND()
    {
        return FindWindowA("MainWindow", "Plants vs. Zombies");
    }

    __declspec(dllexport) void PVZSetSun(HWND hPVZ, int val)
    {
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pBase = (LPVOID)BASE_ADDRESS;
        SIZE_T buf = 0;
        ReadProcessMemory(hProc, pBase, (LPVOID)&buf, 4, NULL);
        for (int off : {0x768, 0x5560})
        {
            pBase = (LPVOID)(buf + off);
            ReadProcessMemory(hProc, pBase, (LPVOID)&buf, 4, NULL);
        }
        WriteProcessMemory(hProc, (LPVOID)pBase, (LPVOID)&val, 4, NULL);
    }

    __declspec(dllexport) void PVZSetCoin(HWND hPVZ, int val)
    {
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pBase = (LPVOID)BASE_ADDRESS;
        SIZE_T buf = 0;
        ReadProcessMemory(hProc, pBase, (LPVOID)&buf, 4, NULL);
        for (int off : {0x82C, 0x28})
        {
            pBase = (LPVOID)(buf + off);
            ReadProcessMemory(hProc, pBase, (LPVOID)&buf, 4, NULL);
        }
        WriteProcessMemory(hProc, (LPVOID)pBase, (LPVOID)&val, 4, NULL);
    }

    __declspec(dllexport) void PVZSetAdvProg(HWND hPVZ, int val)
    {
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pBase = (LPVOID)BASE_ADDRESS;
        SIZE_T buf = 0;
        ReadProcessMemory(hProc, pBase, (LPVOID)&buf, 4, NULL);
        for (int off : {0x82C, 0x24})
        {
            pBase = (LPVOID)(buf + off);
            ReadProcessMemory(hProc, pBase, (LPVOID)&buf, 4, NULL);
        }
        WriteProcessMemory(hProc, (LPVOID)pBase, (LPVOID)&val, 4, NULL);
    }
}