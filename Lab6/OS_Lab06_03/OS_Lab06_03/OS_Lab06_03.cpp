#include <iostream>
#include <Windows.h>

using namespace std;

#define KB (1024)
#define PGSIZE (4 * KB)

int main()
{
	setlocale(LC_ALL, "rus");

	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);

	int pages = 256;
	int countItems = pages * system_info.dwPageSize / sizeof(int);

/*
	LPVOID VirtualAlloc - выделить или зарезервировать страницы виртуальной памяти
	(  
	LPVOID lpAddress,		// базовые адрес
	SIZE_T dwSize,		// размер
	DWORD flAllocationType,	// способ получения
	DWORD flProtect		// тип доступа
	);
*/
	LPVOID xmemaddr = VirtualAlloc(NULL, pages * system_info.dwPageSize, MEM_COMMIT, PAGE_READWRITE);
	int* arr = (int*)xmemaddr;
	for (int i = 0; i < countItems; i++) {
		arr[i] = i;
	}
	cout << endl;

	getchar();

	VirtualFree(xmemaddr, NULL, MEM_RELEASE) ?
		cout << "VirtualFree true\n" : cout << "VirtualFree false\n";

				//М = СС = 204					Т = D2 = 210	Д = C4 = 196	D2C = 3372	CCD2C=838956
				//адрес = PGSIZE * 200 + 3373 = 4096 * 200 + 3373 = 0x00333 + 0x013B0000
}