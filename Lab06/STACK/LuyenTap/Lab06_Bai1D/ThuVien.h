#define MAX 100

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
int File_Stack(const char* f, STACK& s);
int IsEmpty(STACK s);
void Output_Stack(STACK s);

void Push(STACK& s, Data x);
Data Pop(STACK& s);
int Count(STACK& s, Data x);
void RemoveAll(STACK& s, Data x);
Data Top(STACK s);

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

int File_Stack(const char* f, STACK& s)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreatStack(s);
	Data x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(s, x);
	}
	in.close();
	return 1;
}

int IsEmpty(STACK s)
{
	if (s.pHead == NULL)
		return 1;
	return 0;
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
		return NULL;
	}
	x = s.pHead->info;
	p = s.pHead;
	s.pHead = s.pHead->pNext;
	delete p;
	if (s.pHead == NULL)
		s.pTail = NULL;
	return x;
}

int Count(STACK& s, Data x) 
{
	int count = 0;
	NODE* pNode = s.pHead;
	while (pNode != nullptr) 
	{
		if (pNode->info == x) 
		{
			count++;
		}
		pNode = pNode->pNext;
	}
	return count;
}

void RemoveAll(STACK& s, Data x) 
{
	NODE* current = s.pHead;
	NODE* prev = nullptr;

	while (current != nullptr) 
	{
		if (current->info == x) 
		{
			if (prev == nullptr) 
			{ // Node to remove is the head
				s.pHead = current->pNext;
				delete current;
				current = s.pHead;
			}
			else 
			{
				prev->pNext = current->pNext;
				delete current;
				current = prev->pNext;
			}
		}
		else 
		{
			prev = current;
			current = current->pNext;
		}
	}
}

Data Top(STACK s)
{
	if (IsEmpty(s))
	{
		cout << "Stack rong!" << endl;
		return -1; // hoặc một giá trị nào đó phù hợp với ngữ cảnh của bạn
	}
	return s.pHead->info;
}