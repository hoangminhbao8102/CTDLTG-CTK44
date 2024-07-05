//Khai bao nguyen mau
void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, BSTree& root);
//=====================================
void XuatMenu()
{
	cout << "\n========HE THONG MENU======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao bang diem hoc vien (chuyen du lieu tu tap tin cho truoc vao cay nhi phan tim kiem dua vao khoa ma hoc vien.";
	cout << "\n2. Xem bang diem hoc vien theo thu tu truoc (NLR), thu tu giua (LNR), thu tu cuoi (LRN)";
	cout << "\n3. Thay doi dia chi cua hoc vien khi biet ma hoc vien";
	cout << "\n4. Huy hoc vien co ma nhan vien cho truoc ra khoi bang diem.";
	cout << "\n5. Huy cac hoc vien co diem < 5.";
	cout << "\n===========================";
}
int ChonMenu(int SoMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << SoMenu << "] de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= SoMenu)
			break;
	}
	return stt;
}
void XuLyMenu(int menu, BSTree& root)
{
	char* filename;
	int kq;
	char maHV[8];
	char diaChiMoi[15];
	//=========================
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuonbg trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao bang diem hoc vien (chuyen du lieu tu tap tin cho truoc vao cay nhi phan tim kiem dua vao khoa ma hoc vien.";
		filename = new char[50];
		do
		{
			cout << "\nfilename = ";
			cin >> filename;
			kq = File_BST(root, filename);
		} while (kq == 0);
		cout << "\nDa chuyen du lieu tap tin " << filename << " vao cay BST thanh cong.";
		delete[]filename;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem bang diem hoc vien theo thu tu truoc (NLR), thu tu giua (LNR), thu tu cuoi (LRN)";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu truoc (NLR) :\n";
		TieuDe();
		PreOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		system("PAUSE");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		system("PAUSE");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		TieuDe();
		PosOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		system("PAUSE");
		break;
	case 3:
		system("CLS");
		cout << "\n3. Thay doi dia chi cua hoc vien khi biet ma hoc vien";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		cout << "\nNhap ma hoc vien can thay doi dia chi: ";
		cin >> maHV;
		cout << "\nNhap dia chi moi: ";
		cin >> diaChiMoi;
		kq = ThayDoiDiaChi(root, maHV, diaChiMoi);
		if (kq == 1)
			cout << "\nDa thay doi dia chi cua hoc vien " << maHV << " thanh cong.";
		else
			cout << "\nKhong tim thay hoc vien co ma " << maHV;
		cout << "\nDanh sach sau khi thay doi:\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		system("PAUSE");
		break;
	case 4:
		system("CLS");
		cout << "\n4. Huy hoc vien co ma hoc vien cho truoc ra khoi bang diem.";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		cout << "\nNhap ma hoc vien can huy: ";
		cin >> maHV;
		kq = HuyHocVien(root, maHV);
		if (kq == 1)
			cout << "\nDa huy hoc vien " << maHV << " thanh cong.";
		else
			cout << "\nKhong tim thay hoc vien co ma " << maHV;
		cout << "\nDanh sach sau khi huy:\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		system("PAUSE");
		break;
	case 5:
		system("CLS");
		cout << "\n5. Huy các hoc vien co diem < 5.";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		HuyHocVienDiemThap(root);
		cout << "\nDa huy cac hoc vien co diem < 5 thanh cong.";
		cout << "\nDanh sach sau khi huy:\n";
		TieuDe();
		InOrder(root);
		cout << "\n:";
		for (int i = 1; i <= MAXCOT; i++)
			cout << "=";
		cout << ":";
		cout << "\nDanh sach co " << DemSoNut(root) << " hoc vien ";
		system("PAUSE");
		break;
	}
}