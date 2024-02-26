void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Thuat giai Chon Truc tiep";
	cout << "\n4. Thuat giai Chen Truc tiep";
	cout << "\n5. Thuat giai Doi cho Truc tiep";
	cout << "\n6. Thuat giai Buble";
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

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq, comparisonCount = 0, swapCount = 0;
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
		cout << "\n3. Thuat giai Chon Truc tiep";
		SelectionSort(a, n, comparisonCount, swapCount);
		cout << "So lan so sanh: " << comparisonCount << endl;
		cout << "So lan hoan vi: " << swapCount << endl;
		cout << "Mang sau khi sap xep:\n";
		Output(a, n);
		break;
	case 4:
		cout << "\n4. Thuat giai Chen Truc tiep";
		InsertionSort(a, n, comparisonCount, swapCount);
		cout << "So lan so sanh: " << comparisonCount << endl;
		cout << "So lan hoan vi: " << swapCount << endl;
		cout << "Mang sau khi sap xep:\n";
		Output(a, n);
		break;
	case 5:
		cout << "\n5. Thuat giai Doi cho Truc tiep";
		ExchangeSort(a, n, comparisonCount, swapCount);
		cout << "So lan so sanh: " << comparisonCount << endl;
		cout << "So lan hoan vi: " << swapCount << endl;
		cout << "Mang sau khi sap xep:\n";
		Output(a, n);
		break;
	case 6:
		cout << "\n6. Thuat giai Buble";
		BubbleSort(a, n, comparisonCount, swapCount);
		cout << "So lan so sanh: " << comparisonCount << endl;
		cout << "So lan hoan vi: " << swapCount << endl;
		cout << "Mang sau khi sap xep:\n";
		Output(a, n);
		break;
	}
}