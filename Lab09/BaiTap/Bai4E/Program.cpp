#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

#include "ThuVien.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	_getch();
	return 0;
}

void ChayChuongTrinh()
{
	BSTree dictionary;
	CreateBST(dictionary);
	InsertNode(dictionary, "hello", "xin chao, chao ban");
	InsertNode(dictionary, "world", "the gioi, trai dat");
	InOrder(dictionary);
}