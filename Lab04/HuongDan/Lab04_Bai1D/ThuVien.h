#define MAX 100

typedef int DataType;

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

void XuatDS(LIST l);
int File_List(char* f, LIST& l);
NODE* GetNode(DataType x);
void CreatList(LIST& l);
int IsEmpty(LIST l);

NODE* Search_First(LIST l, DataType x);
NODE* Search_End(LIST l, DataType x);
int Search_Node_x_First(LIST l, DataType x);
int Search_Node_x_End(LIST l, DataType x);
void Search_Node_x(LIST l, DataType x);

void AddFirst(LIST& l, NODE* new_ele);
void InsertHead(LIST& l, DataType x);
void AddTail(LIST& l, NODE* new_ele);
void InsertTail(LIST& l, DataType x);
void InsertAfter(LIST& l, NODE* q, DataType x);
void Insert_x_After_first_y(LIST& l, DataType y, DataType x);
void Insert_x_After_End_y(LIST& l, DataType y, DataType x);

void RemoveHead(LIST& l);
void RemoveTail(LIST& l);
void RemoveList(LIST& l);
int RemoveNode_First(LIST& l, DataType x);
int RemoveNode_End(LIST& l, DataType x);
void Remove_x(LIST& l, DataType x);

void List_Selection_Sort1(LIST& l);
void List_Selection_Sort2(LIST& l);

int SoNut_x(LIST l, DataType x);
int SoNut(LIST l);
void Copy(LIST& l1, LIST l);
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

int File_List(char* f, LIST& l)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreatList(l);
	DataType x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}

void XuatDS(LIST l)
{
	NODE* p;
	if (IsEmpty(l))
	{
		cout << "\nDS rong!\n";
		return;
	}
	p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}

NODE* Search_First(LIST l, DataType x)
{
	NODE* p;
	p = l.pHead;
	while ((p != NULL) && (p->info != x))
		p = p->pNext;
	return p;
}

int Search_Node_x_First(LIST l, DataType x)
{
	NODE* p;
	int i = 0;
	p = l.pHead;
	while ((p != NULL) && (p->info != x))
	{
		p = p->pNext;
		i++;
	}
	if (p == NULL)
		i = -1;
	return i;
}

NODE* Search_End(LIST l, DataType x)
{
	NODE* p, * q = NULL;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			q = p;
		p = p->pNext;
	}
	return q;
}

int Search_Node_x_End(LIST l, DataType x)
{
	NODE* p;
	int Kq = -1, i = 0;
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			Kq = i;
		i++;
		p = p->pNext;
	}
	return Kq;
}

void Search_Node_x(LIST l, DataType x)
{
	NODE* p;
	int i = 0;
	p = Search_First(l, x);
	if (p == NULL)
	{
		cout << endl << x << " khong co trong danh sach";
		return;
	}
	cout << endl << x << " xuat hien trong danh sach tai cac vi tri :\n";
	p = l.pHead;
	while (p != NULL)
	{
		if (p->info == x)
			cout << i << '\t';
		p = p->pNext;
		i++;
	}
}

