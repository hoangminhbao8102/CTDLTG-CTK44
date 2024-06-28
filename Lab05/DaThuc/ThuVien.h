#define MAX 100

struct Poly
{
	double coef;
	int expo;
};

typedef Poly DataType;

struct TagNode
{
	DataType info;
	TagNode* pNext;
};

typedef TagNode NODE;

struct POLY
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(DataType x);
void CreatPoly(POLY& a);
void InsertTail(POLY& a, DataType x);
void File_Poly(const char* f, POLY& a);
int IsEmpty(POLY a);
void Output_Poly(POLY a);

void Sort_Expo(POLY& a);
void Reduction(POLY& a);

POLY Add(POLY a, POLY b);
POLY Minus(POLY a, POLY b);
POLY Mult_Node(POLY a, NODE* p);
POLY Mult_Poly(POLY a, POLY b);
double ValueP(POLY a, double x);
POLY DeriveA(POLY a);
POLY IntegratePoly(POLY& a);

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

void CreatPoly(POLY& a)
{
	a.pHead = a.pTail = NULL;
}

void InsertTail(POLY& a, DataType x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (a.pHead == NULL)
	{
		a.pHead = new_ele;
		a.pTail = a.pHead;
	}
	else
	{
		a.pTail->pNext = new_ele;
		a.pTail = new_ele;
	}
}

void File_Poly(const char* f, POLY& a)
{
	ifstream in(f);
	if (!in)
	{
		cout << "\nLoi mo file!\n";
		return;
	}
	CreatPoly(a);
	DataType x;
	in >> x.coef;
	in >> x.expo;
	InsertTail(a, x);
	while (!in.eof())
	{
		in >> x.coef;
		in >> x.expo;
		InsertTail(a, x);
	}
	in.close();
}

int IsEmpty(POLY a)
{
	if (a.pHead == NULL)
		return 1;
	return 0;
}

void Output_Poly(POLY a)
{
	if (a.pHead == NULL)
	{
		cout << "\nDa thuc rong";
		return;
	}
	NODE* p;
	//xu ly nhan tu dau tien, so mu co the == 0
	p = a.pHead;
	if (p->info.expo == 0) //so mu = 0
		cout << p->info.coef;
	else // so mu > 0 : >= 1
	{
		if (p->info.expo == 1) // so mu = 1
		{
			if (p->info.coef == 1) //he so == 1
				cout << "x ";
			else // he so !=1
				if (p->info.coef == -1)
					cout << "-x ";
				else
					cout << p->info.coef << "x ";
		}
		else //so mu > 1
		{
			if (p->info.coef == 1) //he so == 1
				cout << "x^" << p->info.expo << " ";
			else // he so !=1
				if (p->info.coef == -1)
					cout << "-x^" << p->info.expo << " ";
				else
					cout << p->info.coef << "x^" << p->info.expo << " ";
		}
	}
	//xu ly cac hang tu tiêp theo
	p = p->pNext;
	while (p != NULL)
	{
		//so mu > 0
		if (p->info.expo == 1) // so mu = 1
		{
			if (p->info.coef == 1) //he so == 1
				cout << "+x ";
			else // he so !=1
				if (p->info.coef == -1)
					cout << "-x ";
				else
					if (p->info.coef > 0)
						cout << "+ " << p->info.coef << "x ";
					else
						cout << p->info.coef << "x ";
		}
		else //so mu > 1
		{
			if (p->info.coef == 1) //he so == 1
				cout << "+x^" << p->info.expo << " ";
			else // he so !=1
				if (p->info.coef == -1)
					cout << "-x^" << p->info.expo << " ";
				else
					if (p->info.coef > 0)
						cout << "+ " << p->info.coef << "x^" << p->info.expo << " ";
					else //(he so < 0)
						cout << p->info.coef << "x^" << p->info.expo << " ";
		}
		p = p->pNext;
	}
}

void Sort_Expo(POLY& a)
{
	// Kiểm tra danh sách rỗng hoặc chỉ có một phần tử
	if (a.pHead == NULL || a.pHead == a.pTail)
		return;

	NODE* min, * p, * q;
	p = a.pHead;
	while (p != a.pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->info.expo < min->info.expo)
				min = q;
			q = q->pNext;
		}
		// Hoán đổi thông tin giữa nút hiện tại và nút nhỏ nhất tìm được
		if (min != p) {
			swap(min->info, p->info);
		}
		p = p->pNext;
	}
}

void Reduction(POLY& a)
{
	if (a.pHead == NULL)
	{
		cout << "\nDa thuc rong";
		system("PAUSE");
		return;
	}
	int Kq;
	POLY b;
	NODE* pB;
	NODE* pA;
	pA = a.pHead;
	CreatPoly(b);
	while (pA != NULL)
	{
		Kq = 0;
		pB = b.pHead;
		while (pB != NULL)
		{
			if (pB->info.expo == pA->info.expo)
			{
				Kq = 1;
				break;
			}
			pB = pB->pNext;
		}
		if (Kq == 1)
			pB->info.coef += pA->info.coef;
		else
			InsertTail(b, pA->info);
		pA = pA->pNext;
	}
	a = b;
}

