#include <iostream>
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
    char sin[MAX] = "a+b*(c^d-e)^(f+g*h)-i";
    char sout[MAX] = "";
    TrungTo_HauTo(sin, sout);
    cout << "Bieu thuc hau to: " << sout << endl;
}