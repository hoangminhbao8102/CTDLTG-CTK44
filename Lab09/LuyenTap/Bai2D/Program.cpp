#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
#include "BSTree.h"
#include "List.h"
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
	BSTree root = NULL;
	do
	{
		menu = ChonMenu(SoMenu);
		XuLyMenu(menu, root);
		system("PAUSE");
	} while (menu > 0);
}