POLY Add(POLY a, POLY b)
{
	POLY kq;
	CreatPoly(kq);
	DataType x;
	NODE* pA = a.pHead, * pB = b.pHead;
	while (pA != NULL && pB != NULL)
	{
		if (pA->info.expo < pB->info.expo)
		{
			InsertTail(kq, pA->info);
			pA = pA->pNext;
		}
		else if (pA->info.expo > pB->info.expo)
		{
			InsertTail(kq, pB->info);
			pB = pB->pNext;
		}
		else
		{
			x.coef = pA->info.coef + pB->info.coef;
			x.expo = pA->info.expo;
			if (x.coef != 0)
				InsertTail(kq, x);
			pA = pA->pNext;
			pB = pB->pNext;
		}
	}
	while (pA != NULL)
	{
		InsertTail(kq, pA->info);
		pA = pA->pNext;
	}
	while (pB != NULL)
	{
		InsertTail(kq, pB->info);
		pB = pB->pNext;
	}
	Reduction(kq);
	Sort_Expo(kq);
	return kq;
}

POLY Minus(POLY a, POLY b)
{
	POLY kq;
	CreatPoly(kq);
	DataType x;
	NODE* pA = a.pHead, * pB = b.pHead;
	while (pA != NULL && pB != NULL)
	{
		if (pA->info.expo < pB->info.expo)
		{
			InsertTail(kq, pA->info);
			pA = pA->pNext;
		}
		if (pA->info.expo > pB->info.expo)
		{
			x.coef = -pB->info.coef;
			x.expo = pB->info.expo;
			InsertTail(kq, x);
			pB = pB->pNext;
		}
		if (pA->info.expo == pB->info.expo)
		{
			x.coef = pA->info.coef - pB->info.coef;
			x.expo = pA->info.expo;
			if (x.coef != 0)
				InsertTail(kq, x);
			pA = pA->pNext;
			pB = pB->pNext;
		}
	}
	while (pA != NULL)
	{
		InsertTail(kq, pA->info);
		pA = pA->pNext;
	}
	while (pB != NULL)
	{
		x.coef = -pB->info.coef;
		x.expo = pB->info.expo;
		InsertTail(kq, x);
		pB = pB->pNext;
	}
	Reduction(kq);
	Sort_Expo(kq);
	return kq;
}

POLY Mult_Node(POLY a, NODE* p)
{
	POLY kq;
	CreatPoly(kq);
	DataType x;
	NODE* pA = a.pHead;
	while (pA != NULL)
	{
		x.expo = pA->info.expo + p->info.expo;
		x.coef = pA->info.coef * p->info.coef;
		InsertTail(kq, x);
		pA = pA->pNext;
	}
	Reduction(kq);
	Sort_Expo(kq);
	return kq;
}

POLY Mult_Poly(POLY a, POLY b)
{
	POLY kq, t1, t2;
	CreatPoly(kq);
	CreatPoly(t1);
	CreatPoly(t2);
	NODE* pA;
	pA = a.pHead;
	while (pA != NULL)
	{
		t1 = Mult_Node(b, pA);
		t2 = Add(kq, t1);
		kq = t2;
		pA = pA->pNext;
	}
	return kq;
}

double ValueP(POLY a, double x)
{
	double kq = 0, t;
	NODE* pA = a.pHead;
	while (pA != NULL)
	{
		t = pA->info.coef * pow(x, pA->info.expo);
		kq = kq + t;
		pA = pA->pNext;
	}
	return kq;
}

POLY DeriveA(POLY a)
{
	POLY kq;
	CreatPoly(kq);
	NODE* pA = a.pHead;
	DataType x;
	while (pA != NULL)
	{
		if (pA->info.expo == 0)
		{
			x.coef = 0;
			x.expo = 0;
		}
		else
		{
			x.coef = pA->info.expo * pA->info.coef;
			x.expo = pA->info.expo - 1;
		}
		if (x.coef != 0)
			InsertTail(kq, x);
		pA = pA->pNext;
	}
	Reduction(kq);
	Sort_Expo(kq);
	return kq;
}

POLY IntegratePoly(POLY& a) 
{
	POLY kq;
	CreatPoly(kq);
	NODE* p = a.pHead;
	DataType x;

	while (p != nullptr) 
	{
		x.expo = p->info.expo + 1;  // Tăng số mũ lên 1
		x.coef = p->info.coef / x.expo;  // Chia hệ số cho số mũ mới

		InsertTail(kq, x);
		p = p->pNext;
	}

	return kq;
}