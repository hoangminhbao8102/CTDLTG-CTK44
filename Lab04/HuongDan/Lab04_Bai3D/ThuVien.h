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

void Tach_Luong_x(LIST l, double x);
void Tach_LuanPhien(LIST l);
void DaoNguoc_DS(LIST l);
void Remove_Ten(LIST& l, char ten[10]);
int RemoveNode_First(LIST& l, char ten[10]);
void List_SapTang_Ten_Ho_TLot(LIST& l);
void List_Selection_Sort(LIST& l);
void HoanVi(DataType& x, DataType& y);

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

void Tach_Luong_x(LIST l, double x)
{
	NODE* p;
	LIST l1, l2;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	CreatList(l1);
	CreatList(l2);
	while (p != NULL)
	{
		if (p->info.Luong <= x)
			InsertTail(l1, p->info);
		else
			InsertTail(l2, p->info);
		p = p->pNext;
	}
	cout << "\n- Danh sach l1 (Luong <= " << x << "):\n";
	Xuat_DSNV(l1);
	cout << "\n- Danh sach l2 (Luong > " << x << "):\n";
	Xuat_DSNV(l2);
	cout << endl;
}

void Tach_LuanPhien(LIST l)
{
	NODE* p;
	LIST l1, l2;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	int k = 1;
	CreatList(l1);
	CreatList(l2);
	while (p != NULL)
	{
		if (k == 1)
			InsertTail(l1, p->info);
		else
			InsertTail(l2, p->info);
		p = p->pNext;
		k = 3 - k;
	}
	cout << "\n- Danh sach l1:\n";
	Xuat_DSNV(l1);
	cout << "\n- Danh sach l2 :\n";
	Xuat_DSNV(l2);
	cout << endl;
}

void DaoNguoc_DS(LIST l)
{
	NODE* p;
	LIST l1;
	p = l.pHead;
	if (p == NULL)
	{
		cout << "\nDS l rong";
		system("PAUSE");
		return;
	}
	CreatList(l1);
	while (p != NULL)
	{
		InsertHead(l1, p->info);
		p = p->pNext;
	}
	cout << "\n- Danh sach dao nguoc cua l:\n";
	Xuat_DSNV(l1);
}

void Remove_Ten(LIST& l, char ten[10])
{
	NODE* p = l.pHead;
	NODE* prev = NULL;
	while (p != NULL)
	{
		if (strcmp(p->info.Ten, ten) == 0)
		{
			if (prev == NULL)
			{
				l.pHead = p->pNext;
				delete p;
				p = l.pHead;
			}
			else
			{
				prev->pNext = p->pNext;
				delete p;
				p = prev->pNext;
			}
		}
		else
		{
			prev = p;
			p = p->pNext;
		}
	}
}
int RemoveNode_First(LIST& l, char ten[10])
{
	if (l.pHead == NULL)
		return 0;
	NODE* p = l.pHead;
	if (strcmp(p->info.Ten, ten) == 0)
	{
		l.pHead = p->pNext;
		delete p;
		return 1;
	}
	NODE* prev = p;
	p = p->pNext;
	while (p != NULL)
	{
		if (strcmp(p->info.Ten, ten) == 0)
		{
			prev->pNext = p->pNext;
			delete p;
			return 1;
		}
		prev = p;
		p = p->pNext;
	}
	return 0;
}

void List_Selection_Sort(LIST& l)
{
	NODE* min;
	NODE* p, * q;
	p = l.pHead;
	while (p != l.pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (_strcmpi(q->info.Ten, min->info.Ten) < 0)
				min = q;
			q = q->pNext;
		}
		HoanVi(min->info, p->info);
		p = p->pNext;
	}
}

void List_SapTang_Ten_Ho_TLot(LIST& l)
{
	List_Selection_Sort(l);
	NODE* p, * q;
	for (p = l.pHead; p != l.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (_strcmpi(p->info.Ten, q->info.Ten) == 0)
				if (_strcmpi(p->info.HoNV, q->info.HoNV) > 0)
					HoanVi(q->info, p->info);
	for (p = l.pHead; p != l.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (_strcmpi(p->info.Ten, q->info.Ten) == 0 && _strcmpi(p->info.HoNV, q->info.HoNV) == 0)
				if (_strcmpi(p->info.TenLot, q->info.TenLot) > 0)
					HoanVi(q->info, p->info);
}

void HoanVi(DataType& x, DataType& y)
{
	DataType t = x;
	x = y;
	y = t;
}