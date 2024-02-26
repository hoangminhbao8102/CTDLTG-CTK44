void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, int a[MAX], int b[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n5. Thuat giai Chon hai dau";
	cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Thuat giai Chen nhi phan";
	cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11. Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12. Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
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
		cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
		SelectionSort_MinToMax(a, n);
		cout << "Selection Sort - GTNN ve dau mang:\n";
		Output(a, n);
		break;
	case 4:
		cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
		SelectionSort_MaxToMin(b, n);
		cout << "Selection Sort - GTLN ve cuoi mang:\n";
		Output(a, n);
		break;
	case 5:
		cout << "\n5. Thuat giai Chon hai dau";
		Copy(a, b, n); // Reset mảng
		SelectionSort_TwoEnds(a, n);
		cout << "Selection Sort - Hai dau:\n";
		Output(a, n);
		break;
	case 6:
		cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
		Copy(a, b, n); // Reset mảng
		InsertionSort_InsertToLeft(a, n);
		cout << "Insertion Sort - Chen vao day con tang ben trai:\n";
		Output(a, n);
		break;
	case 7:
		cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
		Copy(a, b, n); // Reset mảng
		InsertionSort_InsertToRight(a, n);
		cout << "Insertion Sort - Chen vao day con tang ben phai:\n";
		Output(a, n);
		break;
	case 8:
		cout << "\n8. Thuat giai Chen nhi phan";
		Copy(a, b, n); // Reset mảng
		BinaryInsertionSort(a, n);
		cout << "Binary Insertion Sort:\n";
		Output(a, n);
		break;
	case 9:
		cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
		Copy(a, b, n); // Reset mảng
		ExchangeSort_MinToMax(a, n);
		cout << "Exchange Sort - GTNN ve dau mang:\n";
		Output(a, n);
		break;
	case 10:
		cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
		Copy(a, b, n); // Reset mảng
		ExchangeSort_MaxToMin(a, n);
		cout << "Exchange Sort - GTLN ve cuoi mang:\n";
		Output(a, n);
		break;
	case 11:
		cout << "\n11. Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
		Copy(a, b, n); // Reset mảng
		BubbleSort_MinToMax(a, n);
		cout << "Bubble Sort - GTNN ve dau mang:\n";
		Output(a, n);
		break;
	case 12:
		cout << "\n12. Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
		Copy(a, b, n); // Reset mảng
		BubbleSort_MaxToMin(a, n);
		cout << "Bubble Sort - GTLN ve cuoi mang:\n";
		Output(a, n);
		break;
	}
}