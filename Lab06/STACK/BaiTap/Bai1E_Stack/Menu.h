void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, STACK& s1, STACK& s2);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu";
	cout << "\n2. Xuat du lieu";
	cout << "\n3. Tong 2 so nguyen lon";
	cout << "\n4. Hieu 2 so nguyen";
	cout << "\n5. Tich 2 so nguyen";
	cout << "\n6. Xem cac so";
	cout << "\n7. Chon cac so khac";
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

void XuLyMenu(int menu, STACK& s1, STACK& s2)
{
	char filename1[100], filename2[100];
	STACK result;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap du lieu\n";
		cout << "Nhap ten file cho so thu nhat: ";
		cin >> filename1;
		File_Stack(filename1, s1);
		cout << "Nhap ten file cho so thu hai: ";
		cin >> filename2;
		File_Stack(filename2, s2);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xuat du lieu\n";
		cout << "So thu nhat: ";
		Output_Stack(s1);
		cout << "\nSo thu hai: ";
		Output_Stack(s2);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tong 2 so nguyen lon\n";
		result = AddNumbers(s1, s2);
		cout << "Ket qua: ";
		Output_Stack(result);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Hieu 2 so nguyen\n";
		result = SubtractNumbers(s1, s2);
		cout << "Ket qua: ";
		Output_Stack(result);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tich 2 so nguyen\n";
		result = MultiplyNumbers(s1, s2);
		cout << "Ket qua: ";
		Output_Stack(result);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xem cac so\n";
		cout << "So thu nhat: ";
		Output_Stack(s1);
		cout << "\nSo thu hai: ";
		Output_Stack(s2);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Chon cac so khac\n";
		cout << "Nhap ten file moi cho so thu nhat: ";
		cin >> filename1;
		File_Stack(filename1, s1);
		cout << "Nhap ten file moi cho so thu hai: ";
		cin >> filename2;
		File_Stack(filename2, s2);
		break;
	}
}