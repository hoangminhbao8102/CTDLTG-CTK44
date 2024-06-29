#include <iostream>
#include <conio.h>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
    ChayChuongTrinh();
    _getch();
    return 0;
}

void ChayChuongTrinh()
{
    STACK s;
    char X[MAX], Y[MAX];

    cout << "Nhap chuoi ky tu: ";
    cin.getline(X, MAX);

    Chep_Chuoi_Sang_Stack(s, X);
    Chep_Stack_Sang_Chuoi(s, Y);

    cout << "Chuoi dao nguoc la: " << Y << endl;
}