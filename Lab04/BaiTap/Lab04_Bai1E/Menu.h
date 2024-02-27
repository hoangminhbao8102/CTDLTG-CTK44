void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, LIST& l);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu"; 
    cout << "\n3. Tinh gia tri nho nhat cua danh sach";
    cout << "\n4. Tinh gia tri lon nhat cua danh sach";
    cout << "\n5. Dem gia tri x xuat hien bao nhieu lan trong danh sach";
    cout << "\n6. Tinh tong cac gia tri trong danh sach";
    cout << "\n7. Tinh tong cac gia tri khac nhau trong danh sach";
    cout << "\n8. Xuat cac gia tri khac nhau trong danh sach va so lan xuat hien";
    cout << "\n9. Sap xep danh sach tang dan bang thuat giai chen truc tiep";
    cout << "\n10. Sap xep danh sach theo yeu cau: Gia tri 0 xuat hien tai cac nut dau danh sach, Tiep theo la cac nut co gia tri am giam dan, Cuoi cung la cac nut co gia tri duong tang dan";
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

void XuLyMenu(int menu, LIST& l)
{
    char filename[MAX];
    DataType x, y;
    int kq;
    LIST l1;
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
            _flushall();
            cin >> filename;
            kq = File_List(filename, l);
            if (!kq)
                cout << "\nLoi mo file ! nhap lai\n";
        } while (!kq);
        cout << "\nDanh sach nhap co " << SoNut(l) << " phan tu : \n\n";
        XuatDS(l);
        cout << endl;
        break;
    case 2:
        system("CLS");
        cout << "\n2. Xem du lieu";
        cout << "\nDanh sach l co " << SoNut(l) << " phan tu : \n";
        XuatDS(l);
        cout << endl;
        break;
    case 3:
        system("CLS");
        cout << "\n3. Tinh gia tri nho nhat cua danh sach";
        cout << MinValue(l) << endl;
        break;
    case 4:
        system("CLS");
        cout << "\n4. Tinh gia tri lon nhat cua danh sach";
        cout << MaxValue(l) << endl;
        break;
    case 5:
        system("CLS");
        cout << "\n5. Dem gia tri x xuat hien bao nhieu lan trong danh sach";
        cout << "Nhap gia tri x: ";
        cin >> x;
        cout << "So lan xuat hien cua gia tri " << x << " trong danh sach la: " << CountValue(l, x) << endl;
        break;
    case 6:
        system("CLS");
        cout << "\n6. Tinh tong cac gia tri trong danh sach";
        cout << SumValues(l) << endl;
        break;
    case 7:
        system("CLS");
        cout << "\n7. Tinh tong cac gia tri khac nhau trong danh sach";
        cout << SumDistinctValues(l) << endl;
        break;
    case 8:
        system("CLS");
        cout << "\n8. Xuat cac gia tri khac nhau trong danh sach va so lan xuat hien";
        UniqueValuesCount(l);
        break;
    case 9:
        system("CLS");
        cout << "\n9. Sap xep danh sach tang dan bang thuat giai chen truc tiep";
        InsertionSort(l);
        cout << "Danh sach sau khi sap xep: ";
        XuatDS(l);
        cout << endl;
        break;
    case 10:
        system("CLS");
        cout << "\n10. Sap xep danh sach theo yeu cau: Gia tri 0 xuat hien tai cac nut dau danh sach, Tiep theo la cac nut co gia tri am giam dan, Cuoi cung la cac nut co gia tri duong tang dan";
        SortList(l);
        cout << "Danh sach sau khi sap xep: ";
        XuatDS(l);
        cout << endl;
        break;
    default:
        cout << "\nLua chon khong hop le. Vui long chon lai.\n";
        break;
    }
}