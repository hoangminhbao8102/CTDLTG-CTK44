void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, LIST_KQTD& l, LIST_KQXH& h);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Xem lich thi dau vong j";
	cout << "\n2. Xem lich thi dau toan giai";
	cout << "\n3. Xem ket qua cac tran dau vong j";
	cout << "\n4. Xem ket qua cac tran dau den vong j (tu vong 1 den vong j)";
	cout << "\n5. Xem ket qua xep hang den vong j";
	cout << "\n6. Xem ket qua xep hang luot di";
	cout << "\n7. Xem ket qua chung cuoc";
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

void XuLyMenu(int menu, LIST_KQTD& l, LIST_KQXH& h)
{
	int j{};
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Xem lich thi dau vong j";
		XuatNgangDoi();
		XuatTieuDe_LTD();
		Xuat_LTD_Vong_j(l, j);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem lich thi dau toan giai";
		XuatNgangDoi();
		XuatTieuDe_LTD();
		for (int i = 1; i <= VongTD_MoiNhat(l); ++i) 
		{
			Xuat_LTD_Vong_j(l, i);
		}
		break;
	case 3:
		system("CLS");
		cout << "\n3. Xem ket qua cac tran dau vong j";
		XuatNgangDoi();
		XuatTieuDe_KQTD();
		Xuat_KQTD_Vong_j(l, j);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Xem ket qua cac tran dau den vong j (tu vong 1 den vong j)";
		XuatNgangDoi();
		XuatTieuDe_KQTD();
		for (int i = 1; i <= j; ++i) 
		{
			Xuat_KQTD_DenVong_j(l, i);
		}
		break;
	case 5:
		system("CLS");
		cout << "\n5. Xem ket qua xep hang den vong j";;
		XuatNgangDoi();
		XuatTieuDe_KQ();
		XepHang_DenVong(h, j);
		Xuat_KQXH(h);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xem ket qua xep hang luot di";
		XuatNgangDoi();
		XuatTieuDe_KQ();
		XepHang_DenVong(h, 0);
		Xuat_KQXH(h);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Xem ket qua chung cuoc";
		XuatNgangDoi();
		XuatTieuDe_KQ();
		Xuat_KQXH(h);
		break;
	}
}