#include <Windows.h>
#include <iostream>
#include <iomanip>
#include<TlHelp32.h>

using namespace std;

DWORD pid = NULL;

DWORD WINAPI os04_02_T1()
{
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 50; i++)
	{
		Sleep(1000);
		cout << "\nPID: " << pid << endl;
		cout << "TID(os04_02_T1):" << tid << endl;
	}
	return 0;
}

DWORD WINAPI os04_02_T2()
{
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 125; i++)
	{
		Sleep(1000);
		cout << "\nPID: " << pid << endl;
		cout << "TID(os04_02_T2):" << tid << endl;
	}
	return 0;
}

int main()
{
    pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();
	DWORD ChildId1 = NULL;
	DWORD ChildId2 = NULL;
	HANDLE hChild1 = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)os04_02_T1,NULL,0,&ChildId1);
	HANDLE hChild2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)os04_02_T2, NULL, 0, &ChildId2);
	for (int i = 0; i < 100; i++)
	{
		Sleep(1000);
		cout << "\nPID: " << pid << endl;
		cout << "TID(Parent): " << tid << endl;
	}
	WaitForSingleObject(hChild1,INFINITE);
	CloseHandle(hChild1);
	WaitForSingleObject(hChild2, INFINITE);
	CloseHandle(hChild2);
}
//Функция CreateThread. Функция CreateThread создает поток, который выполняется в пределах виртуального адресного пространства 
//вызывающего процесса. Чтобы создавать поток, который запускается в виртуальном адресном пространстве другого процесса, 
//используется функция CreateRemoteThread.