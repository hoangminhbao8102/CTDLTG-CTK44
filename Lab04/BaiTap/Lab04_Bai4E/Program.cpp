#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <math.h>
#include <conio.h>

using namespace std;

#include "Header_KQTD.h"
#include "ThuVien_KQTD.h"
#include "Header_KQDB.h"
#include "XepHang.h"
#include "Menu.h"

void ChayChuongTrinh();
void TaoDuLieuKQDB(LIST_KQTD& l, LIST_KQXH& h);

int main()
{
    ChayChuongTrinh();
    return 1;
}

void ChayChuongTrinh()
{
	LIST_KQTD l;
	LIST_KQXH h;
	int SoMenu = 7, menu;
	do
	{
        system("CLS");
        menu = ChonMenu(SoMenu);
        if (menu == 8) 
        {
            TaoDuLieuKQDB(l, h);
        }
        else 
        {
            XuLyMenu(menu, l, h);
        }
        system("PAUSE");
	} while (menu > 0);
}

void TaoDuLieuKQDB(LIST_KQTD& l, LIST_KQXH& h)
{
    CreatList_KQTD(l);
    TapTin_List_KQTD(const_cast<char*>("KQTD.txt"), l);
    KhoiTao_List_KQXH(h);
    for (int i = 1; i <= VongTD_MoiNhat(l); ++i) 
    {
        TaoList_KQDB_Vong(h, l, i);
    }
    
    ofstream outFile("KhoiTao_KQDB.txt");
    if (outFile.is_open()) 
    {
        outFile << "Du lieu da duoc tao thanh cong!";
        outFile.close();
    }
    else 
    {
        cout << "Khong the mo file de ghi du lieu!";
    }
}
