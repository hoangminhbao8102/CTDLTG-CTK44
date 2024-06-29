typedef int Data;//Kieu thanh phan du sieu cua nut
struct TagNode //Kieu Nut
{
	Data info;
	TagNode* pNext;
};
typedef TagNode NODE;
struct STACK
{
	NODE* pHead; //Chua dc nut dau
	NODE* pTail; //Chua dc nut cuoi
};
//======================================
NODE* GetNode(Data x);
void CreatStack(STACK& s);
void Push(STACK& s, Data x);
void XuatStack(STACK s);
void DoiCoSo(int n, int b);
//======================================
//Ham tao nut co du lieu x, co next tro toi NULL
NODE* GetNode(Data x)
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
//Tao DS rong
void CreatStack(STACK& s)
{
	s.pHead = s.pTail = NULL;
}
//Ham chen x vao dau s
void Push(STACK& s, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nsoi cap phat bo nho! khong thuc hien duoc thao tac nay";
		return;
	}
	if (s.pHead == NULL)
	{
		s.pHead = new_ele; s.pTail = s.pHead;
	}
	else
	{
		new_ele->pNext = s.pHead;
		s.pHead = new_ele;
	}
}
void XuatStack(STACK s)
{
	NODE* p;
	if (s.pHead == NULL)
	{
		cout << "\nStack rong!\n";
		return;
	}
	p = s.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}
//Ham doi co so : (n)10 sang (n)b
void DoiCoSo(int n, int b)
{
	int du;
	STACK s;
	CreatStack(s);
	cout << endl << n;
	while (n)
	{
		du = n % b;
		Push(s, du);
		n = n / b;
	}
	cout << " bieu dien dang co so (" << b << ") :\n";
	XuatStack(s);
}