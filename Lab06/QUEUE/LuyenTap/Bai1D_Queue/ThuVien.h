#define MAX 100

typedef int Data;

struct TagNode
{
	Data info;
	TagNode* pNext;
};

typedef TagNode NODE;

struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};

NODE* GetNode(Data x);
void CreateQueue(QUEUE& q);
void InsertTail(QUEUE& q, Data x);
int File_Queue(const char* f, QUEUE& q);
int IsEmpty(QUEUE q);
void Output_Queue(QUEUE q);

void Enqueue(QUEUE& q, Data x);
Data Dequeue(QUEUE& q);
int Count(QUEUE& q, Data x);
void RemoveAll(QUEUE& q, Data x);
Data Top(QUEUE q);

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

void CreateQueue(QUEUE& q)
{
	q.pHead = q.pTail = NULL;
}

void InsertTail(QUEUE& q, Data x)
{
	NODE* new_ele = GetNode(x);
	if (new_ele == NULL)
	{
		cout << "\nLoi cap phat bo nho!";
		return;
	}
	if (q.pHead == NULL)
	{
		q.pHead = new_ele;
		q.pTail = q.pHead;
	}
	else
	{
		q.pTail->pNext = new_ele;
		q.pTail = new_ele;
	}
}

int File_Queue(const char* f, QUEUE& q)
{
	ifstream in(f);
	if (!in)
		return 0;
	CreateQueue(q);
	Data x;
	while (!in.eof())
	{
		in >> x;
		InsertTail(q, x);
	}
	in.close();
	return 1;
}

int IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
		return 1;
	return 0;
}

void Output_Queue(QUEUE q)
{
	NODE* p;
	if (q.pHead == NULL)
	{
		cout << "\nQueue rong!\n";
		return;
	}
	p = q.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}

void Enqueue(QUEUE& q, Data x)
{
	InsertTail(q, x);
}

Data Dequeue(QUEUE& q)
{
	Data x;
	NODE* p;
	if (q.pHead == NULL)
	{
		return NULL;
	}
	x = q.pHead->info;
	p = q.pHead;
	q.pHead = q.pHead->pNext;
	delete p;
	if (q.pHead == NULL)
		q.pTail = NULL;
	return x;
}

int Count(QUEUE& q, Data x)
{
	int count = 0;
	NODE* pNode = q.pHead;
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

void RemoveAll(QUEUE& q, Data x)
{
	NODE* current = q.pHead;
	NODE* prev = nullptr;

	while (current != nullptr)
	{
		if (current->info == x)
		{
			if (prev == nullptr)
			{ // Node to remove is the head
				q.pHead = current->pNext;
				delete current;
				current = q.pHead;
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

Data Top(QUEUE q)
{
	if (IsEmpty(q))
	{
		cout << "Queue rong!" << endl;
		return -1; // hoặc một giá trị nào đó phù hợp với ngữ cảnh của bạn
	}
	return q.pHead->info;
}
