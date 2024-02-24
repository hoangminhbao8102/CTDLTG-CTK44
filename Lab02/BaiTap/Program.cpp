#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string.h>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	NhanVien a[MAX];
	int SoMenu = 8, menu, n = 0;
	do
	{
		system("CLS");
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}