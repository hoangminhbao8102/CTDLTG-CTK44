void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, BSTree& root);

void XuatMenu()
{
	cout << "\n========He thong menu======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay tim kiem nhi phan";
	cout << "\n2. Xuat cay tim kiem nhi phan theo thu tu truoc, giua, sau";
	cout << "\n3. Xuat cay theo chieu sau";
	cout << "\n4. Xuat cay theo chieu rong";
	cout << "\n5. Xuat cay theo tung muc";
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
	//=========================
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay tim kiem nhi phan\n";
		filename = new char[50];
		cout << "\nTen tap tin : filename = ";
		_flushall();
		cin >> filename;
		kq = File_BST(root, filename);
		if (kq)
			cout << "\nDa chuyen du lieu file " << filename << " vao cay BST";
		else
			cout << "\nKhong thanh cong!!!";
		delete[]filename;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat cay tim kiem nhi phan theo thu tu truoc, giua, sau\n";
		cout << "\n\nCay BST hien hanh, xuat theo thu tu truoc (NLR) :\n";
		PreOrder(root);
		system("PAUSE");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu giua (LNR) :\n";
		InOrder(root);
		system("PAUSE");
		cout << "\n\nCay BST hien hanh, xuat theo thu tu sau (LRN) :\n";
		PosOrder(root);
		system("PAUSE");
		break;
	case 3:
		system("CLS");
		cout << "\n3. Xuat cay theo chieu sau\n";
		cout << "\n\nCay BST hien hanh, xuat theo chieu sau :\n";
		DFS(root);
		system("PAUSE");
		break;
	case 4:
		system("CLS");
		cout << "\n4. Xuat cay theo chieu rong\n";
		cout << "\n\nCay BST hien hanh, xuat theo chieu rong :\n";
		BFS(root);
		system("PAUSE");
		break;
	case 5:
		system("CLS");
		cout << "\n5. Xuat cay theo tung muc\n";
		cout << "\n\nCay BST hien hanh, xuat theo tung muc :\n";
		BFS_TheoMuc(root);
		system("PAUSE");
		break;
	}
}