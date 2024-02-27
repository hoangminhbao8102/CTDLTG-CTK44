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

NODE* GetNode(DataType x);
void CreatList(LIST& l);
int IsEmpty(LIST l);
int File_List(char* f, LIST& l);
void XuatDS(LIST l);

void InsertTail(LIST& l, DataType x);

int SoNut(LIST l);

DataType MinValue(LIST l);
DataType MaxValue(LIST l);
int CountValue(LIST l, DataType x);
DataType SumValues(LIST l);
DataType SumDistinctValues(LIST l);
void UniqueValuesCount(LIST l);
void InsertionSort(LIST& l);
void SortList(LIST& l);

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

DataType MinValue(LIST l)
{
	NODE* p = l.pHead;
	if (p == NULL)
		return INT_MAX;
	DataType min_val = p->info;
	while (p != NULL)
	{
		if (p->info < min_val)
			min_val = p->info;
		p = p->pNext;
	}
	return min_val;
}

DataType MaxValue(LIST l)
{
	NODE* p = l.pHead;
	if (p == NULL)
		return INT_MIN;
	DataType max_val = p->info;
	while (p != NULL)
	{
		if (p->info > max_val)
			max_val = p->info;
		p = p->pNext;
	}
	return max_val;
}

int CountValue(LIST l, DataType x)
{
	NODE* p = l.pHead;
	int count = 0;
	while (p != NULL)
	{
		if (p->info == x)
			count++;
		p = p->pNext;
	}
	return count;
}

DataType SumValues(LIST l)
{
	NODE* p = l.pHead;
	DataType sum = 0;
	while (p != NULL)
	{
		sum += p->info;
		p = p->pNext;
	}
	return sum;
}

DataType SumDistinctValues(LIST l)
{
	NODE* p = l.pHead;
	LIST unique_list;
	CreatList(unique_list);

	while (p != NULL)
	{
		if (CountValue(unique_list, p->info) == 0)
			InsertTail(unique_list, p->info);
		p = p->pNext;
	}

	return SumValues(unique_list);
}

void UniqueValuesCount(LIST l)
{
	NODE* p = l.pHead;
	LIST unique_list;
	CreatList(unique_list);

	while (p != NULL)
	{
		if (CountValue(unique_list, p->info) == 0)
			InsertTail(unique_list, p->info);
		p = p->pNext;
	}

	p = unique_list.pHead;
	while (p != NULL)
	{
		cout << "Value " << p->info << " appears " << CountValue(l, p->info) << " times." << endl;
		p = p->pNext;
	}
}

void InsertionSort(LIST& l)
{
	if (IsEmpty(l) || l.pHead->pNext == NULL)
		return;

	NODE* p = l.pHead->pNext;
	while (p != NULL)
	{
		NODE* key = p;
		DataType temp = key->info;
		NODE* prev = p;
		NODE* q = l.pHead;
		while (q != key && q->info < temp)
		{
			prev = q;
			q = q->pNext;
		}
		if (q != key)
		{
			while (q != key)
			{
				prev->info = q->info;
				prev = q;
				q = q->pNext;
			}
			prev->info = temp;
		}
		p = p->pNext;
	}
}

void SortList(LIST& l)
{
	NODE* p = l.pHead;
	LIST negatives, positives;
	CreatList(negatives);
	CreatList(positives);

	while (p != NULL)
	{
		if (p->info == 0)
			InsertTail(negatives, p->info);
		else if (p->info < 0)
			InsertTail(negatives, p->info);
		else
			InsertTail(positives, p->info);
		p = p->pNext;
	}

	InsertionSort(negatives);
	InsertionSort(positives);

	if (!IsEmpty(negatives))
	{
		l.pHead = negatives.pHead;
		l.pTail = negatives.pTail;
		l.pTail->pNext = positives.pHead;
	}
	else
	{
		l.pHead = positives.pHead;
		l.pTail = positives.pTail;
	}
}