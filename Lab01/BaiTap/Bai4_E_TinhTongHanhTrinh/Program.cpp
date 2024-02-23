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
    cout << "Nhap kich thuoc ban co n x n: ";
    cin >> n;

    int board[MAX_N][MAX_N];
    cout << "Nhap gia tri cho cac o tren ban co:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << "Gia tri tai o (" << i << ", " << j << "): ";
            cin >> board[i][j];
        }
    }

    printMaxSumPath(n, board);
	system("PAUSE");
}