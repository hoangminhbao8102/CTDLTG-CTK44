#define MAX 100
//======================================
typedef char Data;//Kieu thanh phan du sieu cua nut
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
//=======================================================
NODE* GetNode(Data x);
void CreatStack(STACK& s);
void Push(STACK& s, Data x);
void Chep_Chuoi_Sang_Stack(STACK& s, char X[MAX]);
void Chep_Stack_Sang_Chuoi(STACK s, char Y[MAX]);
//=======================================================
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
void Chep_Chuoi_Sang_Stack(STACK& s, char X[MAX])
{
	CreatStack(s);
	if (X[0] == NULL)
		return;
	int i;
	for (i = 0; X[i] != NULL; i++)
		Push(s, X[i]);
}
void Chep_Stack_Sang_Chuoi(STACK s, char Y[MAX])
{
	Y[0] = NULL;
	if (s.pHead == NULL)
		return;
	NODE* p;
	p = s.pHead;
	int i = 0;
	while (p != NULL)
	{
		Y[i++] = p->info;
		p = p->pNext;
	}
	Y[i] = NULL;
}