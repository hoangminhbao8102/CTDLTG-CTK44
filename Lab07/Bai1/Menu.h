void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, LLIST& l);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem du lieu";
	cout << "\n2. Tim x - Co/Khong";
	cout << "\n3. Tim x - Tra ve vi tri nut dau tien xuat hien neu co";
	cout << "\n4. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co";
	cout << "\n5. Tim x - Xuat cac vi tri xuat hien neu co";
	cout << "\n6. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung";
	cout << "\n7. Chen x vao dau danh sach vong";
	cout << "\n8. Chen x vao cuoi danh sach vong";
	cout << "\n9. Huy nut dau danh sach vong";
	cout << "\n10. Huy nut cuoi danh sach vong";
	cout << "\n11. Huy toan bo danh sach vong";
	cout << "\n12. Dem so nut danh sach vong";
	cout << "\n===================================================";
}

int ChonMenu(int SoMenu)
{
	int STT;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so ( 0 <= so <= " << SoMenu << " ) de chon menu, stt = ";
		cin >> STT;
		if (0 <= STT && STT <= SoMenu)
		{
			break;
		}
	}
	return STT;
}

void XuLyMenu(int menu, LLIST& l)
{
    int x, result;
    switch (menu)
    {
    case 0:
        system("CLS");
        cout << "\n0. Thoat khoi chuong trinh\n";
        break;
    case 1:
        system("CLS");
        cout << "\n1. Xem du lieu\n";
        Output_Llist(l);
        break;
    case 2:
        system("CLS");
        cout << "\n2. Tim x - Co/Khong\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        result = Search(l, x);
        if (result)
            cout << x << " co trong danh sach.\n";
        else
            cout << x << " khong co trong danh sach.\n";
        break;
    case 3:
        system("CLS");
        cout << "\n3. Tim x - Tra ve vi tri nut dau tien xuat hien neu co\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        result = Search_Pos_First(l, x);
        if (result != -1)
            cout << x << " xuat hien dau tien o vi tri: " << result << endl;
        else
            cout << x << " khong co trong danh sach.\n";
        break;
    case 4:
        system("CLS");
        cout << "\n4. Tim x - Tra ve vi tri nut cuoi cung xuat hien neu co\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        result = Search_Pos_End(l, x);
        if (result != -1)
            cout << x << " xuat hien cuoi cung o vi tri: " << result << endl;
        else
            cout << x << " khong co trong danh sach.\n";
        break;
    case 5:
        system("CLS");
        cout << "\n5. Tim x - Xuat cac vi tri xuat hien neu co\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        Search_All_Pos_x(l, x);
        break;
    case 6:
        system("CLS");
        cout << "\n6. Xuat DS moi, voi Head moi tro toi nut x xuat hien cuoi cung\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        result = Head_New(l, x);
        if (result == 1)
            Output_Llist(l);
        else if (result == -1)
            cout << x << " khong co trong danh sach.\n";
        else
            cout << "Danh sach rong.\n";
        break;
    case 7:
        system("CLS");
        cout << "\n7. Chen x vao dau danh sach vong\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        InsertHead(l, x);
        break;
    case 8:
        system("CLS");
        cout << "\n8. Chen x vao cuoi danh sach vong\n";
        cout << "Nhap gia tri x: ";
        cin >> x;
        InsertTail(l, x);
        break;
    case 9:
        system("CLS");
        cout << "\n9. Huy nut dau danh sach vong\n";
        RemoveHead(l);
        break;
    case 10:
        system("CLS");
        cout << "\n10. Huy nut cuoi danh sach vong\n";
        RemoveTail(l);
        break;
    case 11:
        system("CLS");
        cout << "\n11. Huy toan bo danh sach vong\n";
        RemoveLLIST(l);
        break;
    case 12:
        system("CLS");
        cout << "\n12. Dem so nut danh sach vong\n";
        result = SoNut(l);
        cout << "So nut trong danh sach vong: " << result << endl;
        break;
    }
}
