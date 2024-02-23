#define MAX 100

struct SinhVien
{
	char MaSV[8];
	char HoSV[10];
	char TenLot[10];
	char Ten[10];
	char Lop[6];
	int NamSinh;
	double DTB;
	int TichLuy;
};

int TapTin_MangCT(char* filename, SinhVien a[MAX], int& n);
void TieuDe();
void Xuat_SV(SinhVien p);
void Xuat_DSSV(SinhVien a[MAX], int n);
int Tim_MaSo_DauTien(char maSV[10], SinhVien a[MAX], int n);
void Tim_TheoTen(char ten[10], SinhVien a[MAX], int n);
void Tim_TheoHo(char hoSV[10], SinhVien a[MAX], int n);
void Tim_TheoLop(char lop[6], SinhVien a[MAX], int n);
void Tim_TheoDTB(double dtb, SinhVien a[MAX], int n);
int KiemTraDayTang(int x[MAX], int n);
int KiemTraDayGiam(int x[MAX], int n);
void TKNP_Theo_TichLuy(SinhVien a[MAX], int n);
int TKNP_Tang(int x[MAX], int n, int tichLuy);
int TKNP_Giam(int x[MAX], int n, int tichLuy);
void Xuat_TKNP_Theo_TichLuy(int tichLuy, SinhVien a[MAX], int n, int kq);

int TapTin_MangCT(char* filename, SinhVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].MaSV;
		in >> a[n].HoSV;
		in >> a[n].TenLot;
		in >> a[n].Ten;
		in >> a[n].Lop;
		in >> a[n].NamSinh;
		in >> a[n].DTB;
		in >> a[n].TichLuy;
		n++;
	}
	in.close();
	return 1;
}

void TieuDe()
{
	int i;
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(9) << "Ma SV"
		<< ':'
		<< setw(30) << " Ho va Ten sinh vien"
		<< ':'
		<< setw(10) << "Lop"
		<< ':'
		<< setw(6) << "NS"
		<< ':'
		<< setw(6) << "DTB"
		<< ':'
		<< setw(8) << "TichLuy"
		<< ':';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Xuat_SV(SinhVien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(9) << p.MaSV
		<< ':'
		<< setw(10) << p.HoSV
		<< setw(10) << p.TenLot
		<< setw(10) << p.Ten
		<< ':'
		<< setw(10) << p.Lop
		<< ':'
		<< setw(6) << p.NamSinh
		<< ':'
		<< setw(6) << setiosflags(ios::fixed) << setprecision(2) << p.DTB
		<< ':'
		<< setw(8) << p.TichLuy
		<< ':';
}

void Xuat_DSSV(SinhVien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat_SV(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

int Tim_MaSo_DauTien(char maSV[10], SinhVien a[MAX], int n)
{
	int i = 0;
	while ((i < n) && (_stricmp(a[i].MaSV, maSV)))
		i++;
	if (i == n)
		return -1;
	return i;
}

void Tim_TheoTen(char ten[10], SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].Ten, ten) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co ten sinh vien : " << ten;
	else
	{
		cout << "\nthong tin sinh vien trong danh sach co ten " << ten;
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].Ten, ten) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

void Tim_TheoHo(char hoSV[10], SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].HoSV, hoSV) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nDanh sach khong co sinh vien mang ho : " << hoSV;
	else
	{
		cout << "\nCac sinh vien trong danh sach mang ho " << hoSV << " :\n";
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].HoSV, hoSV) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

void Tim_TheoLop(char lop[6], SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (_stricmp(a[i].Lop, lop) == 0)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co lop : " << lop;
	else
	{
		cout << "\nCac sinh vien trong danh sach thuoc lop " << lop << " :\n";
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (_stricmp(a[i].Lop, lop) == 0)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

void Tim_TheoDTB(double dtb, SinhVien a[MAX], int n)
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
		if (a[i].DTB >= dtb)
		{
			kq = 1;
			break;
		}
	if (kq == -1)
		cout << "\nKhong co sinh vien nao co diem trung binh >= " << dtb;
	else
	{
		cout << "\nCac sinh vien trong danh sach co diem trung bin >= " << dtb << " :\n";
		cout << endl;
		TieuDe();
		for (i = 0; i < n; i++)
			if (a[i].DTB >= dtb)
			{
				cout << endl;
				Xuat_SV(a[i]);
			}
	}
}

int KiemTraDayTang(int x[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
		if (x[i] > x[i + 1])
		{
			kq = 0;
			break;
		}
	return kq;
}

int KiemTraDayGiam(int x[MAX], int n)
{
	int i, kq = 1;
	for (i = 0; i < n - 1; i++)
		if (x[i] < x[i + 1])
		{
			kq = 0;
			break;
		}
	return kq;
}

void TKNP_Theo_TichLuy(SinhVien a[MAX], int n)
{
	int i, kq;
	int x[MAX];
	for (i = 0; i < n; i++)
		x[i] = a[i].TichLuy;
	if (!KiemTraDayGiam(x, n) && !KiemTraDayTang(x, n))
	{
		cout << "\nDay so nguyen tao boi truong tich luy khong don dieu";
		cout << "\nKhong su dung duoc thuat giai tim kiem nhi phan!\n";
		return;
	}
	int tichLuy;
	cout << "\nNhap so tich luy : ";
	cin >> tichLuy;
	if (KiemTraDayTang(x, n))
	{
		kq = TKNP_Tang(x, n, tichLuy);
		Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
	}
	if (KiemTraDayGiam(x, n))
	{
		kq = TKNP_Giam(x, n, tichLuy);
		Xuat_TKNP_Theo_TichLuy(tichLuy, a, n, kq);
	}
}

int TKNP_Tang(int x[MAX], int n, int tichLuy)
{
	int kq = -1, midle, left = 0, right = n - 1;
	do
	{
		midle = (left + right) / 2;
		if (tichLuy == x[midle])
		{
			kq = midle;
			break;
		}
		else
			if (tichLuy < x[midle])
				right = midle - 1;
			else
				left = midle + 1;
	} while (left <= right);
	return kq;
}

int TKNP_Giam(int x[MAX], int n, int tichLuy)
{
	int kq = -1, midle, left = 0, right = n - 1;
	do
	{
		midle = (left + right) / 2;
		if (tichLuy == x[midle])
		{
			kq = midle;
			break;
		}
		else
			if (tichLuy < x[midle])
				left = midle + 1;
			else
				right = midle - 1;
	} while (left <= right);
	return kq;
}

void Xuat_TKNP_Theo_TichLuy(int tichLuy, SinhVien a[MAX], int n, int kq)
{
	if (kq == -1)
	{
		cout << "\nKhong co sinh vien trong danh sach co so TC tich luy == " << tichLuy << " :\n";
		return;
	}
	else
	{
		cout << "\nThong tin sinh vien trong danh sach co so TC tich luy == " << tichLuy << " :\n";
		TieuDe();
		cout << endl;
		Xuat_SV(a[kq]);
		cout << endl;
		return;
	}
}