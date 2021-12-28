#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

BOOL printRowsCountFile();

BOOL printWatchRowFileTxt(LPWSTR fileName, DWORD mlsec) {
	char filename[20];
	wcstombs(filename, fileName, 20);
	std::cout << "whatch changes in file\n";
	std::cout << "Folder path: " << fileName << "\n";
	std::cout << "Number of milliseconds to watch: " << mlsec << "\n\n";
	try {	

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
			CloseHandle(hf);
		}

		////////

		int line = 1;
		for (int i = 0; i < n; i++) {
			if (Content[i] == '\n') {
				line++;
			}
		}
		std::cout << "Count of rows in file is:\t" << line << "\n\n	";

		bool bWait = true;
		DWORD dwWaitStatus;
		clock_t t1;
		clock_t t2;
		t1 = clock();
		while (bWait)
		{	
			t2 = clock();
			int clockDifference = t2 - t1;
			double timeDifference = (double)clockDifference / CLOCKS_PER_SEC;
			if (timeDifference > mlsec/1000) {

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
					CloseHandle(hf);
				}

				////////

				int line = 1;
				for (int i = 0; i < n; i++) {
					if (Content[i] == '\n') {
						line++;
					}
				}
				std::cout << "Count of rows in file is:\t" << line << "\n\n	";
				std::cout << "Watching is ended\n";
				std::cout << "Time passed: " << timeDifference << " seconds\n";
				break;
			}
		}


	}
	catch (const char* em) { std::cout << "\tError: " << em << " \n"; return false; }
}


int main() {
	char text[] = "../../os09_01.txt";
	wchar_t wtext[20];
	mbstowcs(wtext, text, strlen(text) + 1);
	LPWSTR fileName = wtext;

	printWatchRowFileTxt(fileName, 20000);

	system("pause");
	return 0;
}