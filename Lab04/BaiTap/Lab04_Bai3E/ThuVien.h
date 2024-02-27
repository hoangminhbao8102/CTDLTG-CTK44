struct NhanVien
{
	char MaNV[8];
	char HoNV[10];
	char TenLot[10];
	char Ten[10];
	char DiaChi[12];
	int NamSinh;
	double Luong;
};

typedef NhanVien DataType;

struct TagNode
{
	DataType info;
	TagNode* pNext;
};

typedef TagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(DataType x);
void CreatList(LIST& l);
int IsEmpty(LIST l);
void InsertHead(LIST& l, DataType x);
void InsertTail(LIST& l, DataType x);

int TapTin_List(char* filename, LIST& l);
void Xuat_DSNV(LIST l);
void Xuat_NV(DataType p);
void TieuDe();

void SwapData(NODE* a, NODE* b);
void SelectionSort(LIST& l);
void InsertionSort(LIST& l);
void BubbleSort(LIST& l);
void MergeSort(LIST& l);
void Merge(LIST& l, NODE* p, NODE* q);
void RadixSort(LIST& l);

NODE* GetNode(DataType x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

int IsEmpty(LIST l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}

void InsertHead(LIST& l, DataType x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void InsertTail(LIST& l, DataType x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("CLS");
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

int TapTin_List(char* filename, LIST& l)
{
	DataType x;
	ifstream in(filename);
	if (!in)
		return 0;
	CreatList(l);
	while (!in.eof())
	{
		in >> x.MaNV;
		in >> x.HoNV;
		in >> x.TenLot;
		in >> x.Ten;
		in >> x.DiaChi;
		in >> x.NamSinh;
		in >> x.Luong;
		InsertTail(l, x);
	}
	in.close();
	return 0;
}

void TieuDe()
{
	int i;
	cout << endl;
	cout << ':';
	for (i = 1; i <= 76; i++)
		cout << '=';
	cout << ':' << endl;
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(10) << "Ma NV"
		<< ':'
		<< setw(10) << "Ho"
		<< setw(10) << "Ten Lot"
		<< setw(10) << "Ten"
		<< ':'
		<< setw(15) << "Dia Chi"
		<< ':'
		<< setw(5) << "NSinh"
		<< ':'
		<< setw(10) << "Luong"
		<< ':';
	cout << endl;
	cout << ':';
	for (i = 1; i <= 76; i++)
		cout << '=';
	cout << ':';
}

void Xuat_NV(DataType p)
{
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << p.MaNV
		<< ':'
		<< setw(10) << p.HoNV
		<< setw(10) << p.TenLot
		<< setw(10) << p.Ten
		<< ':'
		<< setw(15) << p.DiaChi
		<< ':'
		<< setw(5) << p.NamSinh
		<< ':'
		<< setw(10) << setiosflags(ios::fixed) << setprecision(2) << p.Luong
		<< ':';
}

void Xuat_DSNV(LIST l)
{
	TieuDe();
	NODE* p = l.pHead;
	while (p != NULL)
	{
		cout << endl;
		Xuat_NV(p->info);
		p = p->pNext;
	}
}

void SwapData(NODE* a, NODE* b)
{
	DataType temp = a->info;
	a->info = b->info;
	b->info = temp;
}

void SelectionSort(LIST& l)
{
	for (NODE* i = l.pHead; i->pNext != NULL; i = i->pNext)
	{
		NODE* min = i;
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
		{
			if (j->info.NamSinh < min->info.NamSinh)
				min = j;
		}
		SwapData(i, min);
	}
}

void InsertionSort(LIST& l)
{
	NODE* p = l.pHead->pNext;
	while (p != NULL)
	{
		NODE* q = p->pNext;
		NODE* i = l.pHead;
		while (i != p)
		{
			if (i->info.NamSinh > p->info.NamSinh)
			{
				SwapData(p, i);
				break;
			}
			i = i->pNext;
		}
		p = q;
	}
}

void BubbleSort(LIST& l)
{
	for (NODE* i = l.pHead; i != NULL; i = i->pNext)
	{
		for (NODE* j = l.pHead; j->pNext != NULL; j = j->pNext)
		{
			if (j->info.NamSinh > j->pNext->info.NamSinh)
				SwapData(j, j->pNext);
		}
	}
}

void Merge(LIST& l, NODE* p, NODE* q)
{
	LIST mergedList;
	CreatList(mergedList);
	while (p != NULL && q != NULL)
	{
		if (p->info.NamSinh <= q->info.NamSinh)
		{
			InsertTail(mergedList, p->info);
			p = p->pNext;
		}
		else
		{
			InsertTail(mergedList, q->info);
			q = q->pNext;
		}
	}
	while (p != NULL)
	{
		InsertTail(mergedList, p->info);
		p = p->pNext;
	}
	while (q != NULL)
	{
		InsertTail(mergedList, q->info);
		q = q->pNext;
	}
	l = mergedList;
}

void MergeSort(LIST& l)
{
	if (l.pHead != NULL && l.pHead->pNext != NULL)
	{
		NODE* p = l.pHead;
		NODE* q = l.pHead;
		NODE* prev = NULL;
		while (q != NULL && q->pNext != NULL)
		{
			prev = p;
			p = p->pNext;
			q = q->pNext->pNext;
		}
		prev->pNext = NULL;
		MergeSort(l);
		Merge(l, l.pHead, p);
	}
}

void RadixSort(LIST& l)
{
	const int base = 10;
	for (int exp = 1; exp <= 1000000000; exp *= base)
	{
		LIST bucket[base];
		for (int i = 0; i < base; ++i)
			CreatList(bucket[i]);

		for (NODE* current = l.pHead; current != NULL; current = current->pNext)
		{
			int digit = (current->info.NamSinh / exp) % base;
			InsertTail(bucket[digit], current->info);
		}

		int index = 0;
		for (int i = 0; i < base; ++i)
		{
			NODE* current = bucket[i].pHead;
			while (current != NULL)
			{
				NODE* temp = current;
				current = current->pNext;
				temp->pNext = NULL;
				if (l.pHead == NULL)
					l.pHead = l.pTail = temp;
				else
				{
					l.pTail->pNext = temp;
					l.pTail = temp;
				}
			}
		}
	}
}