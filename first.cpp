#include <iostream>
#include <conio.h>
#include <unistd.h>
#include<windows.h>

using namespace std;

void enableRawMode()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
}
int main()
{
    enableRawMode();

    char data;
    while (read(STDIN_FILENO, &data, 1) == 1 && data != 'q')
        ;

    return 0;
}
