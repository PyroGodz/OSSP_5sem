#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

BOOL delRowFileTxt(LPWSTR fileName, DWORD row) {
	char filepath[20];
	wcstombs(filepath, fileName, 20);
	try
	{
		std::cout << "Row delete from file\n";
		std::cout << "Path of file: " << filepath << "\n";
		std::cout << "Row to delete: " << row << "\n\n";
		HANDLE hf = CreateFile(
			fileName,
			GENERIC_READ,
			NULL,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (hf == INVALID_HANDLE_VALUE) {
			std::cout << "Open file unsuccessfully\n";
			CloseHandle(hf);
			return false;
		}
		else {
			std::cout << "Open file successfully\n";
		}
		DWORD n = NULL;
		char Content[1024];
		BOOL b;
		ZeroMemory(Content, sizeof(Content));
		b = ReadFile(
			hf,
			&Content,
			sizeof(Content),
			&n,
			NULL
		);
		if (!b) {
			std::cout << "Read file unsuccessfully\n";
			CloseHandle(hf);
			return false;
		}
		else {
			std::cout << "Read file successfully\n";
			std::cout << "Number of readed bytes: " << n << "\n";
			std::cout << Content << std::endl;
			CloseHandle(hf);
		}
		HANDLE hAppend = CreateFile(fileName, // open Two.txt
			GENERIC_WRITE,         // open for writing
			NULL,          // allow multiple readers
			NULL,                     // no security
			OPEN_ALWAYS,              // open or create
			FILE_ATTRIBUTE_NORMAL,    // normal file
			NULL);                    // no attr. template

		char editedContent[1024];
		ZeroMemory(editedContent, sizeof(editedContent));

		int line = 1;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (line == row) {
				
			}
			else {
				editedContent[j] = Content[i];
				j++;
			}

			if (Content[i] == '\n') {
				line++;
			}
		}
		b = WriteFile(hAppend, 
			editedContent, 
			n, 
			&n, 
			NULL);
		if (!b) {
			std::cout << "Write file unsuccessfully\n";
			CloseHandle(hAppend);
			return false;
		}
		else {
			std::cout << "Write file successfully\n";
			std::cout << "Number of writed bytes: " << j << "\n"; // not at all
			std::cout << editedContent << std::endl;
			CloseHandle(hAppend);
			return true;
		}
	}
	catch (const char* em) { std::cout << "\tError: " << em << " \n"; return false; }
}

int main() {
	char text[] = "../../os09_01.txt";
	wchar_t wtext[20];
	mbstowcs(wtext, text, strlen(text) + 1);
	LPWSTR fileName = wtext;

	delRowFileTxt(fileName, 10);
	delRowFileTxt(fileName, 8);
	delRowFileTxt(fileName, 3);
	delRowFileTxt(fileName, 1);

	system("pause");
	return 0;
}