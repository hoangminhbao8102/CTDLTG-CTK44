#define NULLDATA '\0'

typedef int Data;

struct TagNode
{
	Data info;
	TagNode* pNext;
};

typedef TagNode NODE;

struct STACK
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(Data x);
void CreatStack(STACK& s);
void InsertTail(STACK& s, Data x);
void File_Stack(const char* f, STACK& s);
void Output_Stack(STACK s);
void Push(STACK& s, Data x);

STACK AddNumbers(STACK& s1, STACK& s2);
STACK SubtractNumbers(STACK& s1, STACK& s2);
STACK MultiplyNumbers(STACK& s1, STACK& s2);

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

void CreatStack(STACK& s)
{
	s.pHead = s.pTail = NULL;
}

void InsertTail(STACK& s, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (s.pHead == NULL)
	{
		s.pHead = new_ele;
		s.pTail = s.pHead;
	}
	else
	{
		s.pTail->pNext = new_ele;
		s.pTail = new_ele;
	}
}

void File_Stack(const char* f, STACK& s)
{
	ifstream in(f);
	if (!in)
	{
		cout << "Khong the mo file " << f << endl;
		return;
	}
	CreatStack(s);
	Data x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(s, x);
	}
	in.close();
}

void Output_Stack(STACK s)
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

// Hàm cộng hai số lớn sử dụng stack
STACK AddNumbers(STACK& s1, STACK& s2)
{
	STACK result;
	CreatStack(result);
	int carry = 0;
	Data top1, top2;

	while (s1.pHead != NULL || s2.pHead != NULL || carry != 0) 
	{
		top1 = (s1.pHead != NULL) ? Pop(s1) : 0;
		top2 = (s2.pHead != NULL) ? Pop(s2) : 0;
		int sum = top1 + top2 + carry;
		Push(result, sum % 10);
		carry = sum / 10;
	}
	return result;
}

// Hàm trừ hai số lớn
STACK SubtractNumbers(STACK& s1, STACK& s2)
{
	STACK result;
	CreatStack(result);
	int borrow = 0;
	Data top1, top2;

	while (s1.pHead != NULL || s2.pHead != NULL) 
	{
		top1 = (s1.pHead != NULL) ? Pop(s1) : 0;
		top2 = (s2.pHead != NULL) ? Pop(s2) + borrow : borrow;
		if (top1 < top2) 
		{
			top1 += 10;
			borrow = 1;
		}
		else 
		{
			borrow = 0;
		}
		Push(result, top1 - top2);
	}
	// Remove leading zeros
	while (result.pHead != NULL && result.pHead->info == 0) 
	{
		Pop(result);
	}
	return result;
}

// Hàm nhân hai số lớn
STACK MultiplyNumbers(STACK& s1, STACK& s2)
{
	STACK result, temp;
	CreatStack(result);
	int digitPosition = 0;

	for (NODE* i = s1.pHead; i != NULL; i = i->pNext) 
	{
		CreatStack(temp);
		int carry = 0;

		// Add zeroes based on the position of the digit
		for (int j = 0; j < digitPosition; j++) 
		{
			Push(temp, 0);
		}

		for (NODE* j = s2.pHead; j != NULL; j = j->pNext) 
		{
			int product = i->info * j->info + carry;
			Push(temp, product % 10);
			carry = product / 10;
		}

		if (carry > 0) 
		{
			Push(temp, carry);
		}

		// Add this result to the main result stack
		STACK sumResult = AddNumbers(result, temp);
		result = sumResult; // Assume proper stack copy or move semantics
		digitPosition++;
	}

	return result;
}