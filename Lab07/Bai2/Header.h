//Header DSLK vong : Dinh nghia va cac thao tac co ban
#define MAX 30
//Dinh nghia kieu du lieu thanh phan cua nut trong DSLK don vong
typedef char Data[MAX];//Kieu thanh phan du lieu cua nut
struct TagNode //Kieu cac Nut cua danh sach LK don vong
{
	Data info;
	TagNode* pNext;
};
typedef TagNode NODE; //// Doi lai ten kieu Nut
struct LLIST ////Kieu DSLK don
{
	NODE* pHead; //Chua dc nut dau
	NODE* pTail; //Chua dc nut cuoi
};
//=========================================================
//Khai bao cac ham co ban
NODE* GetNode(Data x);
void CreatLLIST(LLIST& l);
void InsertTail(LLIST& l, Data x);
void Output_Llist(LLIST l);
int File_LLIST(const char* f, LLIST& l);
//=========================================================
//Dinh nghia ca ham co ban
//Ham tao nut co info la x, next co gia tri NULL
NODE* GetNode(Data x)
{
	NODE* p;
	p = new NODE;
	if (p != NULL)
	{
		strcpy_s(p->info, x);
		p->pNext = NULL;
	}
	return p;
}
//Tao DS rong
void CreatLLIST(LLIST& l)
{
	l.pHead = l.pTail = NULL;
}
//=======================================================
//Chen
//=======================================================
//Ham chen x vao cuoi l : Tao nut co info la x, next tro toi NULL, chen nut nay vao cuoi l
void InsertTail(LLIST& l, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho! khong thuc hien duoc thao tac nay";
		return;
	}
	if (l.pHead == NULL)//Chen vao DS rong
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
		l.pTail->pNext = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}
//Nhap, xuat
//=======================================================
void Output_Llist(LLIST l)
{
	NODE* p;
	if (l.pHead == NULL)
	{
		cout << "\nDS don vong rong!\n";
		return;
	}
	p = l.pHead;
	do
	{
		cout << p->info << '\t';
		p = p->pNext;
	} while (p != l.pHead); //Chua giap vong
}
//Tap tin -> LLIST
int File_LLIST(const char* f, LLIST& l)
{
	ifstream in(f); //Mo de doc
	if (!in)
		return 0;
	CreatLLIST(l);
	Data x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(l, x);
	}
	in.close();
	return 1;
}