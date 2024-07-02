#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>

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
    QUEUE q;
    CreatQueue(q);  // Khởi tạo hàng đợi

    ChonPhuongThucNhap(q);  // Nhập thông tin các nhóm

    int m;
    cout << "Nhap so ngay truc: ";
    cin >> m;

    XuatLichTruc(q, m);  // Xuất lịch trực
}