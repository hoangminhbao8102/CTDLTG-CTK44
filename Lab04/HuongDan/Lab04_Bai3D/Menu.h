void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, LIST& l);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tach danh sach nhan vien thanh 2 danh sach, danh sach dau gom nhung nhan vien co luong ≤ x, danh sach sau gom nhung nhan vien con lai.";
	cout << "\n4. Tach danh sach nhan vien theo cach luan phien tung nhan vien theo thu tu vao 2 danh sach.";
	cout << "\n5. Dao nguoc danh sach.";
	cout << "\n6. Sap danh sach tang dan theo ten, ten trung thi tang dan theo ho; ten va ho trung thi tang dan theo ten lot.";
	cout << "\n===================================================";
}

int ChonMenu(int SoMenu)
{
	int STT;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << SoMenu << " ) de chon menu, stt = ";
		cin >> STT;
		if (0 <= STT && STT <= SoMenu)
		{
			break;
		}
	}
	return STT;
}

void XuLyMenu(int menu, LIST& l)
{
	int kq;
	char filename[100];
	double x;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = TapTin_List(filename, l);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		cout << "\nXem danh sach sinh vien.";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach sinh vien.\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 3:
		cout << "\n3. Tach danh sach nhan vien thanh 2 danh sach, danh sach dau gom nhung nhan vien co luong ≤ x, danh sach sau gom nhung nhan vien con lai.";
		cout << "\nNhap x = ";
		cin >> x;
		Tach_Luong_x(l, x);
		cout << "\nDanh sach sau khi tach:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 4:
		cout << "\n4. Tach danh sach nhan vien theo cach luan phien tung nhan vien theo thu tu vao 2 danh sach.";
		Tach_LuanPhien(l);
		cout << "\nDanh sach sau khi tach:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 5:
		cout << "\n5. Dao nguoc danh sach.";
		DaoNguoc_DS(l);
		cout << "\nDanh sach sau khi dao nguoc:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 6:
		cout << "\n6. Sap danh sach tang dan theo ten, ten trung thi tang dan theo ho; ten va ho trung thi tang dan theo ten lot.";
		List_SapTang_Ten_Ho_TLot(l);
		cout << "\nDanh sach sau khi sap xep:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	}
}