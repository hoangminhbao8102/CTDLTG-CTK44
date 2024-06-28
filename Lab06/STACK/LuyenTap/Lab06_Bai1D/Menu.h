void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, STACK& s);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu";
	cout << "\n2. Xuat du lieu";
	cout << "\n3. Them mot node o dau stack";
	cout << "\n4. Huy mot node o dau stack";
	cout << "\n5. Dem so lan xuat hien x trong stack";
	cout << "\n6. Xoa toan bo nhung node co du lieu x trong stack";
	cout << "\n7. Xem du lieu";
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

void XuLyMenu(int menu, STACK& s)
{
	char filename[MAX];
	int kq;
	Data x;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap du lieu\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			_flushall();
			cin >> filename;
			kq = File_Stack(filename, s);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu\n";
		Output_Stack(s);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Them mot node o dau stack\n";
		cout << "\nNhap du lieu cho node moi: ";
		cin >> x;
		Push(s, x);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Huy mot node o dau stack\n";
		if (!IsEmpty(s)) 
		{
			x = Pop(s);
			cout << "\nDu lieu node bi xoa: " << x << endl;
		}
		else 
		{
			cout << "\nStack rong!\n";
		}
		break;
	case 5:
		system("CLS");
		cout << "\n5. Dem so lan xuat hien x trong stack\n";
		cout << "\nNhap gia tri x: ";
		cin >> x;
		cout << "\nSo lan xuat hien cua " << x << " trong stack: " << Count(s, x) << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xoa toan bo nhung node co du lieu x trong stack\n";
		cout << "\nNhap gia tri x can xoa: ";
		cin >> x;
		RemoveAll(s, x);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Xem du lieu\n";
		if (!IsEmpty(s)) 
		{
			x = Top(s);
			cout << "\nDu lieu o dau stack: " << x << endl;
		}
		else 
		{
			cout << "\nStack rong!\n";
		}
		break;
	}
}