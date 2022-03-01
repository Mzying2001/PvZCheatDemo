#pragma once

#include <Windows.h>

#define SIZEOF_ARR(arr) (sizeof(arr) / sizeof(*arr))

// 内存基址
static const LPVOID BASE_ADDRESS = (LPVOID)0x006A9EC0;

// 阳光的偏移量
static const int OFFSET_SUN[] = {0x768, 0x5560};

// 金币的偏移量
static const int OFFSET_COIN[] = {0x82C, 0x28};

// 冒险关卡的偏移量
static const int OFFSET_ADVPROG[] = {0x82C, 0x24};

// 获取进程句柄
HANDLE GetHandle(HWND hwnd)
{
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
}

// 获取偏移后的地址
LPVOID GetAddress(HANDLE hProc, LPVOID pBase, const int *offset, int cnt)
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
    // 获取植物大战僵尸的窗口句柄
    __declspec(dllexport) HANDLE PVZGetHWND()
    {
        return FindWindowA("MainWindow", "Plants vs. Zombies");
    }

    // 修改阳光
    __declspec(dllexport) void PVZSetSun(HWND hPVZ, int val)
    {
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pSun = GetAddress(hProc, BASE_ADDRESS, OFFSET_SUN, SIZEOF_ARR(OFFSET_SUN));
        WriteProcessMemory(hProc, pSun, (LPVOID)&val, 4, NULL);
    }

    // 修改金币
    __declspec(dllexport) void PVZSetCoin(HWND hPVZ, int val)
    {
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pCoin = GetAddress(hProc, BASE_ADDRESS, OFFSET_COIN, SIZEOF_ARR(OFFSET_COIN));
        WriteProcessMemory(hProc, pCoin, (LPVOID)&val, 4, NULL);
    }

    // 修改冒险模式进度
    __declspec(dllexport) void PVZSetAdvProg(HWND hPVZ, int val)
    {
        HANDLE hProc = GetHandle(hPVZ);
        LPVOID pAdvProg = GetAddress(hProc, BASE_ADDRESS, OFFSET_ADVPROG, SIZEOF_ARR(OFFSET_ADVPROG));
        WriteProcessMemory(hProc, pAdvProg, (LPVOID)&val, 4, NULL);
    }
}