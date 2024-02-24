void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Chon truc tiep (Selection Straight sort)";
	cout << "\n4. Chen truc tiep (Insertion Straight sort)";
	cout << "\n5. Doi cho truc tiep (Interchange Straight sort)";
	cout << "\n6. Noi bot (Bubble sort)";
	cout << "\n7. Chen nhi phan (Binary Insertion Sort)";
	cout << "\n8. Radix";
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
	int kq;
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
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao:\n";
		Output(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu";
		cout << "\nMang vua tao:\n";
		Output(a, n);
		break;
	case 3:
		cout << "\n3. Chon truc tiep (Selection Straight sort)";
		Selection_L(a, n);
		Output(a, n);
		break;
	case 4:
		cout << "\n4. Chen truc tiep (Insertion Straight sort)";
		Insertion_L(a, n); 
		Output(a, n);
		break;
	case 5:
		cout << "\n5. Doi cho truc tiep (Interchange Straight sort)";
		Interchange_L(a, n);
		Output(a, n);
		break;
	case 6:
		cout << "\n6. Noi bot (Bubble sort)";
		Buble_L(a, n);
		Output(a, n);
		break;
	case 7:
		cout << "\n7. Chen nhi phan (Binary Insertion Sort)";
		Binary_Insertion(a, n);
		Output(a, n);
		break;
	case 8:
		cout << "\n8. Radix";
		Radix(a, n); 
		Output(a, n);
		break;
	}
}