void AddFirst(LIST& l, NODE* new_ele)
{
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

void InsertHead(LIST& l, DataType x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho! khong thuc hien duoc thao tac nay";
		return;
	}
	if (l.pHead == NULL)
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(LIST& l, NODE* new_ele)
{
	if (IsEmpty(l))
	{
		l.pHead = new_ele; l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

void InsertTail(LIST& l, DataType x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho! khong thuc hien duoc thao tac nay";
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

void InsertAfter(LIST& l, NODE* q, DataType x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho! khong thuc hien duoc thao tac nay";
		return;
	}
	if (q != NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if (q == l.pTail)
			l.pTail = new_ele;
	}
	else
		AddFirst(l, new_ele);
}

void Insert_x_After_first_y(LIST& l, DataType y, DataType x)
{
	NODE* q;
	q = Search_First(l, y);
	InsertAfter(l, q, x);
}

void Insert_x_After_End_y(LIST& l, DataType y, DataType x)
{
	NODE* q;
	q = Search_End(l, y);
	InsertAfter(l, q, x);
}

void RemoveHead(LIST& l)
{
	NODE* p;
	if (l.pHead == NULL)
	{
		cout << "\nDS rong!khong xoa duoc, chon thao tac khac!!!\n";
		return;
	}
	p = l.pHead;
	l.pHead = l.pHead->pNext;
	delete p;
	if (l.pHead == NULL)
		l.pTail = NULL;
}

void RemoveTail(LIST& l)
{
	NODE* p, * q;
	if (l.pHead == NULL)
	{
		cout << "\nDS rong!khong xoa duoc, chon thao tac khac!!!\n";
		return;
	}
	p = l.pHead;
	q = NULL;
	while (p != l.pTail)
	{
		q = p;
		p = p->pNext;
	}
	l.pTail = q;
	delete p;
	if (l.pTail == NULL)
		l.pHead = NULL;
	else
		l.pTail->pNext = NULL;
}

int RemoveNode_First(LIST& l, DataType x)
{
	NODE* p = l.pHead;
	NODE* q = NULL;
	while (p != NULL)
	{
		if (p->info == x)
			break;
		q = p; p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
	{
		if (p == l.pTail)
			l.pTail = q;
		q->pNext = p->pNext;
	}
	else
	{
		l.pHead = p->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}

int RemoveNode_End(LIST& l, DataType x)
{
	NODE* p = l.pHead;
	NODE* q = NULL;
	NODE* r = NULL;
	NODE* t = NULL;
	while (p != NULL)
	{
		if (p->info == x)
		{
			r = p;
			t = q;
		}
		q = p; p = p->pNext;
	}
	if (r == NULL)
		return 0;
	if (t != NULL)
	{
		if (r == l.pTail)
			l.pTail = t;
		t->pNext = r->pNext;
	}
	else 
	{
		l.pHead = r->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	delete p;
	return 1;
}

void Remove_x(LIST& l, DataType x)
{
	while (RemoveNode_First(l, x));
}

void RemoveList(LIST& l)
{
	NODE* p;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		delete p;
	}
	l.pTail = NULL;
}

void List_Selection_Sort1(LIST& l)
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
			if (q->info < min->info)
				min = q;
			q = q->pNext;
		}
		HoanVi(min->info, p->info);
		p = p->pNext;
	}
}

void List_Selection_Sort2(LIST& l)
{
	LIST lRes;
	NODE* min,
		* minprev;
	NODE* p,
		* q;
	CreatList(lRes);
	while (l.pHead != NULL)
	{
		p = l.pHead;
		q = p->pNext; // sau p
		min = p;
		minprev = NULL;
		while (q != NULL)
		{
			if (q->info < min->info)
			{
				min = q;
				minprev = p;
			}
			p = q;
			q = q->pNext;
		}
		if (minprev != NULL)
			minprev->pNext = min->pNext;
		else
			l.pHead = min->pNext;
		min->pNext = NULL;
		AddTail(lRes, min);
	}
	Copy(l, lRes);
}

int SoNut_x(LIST l, DataType x)
{
	NODE* p = l.pHead;
	int i = 0;

	while (p != NULL)
	{
		if (p->info == x)
			i++;
		p = p->pNext;
	}

	return i;
}

int SoNut(LIST l)
{
	NODE* p;
	int i = 0;
	p = l.pHead;
	while (p != NULL)
	{
		p = p->pNext;
		i++;
	}
	return i;
}

void Copy(LIST& l1, LIST l)
{
	CreatList(l1);
	if (IsEmpty(l))
	{
		cout << "\nDS rong!";
		return;
	}
	NODE* p;
	DataType x;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		x = p->info;
		InsertTail(l1, x);
	}
}
void HoanVi(DataType& x, DataType& y)
{
	DataType t = x;
	x = y;
	y = t;
}