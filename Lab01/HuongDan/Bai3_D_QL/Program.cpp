#include <iostream>
#include <iomanip>

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
	int menu, SoMenu = 5;
	int n = 0;
	do
	{
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, n);
		system("PAUSE");
	} while (menu > 0); 
}