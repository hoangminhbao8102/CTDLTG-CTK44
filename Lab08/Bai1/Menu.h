void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, BTree& root);

void XuatMenu()
{
	cout << "\n========He thong menu======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay BST";
	cout << "\n2. Xuat cay BST theo thu tu truoc, giua, cuoi";
	cout << "\n3. So nut cua cay";
	cout << "\n4. Chieu cao cua cay";
	cout << "\n5. Dem so nut la va xuat cac nut la";
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
void XuLyMenu(int menu, BTree& root)
{
	char* filename;
	int kq;
	Data x, y;
	//=========================
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuonbg trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay BST";
		filename = new char[50];
		cout << "\nTen tap tin : filename = ";
		_flushall();
		cin >> filename;
		kq = File_BT(root, filename);
		if (kq)
			cout << "\nDa chuyen du lieu file " << filename << " vao cay BST";
		else
			cout << "\nKhong thanh cong!!!";
		delete[]filename;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat cay BT theo thu tu ";
		cout << "\nNut goc : " << root->key;
		cout << "\nCay BST hien hanh, xuat theo thu tu truoc (NLR) :\n\n";
		PreOrder(root);
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		cout << "\n\nCay BST hien hanh, xuat theo thu tu cuoi (LRN) :\n";
		PosOrder(root);
		break;
	case 3:
		system("CLS");
		cout << "\n3. So nut cua cay";
		cout << "\nCay BST hien hanh, xuat theo thu tu giua :\n";
		InOrder(root);
		cout << "\nSo nut trong cay : So nut = " << DemSoNut(root);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Chieu cao cua cay";
		cout << "\nCay BST hien hanh, xuat theo thu tu giua :\n";
		InOrder(root);
		cout << "\nChieu cao cua cay BST : h = " << TinhChieuCao(root);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Dem so nut la va xuat cac nut la";
		cout << "\nCay BST hien hanh, xuat theo thu tu giua :\n";
		InOrder(root);
		cout << "\n\nDanh sach cac nut la cua BST:\n";
		kq = DemNutLa(root);
		cout << "\n\nSo nut la cua cay BST : soNutLa = " << kq;
		break;
	}
}
