void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, SinhVien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Sap xep danh sach sinh vien theo diem trung binh (QuickSort)";
	cout << "\n4. Sap xep danh sach sinh vien theo diem trung binh (HeapSort)";
	cout << "\n5. Sap xep danh sach sinh vien theo diem trung binh (MergeSort)";
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

void XuLyMenu(int menu, SinhVien a[MAX], int& n)
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
		cout << "\n1. Tao danh sach sinh vien.\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach sinh vien.\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Sap xep danh sach sinh vien theo diem trung binh (QuickSort).\n";
		QuickSort(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Sap xep danh sach sinh vien theo diem trung binh (HeapSort).\n";
		HeapSort(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 5:
		system("CLS");
		cout << "\n5. Sap xep danh sach sinh vien theo diem trung binh (MergeSort).\n";
		MergeSort(a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	}
}