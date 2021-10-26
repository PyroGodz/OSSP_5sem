#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <TlHelp32.h>
#include <cwchar>
using namespace std;

int main()
{
	DWORD pid = GetCurrentProcessId();
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 peProcessEntry;
	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	wcout << L"Current PID = " << pid << endl << L"--------------------------------------" << endl;
	try
	{
		if (!Process32First(snap, &peProcessEntry)) throw L"Process32First";
		do
		{
			wcout << L"Name= " << peProcessEntry.szExeFile << endl
				<< L"PID= " << peProcessEntry.th32ProcessID
				<< L",Parent PID = " << peProcessEntry.th32ParentProcessID;
			if (peProcessEntry.th32ProcessID == pid) wcout << "--> current process";
			wcout << endl << L"-----------------------------------------------" << endl;
		} while (Process32Next(snap, &peProcessEntry));
	}
	catch (char* msg) { wcout << L"ERROR :" << msg << endl; }
	system("pause");
	return 0;
}