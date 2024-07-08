#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;
#include "AVLTree.h"
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
	int menu, SoMenu = 14;
	AVLTree root = NULL;
	do
	{
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, root);
		system("PAUSE");
	} while (menu > 0);
}