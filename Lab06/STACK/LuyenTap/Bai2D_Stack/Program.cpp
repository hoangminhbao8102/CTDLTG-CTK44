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
    int n, b;
    cout << "Nhap so nguyen duong n (he 10): ";
    cin >> n;
    cout << "Nhap co so b (b > 1): ";
    cin >> b;

    if (b <= 1)
    {
        cout << "Co so b phai lon hon 1. Khong thuc hien duoc thao tac.\n";
        return;
    }

    DoiCoSo(n, b);
}