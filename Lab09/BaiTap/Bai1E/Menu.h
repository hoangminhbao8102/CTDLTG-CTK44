void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, BSTree& root);

void XuatMenu()
{
	cout << "\n========HE THONG MENU======";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao cay nhi phan can doi (tai moi nut, so con trai và so con phai lech nhau khong qua 1)";
	cout << "\n2. Xuat cac phan tu tren cay theo thu tu dau (NLR), giua (LNR), cuoi (LRN).";
	cout << "\n3. Dem so nut cua cay";
	cout << "\n4. Xac dinh chieu cao cua cay";
	cout << "\n5. Dem so nut cua cay o muc K";
	cout << "\n6. Dem so nut la cua cay";
	cout << "\n7. Dem so nut co dung hai nut con khac rong";
	cout << "\n8. Huy nut co khoa cho truoc";
	cout << "\n9. Chen mot khoa vao cay";
	cout << "\n10. Duyet cay theo chieu rong (BFS)";
	cout << "\n11. Duyet cay theo chieu sau (DFS)";
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
	//=========================
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao cay nhi phan can doi (tai moi nut, so con trai và so con phai lech nhau khong qua 1)\n";
		// Assume there is a function to create a balanced BST (not provided in the initial code)
		char filename[256];
		cout << "Nhap ten file: ";
		cin >> filename;
		if (!File_BST(root, filename)) 
		{
			cout << "Khong the tao cay\n";
		}
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat cay tim kiem nhi phan theo thu tu truoc, giua, sau\n";
		cout << "\nNLR (PreOrder): ";
		PreOrder(root);
		cout << "\nLNR (InOrder): ";
		InOrder(root);
		cout << "\nLRN (PosOrder): ";
		PosOrder(root);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Dem so nut cua cay\n";
		cout << "So nut cua cay: " << CountNodes(root) << endl;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Xac dinh chieu cao cua cay\n";
		cout << "Chieu cao cua cay: " << Height(root) << endl;
		break;;
	case 5:
		system("CLS");
		cout << "\n5. Dem so nut cua cay o muc K\n";
		int level;
		cout << "Nhap muc K: ";
		cin >> level;
		cout << "So nut o muc " << level << ": " << CountLevelNodes(root, level) << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Dem so nut la cua cay\n";
		cout << "So nut la: " << CountLeafNodes(root) << endl;
		break;
	case 7:
		system("CLS");
		cout << "\n7. Dem so nut co dung hai nut con khac rong\n";
		cout << "So nut day du: " << CountFullNodes(root) << endl;
		break;
	case 8:
		system("CLS");
		cout << "\n8. Huy nut co khoa cho truoc\n";
		KeyType key;
		cout << "Nhap khoa can xoa: ";
		cin >> key;
		if (DeleteNode(root, key)) 
		{
			cout << "Da xoa khoa " << key << " thanh cong.\n";
		}
		else 
		{
			cout << "Khong tim thay khoa " << key << " trong cay.\n";
		}
		break;
	case 9:
		system("CLS");
		cout << "\n9. Chen mot khoa vao cay\n";
		KeyType newKey;
		cout << "Nhap khoa moi: ";
		cin >> newKey;
		if (InsertNode(root, newKey)) 
		{
			cout << "Da chen khoa " << newKey << " thanh cong.\n";
		}
		else 
		{
			cout << "Khoa " << newKey << " da ton tai trong cay.\n";
		}
		break;
	case 10:
		system("CLS");
		cout << "\n10. Duyet cay theo chieu rong (BFS)\n";
		BFS(root);
		cout << endl;
		break;
	case 11:
		system("CLS");
		cout << "\n11. Duyet cay theo chieu sau (DFS)\n";
		DFS(root);
		cout << endl;
		break;
	}
}