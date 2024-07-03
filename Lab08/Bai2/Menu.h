void XuatMenu()
{
	cout << "\n========He thong menu======";
	cout << "\n0. Thoat khoi chuonbg trinh";
	cout << "\n1. Tao cay BT";
	cout << "\n2. Xuat cay BT ";
	cout << "\n3. Xuat so nut cua cay (so luong hoc vien trong danh sach) ";
	cout << "\n4. Xuat so nut la cua cay va thong tin tuong ung cua cac nut";
	cout << "\n5. Chieu cao cua cay ";
	cout << "\n6. Tim kiem theo ma hoc vien ";
	cout << "\n7. Xuat hoc vien co ten cho truoc ";
	cout << "\n===========================";
}
int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << soMenu << "] de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, BTree& root)
{
	char* filename;
	int kq;
	char maHV[8];
	char ten[8];
	//=========================
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuonbg trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay BT";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = File_BT(root, filename);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao BTree thanh cong.";
		delete[]filename;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat BTree ";
		cout << "\n\nCay BT hien hanh, xuat theo thu tu truoc (NLR) :\n";
		TieuDe();
		PreOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << endl;
		system("PAUSE");
		cout << "\n\nCay BT hien hanh, xuat theo thu tu giua (LNR) :\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << endl;
		system("PAUSE");
		cout << "\n\nCay BT hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\n\nDanh sach hoc vien co " << DemSoNut(root) << " hoc vien ";
		break;
	case 3:
		system("CLS");
		cout << "\n3. Xuat so nut cua cay (so luong hoc vien trong danh sach) ";
		cout << "\nCay nhi phan co " << DemSoNut(root) << " nut ";
		cout << "\n\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		break;
	case 4:
		system("CLS");
		cout << "\n4. Xuat so nut la cua cay va thong tin tuong ung cua cac nut";
		cout << endl;
		TieuDe();
		kq = DemNutLa(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nCay nhi phan co " << kq << " nut la";
		cout << "\n\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		break;
	case 5:
		system("CLS");
		cout << "\n5. Chieu cao cua cay ";
		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nCay nhi phan co " << DemSoNut(root) << " nut ";
		cout << "\nChieu cao cua cay : " << TinhChieuCao(root);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Tim kiem theo ma hoc vien ";
		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		p = NULL;
		cout << "\nNhap ma HV can tim : maHV = ";
		cin >> maHV;
		TimKiem_MaHV(root, maHV);
		if (p == NULL)
			cout << "\nTrong DS, khong co hoc vien nao co maHV = " << maHV;
		else
		{
			TieuDe();
			Xuat_HV(p->info);
			cout << "\n:";
			for (int i = 1; i <= MAXCOT; i++)
				cout << "=";
			cout << ":";
		}
		break;
	case 7:
		system("CLS");
		cout << "\n7. Xuat hoc vien co ten cho truoc";
		cout << "\nCay BT xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nNhap ten HV can tim : ten = ";
		cin >> ten;
		dem = 0;
		cout << "\nDanh sach hoc vien co ten " << ten;
		cout << endl;
		TieuDe();
		Xuat_HV_Ten(root, ten);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		if (dem == 0)
			cout << "\nKhong co hoc vien nao ten " << ten;
		else
			cout << "\nCo " << dem << " hoc vien ten " << ten;
		break;
	}
}
