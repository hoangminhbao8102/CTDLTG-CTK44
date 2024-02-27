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
	LIST l;
	do
	{
		system("CLS");
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, l);
		system("PAUSE");
	} while (menu > 0);
}