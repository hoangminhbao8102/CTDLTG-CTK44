#define NULLDATA '\0' // or any other special character that suits your case
#define MAX 100
//======================================
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
Data Pop(STACK& s);
int LaToanTu(char c);
int LaKySo(char c);
int So(char c);
int Tinh_BT_HauTo(char a[MAX]);
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
//Ham huy nut o dinh stack
Data Pop(STACK& s)
{
	Data x;
	NODE* p;
	if (s.pHead == NULL)
	{
		return NULLDATA;
	}
	x = s.pHead->info;
	p = s.pHead;
	s.pHead = s.pHead->pNext;
	delete p;
	if (s.pHead == NULL)
		s.pTail = NULL;
	return x;
}
// Ham kiem tra toan tu
int LaToanTu(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// Kiem tra toan hang - chi can kiem tra co phai la ky so
int LaKySo(char c)
{
	return isdigit(c);
}
//Đổi ký tự số thành số
int So(char c)
{
	return c - '0';
}
//Tính giá trị biểu thức đại số dạng hậu tố
int Tinh_BT_HauTo(char a[MAX])
{
	int i;
	char c;
	Data x, y;
	STACK s;
	CreatStack(s);
	for (i = 0; a[i] != NULL; i++)
	{
		c = a[i];
		if (LaKySo(c) == 1)
		{
			x = So(c);
			Push(s, x);
		}
		else //toan tu
		{
			x = Pop(s);
			y = Pop(s);
			switch (c)
			{
			case '+':
				Push(s, y + x);
				break;
			case '-':
				Push(s, y - x);
				break;
			case '*':
				Push(s, y * x);
				break;
			case '/':
				Push(s, y / x);
				break;
			case '%':
				Push(s, y % x);
				break;
			}
		}
	}//Ket thuc bieu thuc hau to
	return s.pHead->info; //Gia tri bieu thuc hau to
}