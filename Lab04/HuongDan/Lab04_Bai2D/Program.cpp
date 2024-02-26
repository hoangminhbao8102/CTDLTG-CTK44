#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>

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
    LL l;
    BD g;
    CreatList_LL(l);
    CreatList_BD(g);

    if (TapTin_List_LL(const_cast<char*>("LLSV.txt"), l) && TapTin_List_BD(const_cast<char*>("DiemQT.txt"), g))
    {
        XuatBangDiem(l, g);
    }
    else
    {
        cout << "\nLoi mo tap tin";
    }
    _getch();

}