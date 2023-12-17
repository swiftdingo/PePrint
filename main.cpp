#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <winap>

int main() {
	pfnCreateProcessW pCreateProcessW = (pfnCreateProcessW)GetProcAddress(GetModuleHandleW(L"KERNEL32.DLL"), "CreateProcessW");
	if (pCreateProcessW == NULL) {
		// Handle error if the function cannot be found
	}

	STARTUPINFOW si{};
	PROCESS_INFORMATION pi{};

	// Clear out startup and process info structures
	RtlSecureZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si;
	RtlSecureZeroMemory(&pi, sizeof(pi));

	std::wstring pName = L"C:\\Windows\\System32\\svchost.exe";

	HANDLE pHandle = NULL;
	HANDLE hThread = NULL;
	DWORD Pid = 0;

	BOOL cProcess = pCreateProcessW(NULL, &pName[0], NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi);

	pHandle = pi.hProcess;
	hThread = pi.hThread;
	Pid = pi.dwProcessId;

}
