#define MAX 100

int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Copy(int b[MAX], int a[MAX], int n);
void SelectionSort_MinToMax(int a[MAX], int n);
void SelectionSort_MaxToMin(int a[MAX], int n);
void SelectionSort_TwoEnds(int a[MAX], int n);
void InsertionSort_InsertToLeft(int a[MAX], int n);
void InsertionSort_InsertToRight(int a[MAX], int n);
void BinaryInsertionSort(int a[MAX], int n);
void ExchangeSort_MinToMax(int a[MAX], int n);
void ExchangeSort_MaxToMin(int a[MAX], int n);
void BubbleSort_MinToMax(int a[MAX], int n);
void BubbleSort_MaxToMin(int a[MAX], int n);

int File_Array(char* filename, int a[MAX], int& n)
{
	ifstream in(filename);
	if (!in)
		return 0;
	in >> n;
	for (int i = 0; i < n; i++)
		in >> a[i];
	in.close();
	return 1;
}

void Output(int a[MAX], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void HoanVi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}

void Copy(int b[MAX], int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

// Thuật toán Sắp xếp chọn trực tiếp - tại mỗi bước đưa phần tử nhỏ nhất về đầu mảng
void SelectionSort_MinToMax(int a[MAX], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            HoanVi(a[i], a[minIndex]);
    }
}

// Thuật toán Sắp xếp chọn trực tiếp - tại mỗi bước đưa phần tử lớn nhất về cuối mảng
void SelectionSort_MaxToMin(int a[MAX], int n) 
{
    for (int i = n - 1; i > 0; i--) 
    {
        int maxIndex = i;
        for (int j = 0; j < i; j++) 
        {
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }
        if (maxIndex != i)
            HoanVi(a[i], a[maxIndex]);
    }
}

// Thuật toán Sắp xếp chọn hai đầu
void SelectionSort_TwoEnds(int a[MAX], int n) 
{
    for (int i = 0; i < n / 2; i++) 
    {
        int minIndex = i;
        int maxIndex = i;
        for (int j = i + 1; j < n - i; j++) 
        {
            if (a[j] < a[minIndex])
                minIndex = j;
            if (a[j] > a[maxIndex])
                maxIndex = j;
        }
        if (minIndex != i)
            HoanVi(a[i], a[minIndex]);
        if (maxIndex != n - i - 1) {
            if (maxIndex == i)
                maxIndex = minIndex;
            HoanVi(a[n - i - 1], a[maxIndex]);
        }
    }
}

// Thuật toán chèn trực tiếp - chèn vào dãy con tăng bên trái
void InsertionSort_InsertToLeft(int a[MAX], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Thuật toán chèn trực tiếp - chèn vào dãy con tăng bên phải
void InsertionSort_InsertToRight(int a[MAX], int n) 
{
    for (int i = n - 2; i >= 0; i--) {
        int key = a[i];
        int j = i + 1;
        while (j < n && a[j] < key) {
            a[j - 1] = a[j];
            j++;
        }
        a[j - 1] = key;
    }
}

// Thuật toán chèn nhị phân
void BinaryInsertionSort(int a[MAX], int n) 
{
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int left = 0, right = i - 1;
        int j = i - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        while (j >= left) {
            a[j + 1] = a[j];
            j--;
        }
        a[left] = key;
    }
}

// Thuật toán đổi chỗ trực tiếp - tại mỗi bước đưa phần tử nhỏ nhất về đầu mảng
void ExchangeSort_MinToMax(int a[MAX], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (a[j] < a[i])
                HoanVi(a[i], a[j]);
        }
    }
}

// Thuật toán đổi chỗ trực tiếp - tại mỗi bước đưa phần tử lớn nhất về cuối mảng
void ExchangeSort_MaxToMin(int a[MAX], int n) 
{
    for (int i = n - 1; i > 0; i--) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (a[j] < a[i])
                HoanVi(a[i], a[j]);
        }
    }
}

// Thuật toán Bubble - tại mỗi bước đưa phần tử nhỏ nhất về đầu mảng
void BubbleSort_MinToMax(int a[MAX], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1])
                HoanVi(a[j], a[j + 1]);
        }
    }
}

// Thuật toán Bubble - tại mỗi bước đưa phần tử lớn nhất về cuối mảng
void BubbleSort_MaxToMin(int a[MAX], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j] < a[j + 1])
                HoanVi(a[j], a[j + 1]);
        }
    }
}