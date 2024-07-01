#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    _getch();
    return 1;
}

void ChayChuongTrinh()
{
    char filename[] = "Test.txt";
    char operations[MAX];
    File_String(filename, operations);
    XuLy_ThaoTac(operations);
}