#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

BOOL insRowFileTxt(LPWSTR fileName, LPWSTR str, DWORD row) { 
	char filepath[20];
	wcstombs(filepath, fileName, 20);
	char stringToInsert[50];
	wcstombs(stringToInsert, str, 50);
	try
	{

		std::cout << "insert row to the file\n";
		std::cout << "Filepath: " << filepath << "\n";
		std::cout << "String to insert: " << stringToInsert << "\n";
		std::cout << "Row to insert: " << row << "\n\n";
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
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (line == row) {
				for (int k = 0; k < sizeof(stringToInsert); k++) {
					editedContent[j] = str[k];
					j++;
					if (str[k + 1] == '\0') {
						editedContent[j] = '\n';
						j++;
						row = 0; 
						break;
					}
				}
				i--;
			}
			else {
				editedContent[j] = Content[i];
				j++;
			}
			if (Content[i] == '\n') {
				line++;
			}
			if (Content[i + 1] == '\0' && row == -1) {
				for (int k = 0; k < sizeof(stringToInsert); k++) {
					editedContent[j] = str[k];
					j++;
					if (str[k + 1] == '\0') {
						editedContent[j] = '\n';
						j++;
						row = 0;
						break;
					}
				}
			}
		}
		b = WriteFile(hAppend,
			editedContent,
			j,
			&n,
			NULL);

		if (!b) {
			std::cout << "Write file unsuccessfully\n";
			CloseHandle(hAppend);
			return false;
		}
		else {
			std::cout << "Write file successfully\n";
			std::cout << "Number of writed bytes: " << n << "\n";
			std::cout << editedContent << std::endl;
			CloseHandle(hAppend);
			return true;
		}


	}
	catch (const char* em) { std::cout << "\tError: " << em << " \n"; return false; }
}

int main() {
	char filePath[] = "../../os09_01.txt";
	wchar_t wFilePath[20];
	mbstowcs(wFilePath, filePath, strlen(filePath) + 1);
	LPWSTR fileName = wFilePath;

	char str[] = "inserted row.";
	wchar_t wStr[50];
	mbstowcs(wStr, str, strlen(str) + 1);
	LPWSTR strToIns = wStr;

	insRowFileTxt(fileName, strToIns, 1);
	insRowFileTxt(fileName, strToIns, -1);
	insRowFileTxt(fileName, strToIns, 5);
	insRowFileTxt(fileName, strToIns, 7);

	system("pause");
	return 0;
}