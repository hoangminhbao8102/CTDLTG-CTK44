void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, SET& l1, SET& l2);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu cho tap hop";
	cout << "\n2. Xem du lieu tap hop";
	cout << "\n3. Giao 2 tap hop";
	cout << "\n4. Hop 2 tap hop";
	cout << "\n5. Hieu 2 tap hop";
	cout << "\n6. Hieu doi xung 2 tap hop";
	cout << "\n7. Tich Descartes 2 tap hop";
	cout << "\n8. Kiem tra phan tu co thuoc vao tap hop";
	cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop";
	cout << "\n10. Tinh luc luong tap hop";
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

void XuLyMenu(int menu, SET& l1, SET& l2)
{
	DataType x;
	SET kq;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap du lieu cho tap hop";
		CreatList(l1); // Tạo mới danh sách l1
		CreatList(l2); // Tạo mới danh sách l2
		File_List("A.txt", l1); // Đọc file A.txt vào l1
		File_List("B.txt", l2); // Đọc file B.txt vào l2
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu tap hop\n";
		cout << "Danh sach l1: ";
		XuatDS(l1);
		cout << "\nDanh sach l2: ";
		XuatDS(l2);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Giao 2 tap hop\n";
		kq = Giao(l1, l2);
		XuatDS(kq);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Hop 2 tap hop\n";
		kq = Hop(l1, l2);
		XuatDS(kq);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Hieu 2 tap hop\n";
		kq = Hieu(l1, l2);
		XuatDS(kq);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Hieu doi xung 2 tap hop\n";
		kq = HieuDoiXung(l1, l2);
		XuatDS(kq);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tich Descartes 2 tap hop\n";
		TichDescartes(l1, l2);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Kiem tra phan tu co thuoc vao tap hop\n";
		cout << "Nhap phan tu can kiem tra: ";
		cin >> x; // Giả sử DataType có thể nhập trực tiếp
		cout << (IsExist(l1, x) ? "Phan tu thuoc l1" : "Phan tu khong thuoc l1") << endl;
		cout << (IsExist(l2, x) ? "Phan tu thuoc l2" : "Phan tu khong thuoc l2") << endl;
		break;
	case 9:
		system("CLS");
		cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop\n";
		cout << (IsSubset(l1, l2) ? "l1 la tap con cua l2" : "l1 khong la tap con cua l2") << endl;
		cout << (IsSubset(l2, l1) ? "l2 la tap con cua l1" : "l2 khong la tap con cua l1") << endl;
		break;
	case 10:
		system("CLS");
		cout << "\n10. Tinh luc luong tap hop\n";
		cout << "Cardinality of l1: " << Cardinality(l1) << endl;
		cout << "Cardinality of l2: " << Cardinality(l2) << endl;
		break;
	}
}