#define MAX 100

int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Selection_L(int a[MAX], int n);
void Copy(int b[MAX], int a[MAX], int n);
void Insertion_L(int a[MAX], int n);
void Interchange_L(int a[MAX], int n);
void Buble_L(int a[MAX], int n);
void Binary_Insertion(int a[MAX], int n);
void Radix(int a[MAX], int n);

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

void Selection_L(int a[MAX], int n)
{
	int i, j, cs_min;
	for (i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[cs_min])
				cs_min = j;
		HoanVi(a[i], a[cs_min]);
	}
}

void Copy(int b[MAX], int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

void Insertion_L(int a[MAX], int n)
{
	int i, x, pos;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		for (pos = i - 1; (pos >= 0) && (a[pos] > x); pos--)
			a[pos + 1] = a[pos];
		a[pos + 1] = x;
	}
}

void Interchange_L(int a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				HoanVi(a[i], a[j]);
	}
}

void Buble_L(int a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				HoanVi(a[j - 1], a[j]);
	}
}

void Binary_Insertion(int a[MAX], int n)
{
	int l, r, m;
	int i, j;
	int x;
	for (i = 1; i < n; i++)
	{
		x = a[i]; l = 0; r = i - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (x < a[m])
				r = m - 1;
			else
				l = m + 1;
		}
		for (j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = x;
	}
}

void Radix(int a[MAX], int n)
{
	int max, m;
	max = a[0]; m = 0;
	int k, i, j, du, thuong;
	int b0[MAX], b1[MAX], b2[MAX], b3[MAX], b4[MAX], b5[MAX],
		b6[MAX], b7[MAX], b8[MAX], b9[MAX];
	int p0, p1, p2, p3, p4, p5, p6, p7, p8, p9;
	for (i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	while (max != 0)
	{
		max = max / 10;
		m++;
	}
	k = 0; 
	while (k < m)
	{
		p0 = p1 = p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = 0;
		for (i = 0; i < n; i++)
		{
			thuong = a[i];
			for (j = 0; j <= k; j++)
			{
				du = thuong % 10;
				thuong = thuong / 10;
			}
			switch (du)
			{
			case 0:b0[p0++] = a[i];
				break;
			case 1:b1[p1++] = a[i];
				break;
			case 2:b2[p2++] = a[i];
				break;
			case 3:b3[p3++] = a[i];
				break;
			case 4:b4[p4++] = a[i];
				break;
			case 5:b5[p5++] = a[i];
				break;
			case 6:b6[p6++] = a[i];
				break;
			case 7:b7[p7++] = a[i];
				break;
			case 8:b8[p8++] = a[i];
				break;
			case 9:b9[p9++] = a[i];
				break;
			}
		}
		j = 0;
		for (i = 0; i < p0; i++)
			a[j++] = b0[i];
		for (i = 0; i < p1; i++)
			a[j++] = b1[i];
		for (i = 0; i < p2; i++)
			a[j++] = b2[i];
		for (i = 0; i < p3; i++)
			a[j++] = b3[i];
		for (i = 0; i < p4; i++)
			a[j++] = b4[i];
		for (i = 0; i < p5; i++)
			a[j++] = b5[i];
		for (i = 0; i < p6; i++)
			a[j++] = b6[i];
		for (i = 0; i < p7; i++)
			a[j++] = b7[i];
		for (i = 0; i < p8; i++)
			a[j++] = b8[i];
		for (i = 0; i < p9; i++)
			a[j++] = b9[i];
		k++; 
	}
}