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

int File_Array(char* filename, SinhVien a[MAX], int& n);
void Output_Arr(SinhVien a[MAX], int n);
void Output_Struct(SinhVien p);
void Heading();

void HoanVi(SinhVien& x, SinhVien& y);
void Copy(SinhVien b[MAX], SinhVien a[MAX], int n);

void QuickSort(SinhVien a[MAX], int n);
void Partition(SinhVien a[MAX], int l, int r);
void Shift(SinhVien a[MAX], int l, int r);
void Create_Heap(SinhVien a[MAX], int n);
void HeapSort(SinhVien a[MAX], int n);
void MergeSort(SinhVien F[MAX], int n);
void Merge(SinhVien F1[MAX], int h1, SinhVien F2[MAX], int h2, SinhVien F[MAX], int p);
void Distribution(SinhVien F[MAX], int n, SinhVien F1[MAX], int& h1, SinhVien F2[MAX], int& h2, int p);

int File_Array(char* filename, SinhVien a[MAX], int& n)
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

void Output_Struct(SinhVien p)
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

void Output_Arr(SinhVien a[MAX], int n)
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

void HoanVi(SinhVien& x, SinhVien& y)
{
	SinhVien t;
	t = x;
	x = y;
	y = t;
}
void Copy(SinhVien b[MAX], SinhVien a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void QuickSort(SinhVien a[MAX], int n)
{
	Partition(a, 0, n - 1);
}

void Partition(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	x = a[(l + r) / 2];
	i = l; j = r;
	do
	{
		while (a[i].DTB < x.DTB)
			i++;
		while (a[j].DTB > x.DTB)
			j--;
		if (i <= j)
		{
			HoanVi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		Partition(a, l, j);
	if (i < r)
		Partition(a, i, r);
}

void Shift(SinhVien a[MAX], int l, int r)
{
	int i, j;
	SinhVien x;
	i = l; j = 2 * i + 1;
	x = a[i];
	while (j <= r)
	{
		if (j < r)
			if (a[j].DTB < a[j + 1].DTB)
				j = j + 1;
		if (a[j].DTB <= x.DTB)
			return;
		else
		{
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
			a[i] = x;
		}
	}
}

void Create_Heap(SinhVien a[MAX], int n)
{
	int l;
	l = (n - 1) / 2;
	while (l >= 0)
	{
		Shift(a, l, n - 1);
		l = l - 1;
	}
}

void HeapSort(SinhVien a[MAX], int n)
{
	int r, i = 0;
	Create_Heap(a, n);
	r = n - 1;
	while (r > 0)
	{
		i++;
		HoanVi(a[0], a[r]);
		r = r - 1;
		Shift(a, 0, r);
	}
}

void MergeSort(SinhVien F[MAX], int n)
{
	int p = 1, h1, h2;
	SinhVien F1[MAX], F2[MAX];
	int i = 1;
	while (p < n)
	{
		Distribution(F, n, F1, h1, F2, h2, p);
		Merge(F1, h1, F2, h2, F, p);
		i++;
		p = p * 2;
	}
}

void Merge(SinhVien F1[MAX], int h1, SinhVien F2[MAX], int h2, SinhVien F[MAX], int p)
{
	int i1 = 0, i2 = 0, r1, r2;
	int h = 0;
	while (i1 < h1 && i2 < h2)
	{
		r1 = r2 = 1;
		while ((r1 <= p) && (r2 <= p) && i1 < h1 && i2 < h2)
		{
			if (F1[i1].DTB <= F2[i2].DTB)
			{
				F[h++] = F1[i1];
				r1++;
				i1++;
			}
			else
			{
				F[h++] = F2[i2];
				r2++;
				i2++;
			}
		}
		while (i1 < h1 && r1 <= p)
		{
			F[h++] = F1[i1];
			i1++; r1++;
		}
		while (i2 < h2 && r2 <= p)
		{
			F[h++] = F2[i2];
			i2++; r2++;
		}
	}
	while (i1 < h1)
	{
		F[h++] = F1[i1];
		i1++;
	}
	while (i2 < h2)
	{
		F[h++] = F2[i2];
		i2++;
	}
}

void Distribution(SinhVien F[MAX], int n, SinhVien F1[MAX], int& h1, SinhVien F2[MAX], int& h2, int p)
{
	int i, k = 1, l = 0;
	h1 = 0; h2 = 0;
	do
	{
		i = 1;
		while (i <= p && l < n)
		{
			if (k == 1)
			{
				F1[h1++] = F[l];
			}
			else
			{
				F2[h2++] = F[l];
			}
			i++;
			l++;
		}
		k = 3 - k;
	} while (l < n);
}