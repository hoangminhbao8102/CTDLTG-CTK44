void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, LIST& l);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Thuat giai Chon truc tiep";
	cout << "\n4. Thuat giai Chen truc tiep";
	cout << "\n5. Thuat giai Buble";
	cout << "\n6. Thuat giai Merge Sort";
	cout << "\n7. Thuat giai Radix";
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
		cout << "\n3. Thuat giai Chon truc tiep";
		SelectionSort(l);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 4:
		cout << "\n4. Thuat giai Chen truc tiep";
		InsertionSort(l);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 5:
		cout << "\n5. Thuat giai Buble";
		BubbleSort(l);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 6:
		cout << "\n6. Thuat giai Merge Sort";
		MergeSort(l);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	case 7:
		cout << "\n7. Thuat giai Radix";
		RadixSort(l);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSNV(l);
		cout << endl;
		break;
	}
}