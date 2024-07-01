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
	int SoMenu = 7, menu;
	QUEUE q;
	do
	{
		system("CLS");
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, q);
		system("PAUSE");
	} while (menu > 0);
}