#include <iostream>
#include <fstream>

using namespace std;

#include "ThuVien.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	int SoMenu = 10, menu;
	SET l1, l2;
	do
	{
		system("CLS");
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, l1, l2);
		system("PAUSE");
	} while (menu > 0);
}