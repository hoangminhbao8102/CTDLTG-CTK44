void XuatMenu();
int ChonMenu(int SoMenu);
void XuLyMenu(int menu, NhanVien a[MAX], int& n);

void XuatMenu()
{
	cout << "\n================ He thong chuc nang ===============";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach nhan vien";
	cout << "\n2. Xem danh sach nhan vien";
	cout << "\n3. Tim kiem theo ho, ten: Xuat tat ca cac nhan vien trung ho va ten cho truoc.";
	cout << "\n4. Tim kiem nam sinh: Xuat tat ca cac nhan vien cung nam sinh";
	cout << "\n5. Tim kiem theo ho, ten va nam sinh: Xuat tat ca cac nhan vien trung ho, ten cho truoc va co nam sinh < x";
	cout << "\n6. Tim kiem theo ten và dia chi : Xuat tat ca nhan vien cung ten va dia chi cho truoc";
	cout << "\n7. Tim kiem theo nam sinh va luong : Xuat cac nhan vien co muc luong >= x va co nam sinh <= y";
	cout << "\n8. Tim kiem nhi phan theo ma nhan vien khi cho truoc ma nhan vien (can phai kiem tra tinh don dieu cua du lieu)";
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
	char filename[MAX], maNV[8], hoTen[30], ten[10], diaChi[15];
	NTNS ntns;
	double luong;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach nhan vien.\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach nhan vien vua nhap:\n";
		Xuat_DSNV(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach sinh vien.\n";
		cout << "\nDanh sach nhan vien hien hanh:\n";
		Xuat_DSNV(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Tim kiem theo ho, ten: Xuat tat ca cac nhan vien trung ho va ten cho truoc.";
		cout << "\nNhap ho va ten can tim: ";
		cin.ignore();
		cin.getline(hoTen, 30);
		Tim_TheoHoTen(hoTen, a, n);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem nam sinh: Xuat tat ca cac nhan vien cung nam sinh";
		cout << "\nNhap ngay sinh (dd mm yyyy): ";
		cin >> ntns.NgaySinh >> ntns.ThangSinh >> ntns.NamSinh;
		Tim_TheoNamSinh(ntns, a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo ho, ten va nam sinh: Xuat tat ca cac nhan vien trung ho, ten cho truoc va co nam sinh < x";
		cout << "\nNhap ho va ten can tim: ";
		cin.ignore();
		cin.getline(hoTen, 30);
		cout << "\nNhap nam sinh: ";
		cin >> ntns.NamSinh;
		Tim_TheoHoTenNamSinh(hoTen, ntns, a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Tim kiem theo ten và dia chi : Xuat tat ca nhan vien cung ten va dia chi cho truoc";
		cout << "\nNhap ten nhan vien: ";
		cin.ignore();
		cin.getline(ten, 10);
		cout << "\nNhap dia chi: ";
		cin.getline(diaChi, 15);
		Tim_TheoTenDiaChi(ten, diaChi, a, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo nam sinh va luong : Xuat cac nhan vien co muc luong >= x va co nam sinh <= y";
		cout << "\nNhap nam sinh: ";
		cin >> ntns.NamSinh;
		cout << "\nNhap muc luong: ";
		cin >> luong;
		Tim_TheoNamSinhLuong(ntns, luong, a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim kiem nhi phan theo ma nhan vien khi cho truoc ma nhan vien (can phai kiem tra tinh don dieu cua du lieu)";
		cout << "\nNhap ma nhan vien can tim: ";
		cin >> maNV;
		kq = Tim_NhanVien_BinarySearch(maNV, a, n);
		if (kq == -1)
			cout << "\nKhong tim thay nhan vien co ma " << maNV << endl;
		else {
			cout << "\nTim thay nhan vien co ma " << maNV << ": \n";
			Xuat_NV(a[kq]);
		}
		break;
	}
}