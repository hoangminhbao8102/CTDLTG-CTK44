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
    int n;
    cout << "Nhap so doi bong (n la luy thua 2): ";
    cin >> n;

    if ((n & (n - 1)) != 0 || n <= 1) 
    {
        cout << "So doi bong nhap vao khong hop le.\n";
        return;
    }

    int** lichThiDau;
    TaoLichThiDau(n, &lichThiDau);

    cout << "Lich thi dau:\n";
    for (int i = 0; i < n * (n - 1); ++i) 
    {
        cout << "Doi " << lichThiDau[i][0] << " vs Doi " << lichThiDau[i][1] << endl;
    }

    for (int i = 0; i < n * (n - 1); ++i) 
    {
        delete[] lichThiDau[i];
    }
    delete[] lichThiDau;
	system("PAUSE");
}