#define MAX 100

struct NhanVien
{
	char MaNV[8];
	char Ho[10];
	char TenLot[10];
	char Ten[10];
	char DiaChi[15];
	int NamSinh;
	double Luong;
};

int File_Array(char* filename, NhanVien a[MAX], int& n);
void Output_Arr(NhanVien a[MAX], int n);
void Output_Struct(NhanVien p);
void Heading();

void HoanVi(NhanVien& x, NhanVien& y);
void Copy(NhanVien b[MAX], NhanVien a[MAX], int n);

void SelectionSort_MaNV(NhanVien a[MAX], int n);
void InsertionSort_DiaChi(NhanVien a[MAX], int n);
void CountingSort_NamSinh(NhanVien a[MAX], int n, int exp);
void RadixSort_NamSinh(NhanVien a[MAX], int n);

int File_Array(char* filename, NhanVien a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	n = 0;
	while (!in.eof())
	{
		in >> a[n].MaNV;
		in >> a[n].Ho;
		in >> a[n].TenLot;
		in >> a[n].Ten;
		in >> a[n].DiaChi;
		in >> a[n].NamSinh;
		in >> a[n].Luong;
		n++;
	}
	in.close();
	return 1;
}

void Output_Struct(NhanVien p)
{
	cout << ':';
	cout << setiosflags(ios::left)
		<< setw(10) << p.MaNV
		<< ':'
		<< setw(10) << p.Ho
		<< setw(10) << p.TenLot
		<< setw(10) << p.Ten
		<< ':'
		<< setw(20) << p.DiaChi
		<< ':'
		<< setw(5) << p.NamSinh
		<< ':'
		<< setw(10) << setiosflags(ios::fixed) << setprecision(2) << p.Luong
		<< ':';
}

void Output_Arr(NhanVien a[MAX], int n)
{
	int i;
	Heading();
	for (i = 0; i < n; i++)
	{
		Output_Struct(a[i]);
		cout << '\n';
	}
	cout << ':';
	for (i = 1; i <= 74; i++)
		cout << '=';
	cout << ':';
	cout << "\n";
}

void Heading()
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
	cout << setw(9) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Ten lot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(20) << "Dia Chi"
		<< ':'
		<< setw(5) << "NSinh"
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

void HoanVi(NhanVien& x, NhanVien& y)
{
	NhanVien t;
	t = x;
	x = y;
	y = t;
}

void Copy(NhanVien b[MAX], NhanVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

//Dùng thuật giải chọn trực tiếp sắp danh sách tăng dần theo mã NV.
void SelectionSort_MaNV(NhanVien a[MAX], int n) 
{
	for (int i = 0; i < n - 1; ++i) 
	{
		int min_idx = i;
		for (int j = i + 1; j < n; ++j) 
		{
			if (strcmp(a[j].MaNV, a[min_idx].MaNV) < 0) 
			{
				min_idx = j;
			}
		}
		if (min_idx != i) 
		{
			HoanVi(a[i], a[min_idx]);
		}
	}
}

//Dùng thuật giải chèn trực tiếp sắp danh sách tăng dần theo địa chỉ.
void InsertionSort_DiaChi(NhanVien a[MAX], int n) 
{
	for (int i = 1; i < n; ++i) 
	{
		NhanVien key = a[i];
		int j = i - 1;
		while (j >= 0 && strcmp(a[j].DiaChi, key.DiaChi) > 0) 
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

//Dùng thuật giải Radix sắp danh sách tăng dần theo năm sinh
void CountingSort_NamSinh(NhanVien a[MAX], int n, int exp) 
{
	NhanVien* output = new NhanVien[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; ++i) 
	{
		count[(a[i].NamSinh / exp) % 10]++;
	}

	for (int i = 1; i < 10; ++i) 
	{
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; --i) 
	{
		output[count[(a[i].NamSinh / exp) % 10] - 1] = a[i];
		count[(a[i].NamSinh / exp) % 10]--;
	}

	for (int i = 0; i < n; ++i) 
	{
		a[i] = output[i];
	}

	delete[] output; // Giải phóng bộ nhớ sau khi sử dụng xong
}

void RadixSort_NamSinh(NhanVien a[MAX], int n) 
{
	int max_year = a[0].NamSinh;
	for (int i = 1; i < n; ++i) 
	{
		if (a[i].NamSinh > max_year) 
		{
			max_year = a[i].NamSinh;
		}
	}

	for (int exp = 1; max_year / exp > 0; exp *= 10) 
	{
		CountingSort_NamSinh(a, n, exp);
	}
}
