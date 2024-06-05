#include <iostream>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

HANDLE FindGameProcess(const std::wstring& gameName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return NULL;

    PROCESSENTRY32 processEntry = { sizeof(PROCESSENTRY32) };
    HANDLE hProcess = NULL;

    if (Process32First(snapshot, &processEntry)) {
        do {
            if (_wcsicmp(processEntry.szExeFile, gameName.c_str()) == 0) {
                hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processEntry.th32ProcessID);
                break;
            }
        } while (Process32Next(snapshot, &processEntry));
    }
    CloseHandle(snapshot);
    return hProcess;
}

HWND FindGameWindow(const std::wstring& windowName) {
    return FindWindowW(NULL, windowName.c_str());
}

template <typename T>
T ReadAddress(HANDLE hProcess, DWORD address) {
    T value;
    ReadProcessMemory(hProcess, (LPCVOID)address, &value, sizeof(T), NULL);
    return value;
}

template <typename T>
bool WriteAddress(HANDLE hProcess, DWORD address, const T& value) {
    return WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(T), NULL);
}

template <typename T>
T ReadAddressOffset(HANDLE hProcess, DWORD address, const DWORD offset) {
    return ReadAddress<T>(hProcess, address + offset);
}

template <typename T>
bool WriteAddressOffset(HANDLE hProcess, DWORD address, DWORD offset, const T& value) {
    return WriteAddress(hProcess, address + offset, value);
}

template <typename T>
T ReadAddressOffsets(HANDLE hProcess, DWORD address, const std::vector<DWORD>& offsets) {
    DWORD currentAddress = address;
    for (DWORD offset : offsets) {
        currentAddress = ReadAddress<DWORD>(hProcess, currentAddress) + offset;
    }
    return ReadAddress<T>(hProcess, currentAddress);
}

template <typename T>
bool WriteAddressOffsets(HANDLE hProcess, DWORD address, const std::vector<DWORD>& offsets, const T& value) {
    DWORD currentAddress = address;
    for (size_t i = 0; i < offsets.size() - 1; ++i) {
        currentAddress = ReadAddress<DWORD>(hProcess, currentAddress) + offsets[i];
    }
    return WriteAddress(hProcess, currentAddress + offsets.back(), value);
}

std::string ReadString(HANDLE hProcess, DWORD address, size_t size) {
    std::vector<char> buffer(size + 1);
    ReadProcessMemory(hProcess, (LPCVOID)address, buffer.data(), size, NULL);
    buffer[size] = '\0';
    return std::string(buffer.data());
}

bool WriteString(HANDLE hProcess, DWORD address, const std::string& str) {
    return WriteProcessMemory(hProcess, (LPVOID)address, str.c_str(), str.size() + 1, NULL);
}

bool HotKeysDown(const std::vector<int>& keys) {
    for (int key : keys) {
        if (!(GetAsyncKeyState(key) & 0x8000)) return false;
    }
    return true;
}

bool IsKeyPressed(int keycode) {
    return GetAsyncKeyState(keycode) & 0x8000;
}

bool IsKeyToggled(int keycode) {
    return GetKeyState(keycode) & 1;
}

HANDLE GetGameHandle4mHWND(HWND hwnd) {
    DWORD processID;
    GetWindowThreadProcessId(hwnd, &processID);
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
}

DWORD GetProcessID4mHWND(HWND hwnd) {
    DWORD processID;
    GetWindowThreadProcessId(hwnd, &processID);
    return processID;
}

int main() {
    std::cout << "Star This!\n";

    const std::wstring processName = L"Starme.exe";
    const std::wstring windowName = L"GameWindowName";
    DWORD baseAddress = 0x207B566A7F0; // Add your addy (address) here
    DWORD offset = 0x18C; // add your offset here
    int newValue = 10000; // whatever you want to set the value to

    HANDLE hProcess = FindGameProcess(processName);
    if (!hProcess) {
        std::cerr << "Failed to find the game process.\n";
        return 1;
    }

    HWND gameWindow = FindGameWindow(windowName);
    if (!gameWindow) {
        std::cerr << "Failed to find the game window.\n";
        CloseHandle(hProcess);
        return 1;
    }

    if (WriteAddressOffset(hProcess, baseAddress, offset, newValue)) {
        std::cout << "Memory written successfully.\n";
    }
    else {
        std::cerr << "Failed to write memory.\n";
    }

    CloseHandle(hProcess);
    return 0;
}
