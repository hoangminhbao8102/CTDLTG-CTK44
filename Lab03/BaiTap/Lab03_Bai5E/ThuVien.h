#define MAX 100

int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Copy(int b[MAX], int a[MAX], int n);
// Các hàm sắp xếp
void SelectionSort(int a[MAX], int n, int& comparisonCount, int& swapCount);
void InsertionSort(int a[MAX], int n, int& comparisonCount, int& swapCount);
void ExchangeSort(int a[MAX], int n, int& comparisonCount, int& swapCount);
void BubbleSort(int a[MAX], int n, int& comparisonCount, int& swapCount);

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

// Selection Sort
void SelectionSort(int a[MAX], int n, int& comparisonCount, int& swapCount) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            comparisonCount++;
            if (a[j] < a[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            swapCount++;
            HoanVi(a[i], a[minIndex]);
        }
    }
}

// Insertion Sort
void InsertionSort(int a[MAX], int n, int& comparisonCount, int& swapCount) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            comparisonCount++;
            swapCount++;
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Exchange Sort (Bubble Sort)
void ExchangeSort(int a[MAX], int n, int& comparisonCount, int& swapCount) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            comparisonCount++;
            if (a[i] > a[j]) 
            {
                swapCount++;
                HoanVi(a[i], a[j]);
            }
        }
    }
}

// Bubble Sort
void BubbleSort(int a[MAX], int n, int& comparisonCount, int& swapCount) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            comparisonCount++;
            if (a[j] > a[j + 1]) 
            {
                swapCount++;
                HoanVi(a[j], a[j + 1]);
            }
        }
    }
}