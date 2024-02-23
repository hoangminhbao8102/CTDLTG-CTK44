void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
	cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co(Co linh canh)";
	cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
	cout << "\n6. Tra ve tat ca chi so i neu co.";
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

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int x, kq;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_Mang1C(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		Xuat_Mang(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu";
		cout << "\nMang vua tao:\n";
		Xuat_Mang(a, n);
		cout << endl;
		break;
	case 3:
		cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		kq = TKTT_DauTien(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hien trong a tai vi tri dau tien la : " << kq;
		cout << endl;
		break;
	case 4:
		cout << "\n4. Tim kiem tuyen tinh (co linh canh)- Tra ve chi so dau tien";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		kq = TKTT_DauTien_LC(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hien trong a tai vi tri dau tien la : " << kq;
		cout << endl;
		break;
	case 5:
		cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		kq = TKTT_CuoiCung(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hien trong a tai vt cuoi cung la:" << kq;
		cout << endl;
		break;
	case 6:
		cout << "\n6. Tra ve tat ca chi so i neu co.";
		cout << "\nMang du lieu ban dau:\n";
		Xuat_Mang(a, n);
		cout << "\nNhap x = ";
		cin >> x;
		TKTT_CacChiSo(a, n, x);
		cout << endl;
		break;
	}
}