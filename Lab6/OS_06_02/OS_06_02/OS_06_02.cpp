#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    for (int i = 0; i < 10000000; i++) {
        cout << "index: " << i << endl;
        Sleep(1000);
    }
}
