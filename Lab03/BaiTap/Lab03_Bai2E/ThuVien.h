#define MAX 100

int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Copy(int b[MAX], int a[MAX], int n);
void Merge(int arr[], int l, int m, int r);
void MergeSort(int arr[], int l, int r);
void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);
int GetMax(int arr[], int n);
void CountSort(int arr[], int n, int exp);
void RadixSort(int arr[], int n);
int Partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high);

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
    cout << endl;
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

// Merge Sort
void Merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1]; // Sử dụng cấp phát động thay vì cấp phát tĩnh
    int* R = new int[n2]; // Sử dụng cấp phát động thay vì cấp phát tĩnh

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L; // Giải phóng bộ nhớ sau khi sử dụng
    delete[] R; // Giải phóng bộ nhớ sau khi sử dụng
}

void MergeSort(int arr[], int l, int r) 
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, r);
    Merge(arr, l, m, r);
}

// Heap Sort
void Heapify(int arr[], int n, int i) 
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) 
    {
        HoanVi(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) 
    {
        HoanVi(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

// Radix Sort
int GetMax(int arr[], int n) 
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void CountSort(int arr[], int n, int exp)
{
    int* output = new int[n]; // Sử dụng cấp phát động thay vì cấp phát tĩnh
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output; // Giải phóng bộ nhớ sau khi sử dụng
}

void RadixSort(int arr[], int n) 
{
    int m = GetMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        CountSort(arr, n, exp);
}

// Quick Sort
int Partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            HoanVi(arr[i], arr[j]);
        }
    }
    HoanVi(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high) 
{
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}