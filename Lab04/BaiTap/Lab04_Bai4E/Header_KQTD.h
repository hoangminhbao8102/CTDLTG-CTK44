struct KetQuaTranDau
{
	int Vong;
	char Ngay[9];
	char Gio[6];
	char ChuNha[15];
	int BanThangChu;
	int BanThangKhach;
	char DoiKhach[15]; 
};

typedef KetQuaTranDau DataType_TD;

struct TagNODE_TD
{
	DataType_TD KQTD;
	TagNODE_TD* pNext;
};

typedef TagNODE_TD NODE_TD;

struct LIST_KQTD
{
	NODE_TD* pHead;
	NODE_TD* pTail;
};

NODE_TD* GetNODE_TD(DataType_TD x);
void CreatList_KQTD(LIST_KQTD& l);
void InsertTail_TD(LIST_KQTD& l, DataType_TD x);
void TapTin_List_KQTD(char* filename, LIST_KQTD& l);

NODE_TD* GetNODE_TD(DataType_TD x)
{
	NODE_TD* p;
	p = new NODE_TD;
	if (p != NULL)
	{
		p->KQTD = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_KQTD(LIST_KQTD& l)
{
	l.pHead = l.pTail = NULL;
}

void InsertTail_TD(LIST_KQTD& l, DataType_TD x)
{
	NODE_TD* new_ele = GetNODE_TD(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
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

void TapTin_List_KQTD(char* filename, LIST_KQTD& l)
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file !\n";
		system("PAUSE");
		return;
	}
	CreatList_KQTD(l);
	DataType_TD x;
	while (!in.eof())
	{
		in >> x.Vong;
		in >> x.Ngay;
		in >> x.Gio;
		in >> x.ChuNha;
		in >> x.BanThangChu;
		in >> x.BanThangKhach;
		in >> x.DoiKhach;
		InsertTail_TD(l, x);
	}
	in.close();
}
