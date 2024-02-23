#include <iostream>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
    int m, n;
    cout << "Nhap so phan thuong: ";
    cin >> m;
    cout << "Nhap so hoc sinh: ";
    cin >> n;

    int* ketQua = ChiaThuong(m, n);

    std::cout << "So phan thuong cua moi hoc sinh:\n";
    for (int i = 0; i < n; ++i) 
    {
        cout << "Hoc sinh " << i + 1 << ": " << ketQua[i] << " phan thuong\n";
    }

    delete[] ketQua;
    system("PAUSE");
}