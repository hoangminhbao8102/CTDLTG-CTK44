#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
#include "Header.h"
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
	int menu, SoMenu = 13;
	BSTree root = NULL;
	do
	{
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, root);
		system("PAUSE");
	} while (menu > 0);
}