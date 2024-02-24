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
	SinhVien a[MAX];
	int SoMenu = 5, menu, n = 0;
	do
	{
		system("CLS");
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}