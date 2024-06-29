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
    char sin[MAX], sout[MAX] = ""; // Khai báo chuỗi đầu vào và chuỗi đầu ra
    cout << "Nhap bieu thuc trung to: ";
    cin.getline(sin, MAX); // Đọc chuỗi đầu vào từ bàn phím

    TrungTo_HauTo(sin, sout); // Chuyển đổi chuỗi từ trung tố sang hậu tố

    cout << "Bieu thuc hau to la: " << sout << endl; // Xuất chuỗi đầu ra
}