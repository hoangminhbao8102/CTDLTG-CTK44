void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, SET& l);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Nhap du lieu cho tap hop";
	cout << "\n2. Xem du lieu tap hop";
	cout << "\n3. Giao 2 tap hop";
	cout << "\n4. Hop 2 tap hop";
	cout << "\n5. Hieu 2 tap hop";
	cout << "\n6. Hieu doi xung 2 tap hop";
	cout << "\n7. Tich Descartes 2 tap hop";
	cout << "\n8. Kiem tra phan tu co thuoc vao tap hop";
	cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop";
	cout << "\n10. Tinh luc luong tap hop";
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

void XuLyMenu(int menu, SET& l)
{
	char filename[MAX];
	int kq;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Nhap du lieu cho tap hop";
		cout << "Nhap ten file: ";
		cin >> filename;
		kq = File_List(filename, l);
		if (kq)
			cout << "Da nhap du lieu tu file thanh cong.\n";
		else
			cout << "Loi! Khong the mo file.\n";
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem du lieu tap hop";
		cout << "\n2. Xem du lieu tap hop\n";
		XuatDS(l);
		break;
	case 3:
		system("CLS");
		cout << "\n3. Giao 2 tap hop";
		SET l2;
		CreatList(l2);
		cout << "Nhap ten file cho tap hop thu hai: ";
		cin >> filename;
		kq = File_List(filename, l2);
		if (!kq) {
			cout << "Loi! Khong the mo file.\n";
			break;
		}
		SET giao = Giao(l, l2);
		cout << "Tap hop giao: ";
		XuatDS(giao);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Hop 2 tap hop";
		SET l2;
		CreatList(l2);
		cout << "Nhap ten file cho tap hop thu hai: ";
		cin >> filename;
		kq = File_List(filename, l2);
		if (!kq) {
			cout << "Loi! Khong the mo file.\n";
			break;
		}
		SET hop = Hop(l, l2);
		cout << "Tap hop hop: ";
		XuatDS(hop);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Hieu 2 tap hop";
		SET l2;
		CreatList(l2);
		cout << "Nhap ten file cho tap hop thu hai: ";
		cin >> filename;
		kq = File_List(filename, l2);
		if (!kq) {
			cout << "Loi! Khong the mo file.\n";
			break;
		}
		SET hieu = Hieu(l, l2);
		cout << "Tap hop hieu: ";
		XuatDS(hieu);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Hieu doi xung 2 tap hop";
		SET l2;
		CreatList(l2);
		cout << "Nhap ten file cho tap hop thu hai: ";
		cin >> filename;
		kq = File_List(filename, l2);
		if (!kq) {
			cout << "Loi! Khong the mo file.\n";
			break;
		}
		SET hieu_doi_xung = HieuDoiXung(l, l2);
		cout << "Tap hop hieu doi xung: ";
		XuatDS(hieu_doi_xung);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tich Descartes 2 tap hop";
		SET l2;
		CreatList(l2);
		cout << "Nhap ten file cho tap hop thu hai: ";
		cin >> filename;
		kq = File_List(filename, l2);
		if (!kq) {
			cout << "Loi! Khong the mo file.\n";
			break;
		}
		cout << "Tich Descartes: ";
		TichDescartes(l, l2);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Kiem tra phan tu co thuoc vao tap hop";
		DataType element;
		cout << "Nhap phan tu can kiem tra: ";
		cin >> element;
		if (IsExist(l, element))
			cout << "Phan tu " << element << " thuoc tap hop.\n";
		else
			cout << "Phan tu " << element << " khong thuoc tap hop.\n";
		break;
	case 9:
		system("CLS");
		cout << "\n9. Kiem tra quan he bao ham giua 2 tap hop";
		SET l2;
		CreatList(l2);
		cout << "Nhap ten file cho tap hop thu hai: ";
		cin >> filename;
		kq = File_List(filename, l2);
		if (!kq) {
			cout << "Loi! Khong the mo file.\n";
			break;
		}
		if (IsSubset(l, l2))
			cout << "Tap hop 1 bao ham tap hop 2.\n";
		else
			cout << "Tap hop 1 khong bao ham tap hop 2.\n";
		break;
	case 10:
		system("CLS");
		cout << "\n10. Tinh luc luong tap hop";
		cout << "Luc luong cua tap hop: " << Cardinality(l) << endl;
		break;
	}
}