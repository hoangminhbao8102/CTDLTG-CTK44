#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <conio.h>

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
	LIST l;
	int SoMenu = 7, menu;
	do
	{
		system("CLS");
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, l);
		system("PAUSE");
	} while (menu > 0);
}