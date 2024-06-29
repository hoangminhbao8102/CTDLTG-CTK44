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
    char bieuThuc[MAX];
    cout << "Nhap bieu thuc hau to (VD: 56+): ";
    cin >> bieuThuc;
    cout << "Gia tri cua bieu thuc la: " << Tinh_BT_HauTo(bieuThuc) << endl;
}