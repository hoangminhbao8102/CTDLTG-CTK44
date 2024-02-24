#define MAX 100

typedef unsigned short int Byte;

struct NTNS
{
	Byte NgaySinh;
	Byte ThangSinh;
	unsigned int NamSinh;
};

struct NhanVien
{
	char MaNV[8];
	char HoNV[10];
	char TenLot[10];
	char TenNV[10];
	NTNS NTNS;
	char DiaChi[15];
	double Luong;
};

int TapTin_MangCT(char* filename, NhanVien a[MAX], int& n);
void TieuDe();
void Xuat_NV(NhanVien p);
void Xuat_DSNV(NhanVien a[MAX], int n);
void Tim_TheoHoTen(char hoTen[30], NhanVien a[MAX], int n);
void Tim_TheoNamSinh(NTNS ntns, NhanVien a[MAX], int n);
void Tim_TheoHoTenNamSinh(char hoTen[30], NTNS ntns, NhanVien a[MAX], int n);
void Tim_TheoTenDiaChi(char ten[10], char diaChi[15], NhanVien a[MAX], int n);
void Tim_TheoNamSinhLuong(NTNS ntns, double luong, NhanVien a[MAX], int n);
int Tim_NhanVien_BinarySearch(char maNV[8], NhanVien a[MAX], int n);

int TapTin_MangCT(char* filename, NhanVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].MaNV;
		in >> a[n].HoNV;
		in >> a[n].TenLot;
		in >> a[n].TenNV;
		in >> a[n].NTNS.NgaySinh;
		in.ignore();
		in >> a[n].NTNS.ThangSinh;
		in.ignore();
		in >> a[n].NTNS.NamSinh;
		in >> a[n].DiaChi;
		in >> a[n].Luong;
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
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Ten Lot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(11) << "NTN sinh"
		<< ':'
		<< setw(15) << "Dia Chi"
		<< ':'
		<< setw(10) << "Luong"
		<< ':';
	cout << "\n";
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Xuat_NV(NhanVien p)
{
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(8) << p.MaNV
		<< ':'
		<< setw(10) << p.HoNV
		<< setw(10) << p.TenLot
		<< setw(10) << p.TenNV
		<< ':'
		<< setw(2) << p.NTNS.NgaySinh
		<< '/'
		<< setw(2) << p.NTNS.ThangSinh
		<< '/'
		<< setw(4) << p.NTNS.NamSinh
		<< ':'
		<< setw(15) << p.DiaChi
		<< ':'
		<< setw(10) << setiosflags(ios::fixed) << setprecision(2) << p.Luong
		<< ':';
}

void Xuat_DSNV(NhanVien a[MAX], int n)
{
	int i;
	TieuDe();
	for (i = 0; i < n; i++)
	{
		Xuat_NV(a[i]);
		if ((i + 1) % 5 == 0 && i != n - 1) 
		{
			cout << "\n:";
			for (int j = 1; j <= 74; j++)
				cout << '-';
			cout << ':';
		}
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Tim_TheoHoTen(char hoTen[30], NhanVien a[MAX], int n) 
{
	int found = 0;
	TieuDe();
	for (int i = 0; i < n; i++) 
	{
		char fullName[20];
		strcpy(fullName, a[i].HoNV);
		strcat(fullName, " ");
		strcat(fullName, a[i].TenLot);
		strcat(fullName, " ");
		strcat(fullName, a[i].TenNV);
		if (strcmpi(fullName, hoTen) == 0) 
		{
			Xuat_NV(a[i]);
			found = 1;
		}
	}
	if (!found)
		cout << "Khong tim thay nhan vien nao co ho ten la " << hoTen << endl;
}

void Tim_TheoNamSinh(NTNS ntns, NhanVien a[MAX], int n) 
{
	int found = 0;
	TieuDe();
	for (int i = 0; i < n; i++) 
	{
		if (a[i].NTNS.NamSinh == ntns.NamSinh && a[i].NTNS.ThangSinh == ntns.ThangSinh && a[i].NTNS.NgaySinh == ntns.NgaySinh) 
		{
			Xuat_NV(a[i]);
			found = 1;
		}
	}
	if (!found)
		cout << "Khong tim thay nhan vien nao co nam sinh la " << ntns.NgaySinh << "/" << ntns.ThangSinh << "/" << ntns.NamSinh << endl;
}

void Tim_TheoHoTenNamSinh(char hoTen[30], NTNS ntns, NhanVien a[MAX], int n) 
{
	int found = 0;
	TieuDe();
	for (int i = 0; i < n; i++) 
	{
		char fullName[20];
		strcpy(fullName, a[i].HoNV);
		strcat(fullName, " ");
		strcat(fullName, a[i].TenLot);
		strcat(fullName, " ");
		strcat(fullName, a[i].TenNV);
		if (strcmpi(fullName, hoTen) == 0 && (a[i].NTNS.NamSinh < ntns.NamSinh || (a[i].NTNS.NamSinh == ntns.NamSinh && a[i].NTNS.ThangSinh < ntns.ThangSinh) || (a[i].NTNS.NamSinh == ntns.NamSinh && a[i].NTNS.ThangSinh == ntns.ThangSinh && a[i].NTNS.NgaySinh < ntns.NgaySinh))) 
		{
			Xuat_NV(a[i]);
			found = 1;
		}
	}
	if (!found)
		cout << "Khong tim thay nhan vien nao co ho ten la " << hoTen << " va nam sinh nho hon " << ntns.NgaySinh << "/" << ntns.ThangSinh << "/" << ntns.NamSinh << endl;
}

void Tim_TheoTenDiaChi(char ten[10], char diaChi[15], NhanVien a[MAX], int n) 
{
	int found = 0;
	TieuDe();
	for (int i = 0; i < n; i++) {
		if (strcmpi(a[i].TenNV, ten) == 0 && strcmpi(a[i].DiaChi, diaChi) == 0) 
		{
			Xuat_NV(a[i]);
			found = 1;
		}
	}
	if (!found)
		cout << "Khong tim thay nhan vien nao co ten la " << ten << " va dia chi la " << diaChi << endl;
}

void Tim_TheoNamSinhLuong(NTNS ntns, double luong, NhanVien a[MAX], int n) 
{
	int found = 0;
	TieuDe();
	for (int i = 0; i < n; i++) 
	{
		if ((a[i].NTNS.NamSinh < ntns.NamSinh || (a[i].NTNS.NamSinh == ntns.NamSinh && a[i].NTNS.ThangSinh < ntns.ThangSinh) || (a[i].NTNS.NamSinh == ntns.NamSinh && a[i].NTNS.ThangSinh == ntns.ThangSinh && a[i].NTNS.NgaySinh <= ntns.NgaySinh)) && a[i].Luong >= luong) 
		{
			Xuat_NV(a[i]);
			found = 1;
		}
	}
	if (!found)
		cout << "Khong tim thay nhan vien nao co nam sinh nho hon hoac bang " << ntns.NgaySinh << "/" << ntns.ThangSinh << "/" << ntns.NamSinh << " va luong >= " << luong << endl;
}

int Tim_NhanVien_BinarySearch(char maNV[8], NhanVien a[MAX], int n) 
{
	int left = 0, right = n - 1;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		int compareResult = strcmp(a[mid].MaNV, maNV);
		if (compareResult == 0)
			return mid;
		else if (compareResult < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}