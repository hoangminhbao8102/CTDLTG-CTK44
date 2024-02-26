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
// Dùng QuickSort
void QuickSort(NhanVien a[MAX], int left, int right);
int Partition(NhanVien a[MAX], int left, int right);
// Dùng HeapSort
void Heapify(NhanVien a[MAX], int n, int i);
void HeapSort(NhanVien a[MAX], int n);
// Dùng MergeSort
void Merge(NhanVien a[MAX], int l, int m, int r);
void MergeSort(NhanVien arr[], int l, int r);
// Dùng ShakerSort
void ShakerSort(NhanVien a[MAX], int n);
//Nếu cùng mức lương
int Compare(NhanVien x, NhanVien y);

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

// Dùng QuickSort
void QuickSort(NhanVien a[MAX], int left, int right) 
{
	if (left < right) 
	{
		int pivot = Partition(a, left, right);
		QuickSort(a, left, pivot - 1);
		QuickSort(a, pivot + 1, right);
	}
}

int Partition(NhanVien a[MAX], int left, int right) 
{
	NhanVien pivot = a[right];
	int i = left - 1;
	for (int j = left; j < right; j++) 
	{
		if (Compare(a[j], pivot) < 0) 
		{
			i++;
			HoanVi(a[i], a[j]);
		}
	}
	HoanVi(a[i + 1], a[right]);
	return i + 1;
}

// Dùng HeapSort
void Heapify(NhanVien a[MAX], int n, int i) 
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l].Luong > a[largest].Luong)
		largest = l;

	if (r < n && a[r].Luong > a[largest].Luong)
		largest = r;

	if (largest != i) 
	{
		swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}

void HeapSort(NhanVien a[MAX], int n) 
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);

	for (int i = n - 1; i > 0; i--) 
	{
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}

// Dùng MergeSort
void Merge(NhanVien a[MAX], int l, int m, int r) 
{
	int n1 = m - l + 1;
	int n2 = r - m;

	NhanVien* L = new NhanVien[n1];
	NhanVien* R = new NhanVien[n2];

	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (L[i].Luong <= R[j].Luong)
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}

	// Giải phóng bộ nhớ của mảng động
	delete[] L;
	delete[] R;
}

void MergeSort(NhanVien arr[], int l, int r) 
{
	if (l >= r)
		return;
	int m = l + (r - l) / 2;
	MergeSort(arr, l, m);
	MergeSort(arr, m + 1, r);
	Merge(arr, l, m, r);
}

// Dùng ShakerSort
void ShakerSort(NhanVien a[MAX], int n) 
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) 
	{
		swapped = false;

		for (int i = start; i < end; ++i) 
		{
			if (a[i].Luong > a[i + 1].Luong) 
			{
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i) 
		{
			if (a[i].Luong > a[i + 1].Luong) 
			{
				swap(a[i], a[i + 1]);
				swapped = true;
			}
		}

		++start;
	}
}

//Nếu cùng mức lương
int Compare(NhanVien x, NhanVien y)
{
	if (x.Luong != y.Luong)
		return (x.Luong - y.Luong) > 0 ? 1 : -1;
	else if (strcmp(x.Ten, y.Ten) != 0)
		return strcmp(x.Ten, y.Ten);
	else if (strcmp(x.Ho, y.Ho) != 0)
		return strcmp(x.Ho, y.Ho);
	else
		return x.NamSinh - y.NamSinh;
}