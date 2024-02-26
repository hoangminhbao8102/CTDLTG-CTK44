void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, int a[MAX], int b[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Thuat giai Merge Sort";
	cout << "\n4. Thuat giai Heap Sort";
	cout << "\n5. Thuat giai Radix Sort";
	cout << "\n6. Thuat giai Quick Sort";
	cout << "\n====================================================";
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

void XuLyMenu(int menu, int a[MAX], int b[MAX], int& n)
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
		cout << "\n3. Thuat giai Merge Sort";
		MergeSort(a, 0, n - 1);
		cout << "Merge Sort:\n";
		Output(a, n);
		break;
	case 4:
		cout << "\n4. Thuat giai Heap Sort";
		HeapSort(b, n);
		cout << "Heap Sort:\n";
		Output(a, n);
		break;
	case 5:
		cout << "\n5. Thuat giai Radix Sort";
		Copy(a, b, n); // Reset mảng
		RadixSort(a, n);
		cout << "Radix Sort:\n";
		Output(a, n);
		break;
	case 6:
		cout << "\n6. Thuat giai Quick Sort";
		Copy(a, b, n); // Reset mảng
		QuickSort(a, 0, n - 1);
		cout << "Quick Sort:\n";
		Output(a, n);
		break;
	}
}