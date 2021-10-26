#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;
int main()
{
	LPCWSTR an1 = L"D:\\Study\\Practice\\OSSP\\Lab3\\OS03_02_01\\Debug\\OS03_02_01.exe";
	LPCWSTR an2 = L"D:\\Study\\Practice\\OSSP\\Lab3\\OS03_02_02\\Debug\\OS03_02_02.exe";
	STARTUPINFO si1, si2;
	PROCESS_INFORMATION pi1, pi2;
	ZeroMemory(&si1, sizeof(STARTUPINFO)); si1.cb = sizeof(STARTUPINFO);
	ZeroMemory(&si2, sizeof(STARTUPINFO)); si2.cb = sizeof(STARTUPINFO);

	if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
		cout << "Process OS03_02_01.exe created!" << endl;
	else
		cout << "Process OS03_02_01.exe not created!" << endl;

	if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
		cout << "Process OS03_02_02.exe created!" << endl;
	else
		cout << "Process OS03_02_02.exe not created!" << endl;

	DWORD pid = GetCurrentProcessId();
	for (int i = 0; i < 1000; i++)
	{
		Sleep(1000);
		cout << "PID: " << pid << endl;
	}
	WaitForSingleObject(pi1.hProcess, INFINITE);
	CloseHandle(pi1.hProcess);
	WaitForSingleObject(pi2.hProcess, INFINITE);
	CloseHandle(pi2.hProcess);
}