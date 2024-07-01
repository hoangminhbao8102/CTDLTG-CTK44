void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, QUEUE& q);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu";
	cout << "\n2. Xuat du lieu";
	cout << "\n3. Them mot gia tri vao cuoi QUEUE";
	cout << "\n4. Huy node dau QUEUE";
	cout << "\n5. Dem so lan xuat hien x trong QUEUE";
	cout << "\n6. Xoa toan bo nhung node co du lieu x trong QUEUE";
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

void XuLyMenu(int menu, QUEUE& q)
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
			kq = File_Queue(filename, q);
			if (!kq)
				cout << "\nLoi mo file ! nhap lai\n";
		} while (!kq);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu\n";
		Output_Queue(q);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Them mot gia tri vao cuoi QUEUE\n";
		cout << "\nNhap gia tri can them: ";
		cin >> x;
		Enqueue(q, x);
		cout << "\nDa them gia tri vao cuoi QUEUE\n";
		break;
	case 4:
		system("CLS");
		cout << "\n4. Huy node dau QUEUE\n";
		if (IsEmpty(q))
		{
			cout << "\nQUEUE rong, khong co phan tu de xoa\n";
		}
		else
		{
			x = Dequeue(q);
			cout << "\nGia tri node dau QUEUE vua bi xoa: " << x << endl;
		}
		break;
	case 5:
		system("CLS");
		cout << "\n5. Dem so lan xuat hien x trong QUEUE\n";
		cout << "\nNhap gia tri x: ";
		cin >> x;
		kq = Count(q, x);
		cout << "\nSo lan xuat hien cua " << x << " trong QUEUE la: " << kq << endl;
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xoa toan bo nhung node co du lieu x trong QUEUE\n";
		cout << "\nNhap gia tri x can xoa: ";
		cin >> x;
		RemoveAll(q, x);
		cout << "\nDa xoa toan bo nhung node co du lieu " << x << " trong QUEUE\n";
		break;
	case 7:
		system("CLS");
		cout << "\n7. Xem du lieu\n";
		if (IsEmpty(q))
		{
			cout << "\nQUEUE rong!\n";
		}
		else
		{
			cout << "\nGia tri cua node dau QUEUE la: " << Top(q) << endl;
		}
		break;
	}
}