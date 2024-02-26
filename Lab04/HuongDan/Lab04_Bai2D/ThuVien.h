struct LLSinhVien //Kieu sinh vien
{
	char MaSV[8];
	char Ho[15];
	char Ten[10];
	int NamSinh;
	char NguyenQuan[15];
};

struct TagNodeLL
{
	LLSinhVien info;
	TagNodeLL* pNext;
};

typedef TagNodeLL NODELL;

struct LL
{
	NODELL* pHead;
	NODELL* pTail;
};

struct DiemTP
{
	char MaSV[8];
	double DBT1;
	double DBT2;
	double DGK;
	double DQT;
};

struct TagNodeDiem
{
	DiemTP info;
	TagNodeDiem* pNext;
};

typedef TagNodeDiem NODEBD;

struct BD
{
	NODEBD* pHead;
	NODEBD* pTail;
};

NODELL* GetNode_LL(LLSinhVien x);
void CreatList_LL(LL& l);
void InsertTail_LL(LL& l, LLSinhVien x);
int TapTin_List_LL(char* filename, LL& l);

int TapTin_List_BD(char* filename, BD& l);
void InsertTail_BD(BD& l, DiemTP x);
void CreatList_BD(BD& l);
NODEBD* GetNode_BD(DiemTP x);

void XuatBangDiem(LL l, BD g);
void TieuDe();

NODELL* GetNode_LL(LLSinhVien x)
{
	NODELL* p;
	p = new NODELL;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_LL(LL& l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail_LL(LL& l, LLSinhVien x)
{
	NODELL* new_ele = GetNode_LL(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		_getch();
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

int TapTin_List_LL(char* filename, LL& l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	LLSinhVien x;
	CreatList_LL(l);
	while (!in.eof())
	{
		in >> x.MaSV;
		in >> x.Ho;
		in >> x.Ten;
		in >> x.NamSinh;
		in >> x.NguyenQuan;
		InsertTail_LL(l, x);
	}
	in.close();
	return 1;
}

NODEBD* GetNode_BD(DiemTP x)
{
	NODEBD* p;
	p = new NODEBD;
	if (p != NULL)
	{
		p->info = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_BD(BD& l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail_BD(BD& l, DiemTP x)
{
	NODEBD* new_ele = GetNode_BD(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		_getch();
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

int TapTin_List_BD(char* filename, BD& l)
{
	ifstream in(filename);
	if (!in)
		return 0;
	DiemTP x;
	CreatList_BD(l);
	while (!in.eof())
	{
		in >> x.MaSV;
		in >> x.DBT1;
		in >> x.DBT2;
		in >> x.DGK;
		x.DQT = x.DBT1 + x.DBT2 + x.DGK;
		InsertTail_BD(l, x);
	}
	in.close();
	return 1;
}

void TieuDe()
{
	int i;
	cout << endl;
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':' << endl;
	cout << setiosflags(ios::left);
	cout << ':';
	cout << setw(10) << "Ma SV"
		<< ':'
		<< setw(16) << "Ho"
		<< setw(11) << "Ten"
		<< ':'
		<< setw(6) << "NSinh"
		<< ':'
		<< setw(8) << "DiemGK"
		<< ':';
	cout << endl;
	cout << ':';
	for (i = 1; i <= 54; i++)
		cout << '=';
	cout << ':';
}

void XuatBangDiem(LL l, BD g)
{
	TieuDe();
	NODELL* p = l.pHead;
	NODEBD* q = g.pHead;
	while (p != NULL && q != NULL)
	{
		cout << endl << ':';
		cout << setiosflags(ios::left)
			<< setw(10) << p->info.MaSV
			<< ':'
			<< setw(16) << p->info.Ho
			<< setw(11) << p->info.Ten
			<< ':'
			<< setw(6) << p->info.NamSinh
			<< ':'
			<< setw(8) << setprecision(2) << setiosflags(ios::fixed) << q->info.DQT
			<< ':';
		p = p->pNext;
		q = q->pNext;
	}
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 54; i++)
		cout << '=';
	cout << ':' << endl;
}
