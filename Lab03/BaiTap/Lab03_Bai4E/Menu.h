void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, NhanVien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Sap tang dan theo muc luong theo Quick Sort";
	cout << "\n4. Sap tang dan theo muc luong theo Heap Sort";
	cout << "\n5. Sap tang dan theo muc luong theo Merge Sort";
	cout << "\n6. Sap tang dan theo muc luong theo Shaker Sort";
	cout << "\n7. Neu cung muc luong, sap tang dan theo ten";
	cout << "\n8. Neu cung luong, ten, sap tang dan theo ho";
	cout << "\n9. Neu cung luong, ten, ho, sap tang dan theo nam sinh";
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

void XuLyMenu(int menu, NhanVien a[MAX], int& n)
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
		cout << "\n3. Sap tang dan theo muc luong theo Quick Sort";
		QuickSort(a, 0, n - 1);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 4:
		cout << "\n4. Sap tang dan theo muc luong theo Heap Sort";
		HeapSort(a, n);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 5:
		cout << "\n5. Sap tang dan theo muc luong theo Merge Sort";
		MergeSort(a, 0, n - 1);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 6:
		cout << "\n6. Sap tang dan theo muc luong theo Shaker Sort";
		ShakerSort(a, n);
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 7:
		cout << "\n7. Neu cung muc luong, sap tang dan theo ten";
		//Sử dụng QuickSort
		QuickSort(a, 0, n - 1);
		break;
	case 8:
		cout << "\n8. Neu cung luong, ten, sap tang dan theo ho";
		//Sử dụng QuickSort
		QuickSort(a, 0, n - 1);
		break;
	case 9:
		cout << "\n9. Neu cung luong, ten, ho, sap tang dan theo nam sinh";
		//Sử dụng QuickSort
		QuickSort(a, 0, n - 1);
		break;
	}
}