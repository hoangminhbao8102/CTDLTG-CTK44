int Search(LLIST l, Data x);
int Search_Pos_First(LLIST l, Data x);
int Search_Pos_End(LLIST l, Data x);
void Search_All_Pos_x(LLIST l, Data x);
NODE* Search_End(LLIST l, Data x);
int Head_New(LLIST& l, Data x);
void RemoveHead(LLIST& l);
void RemoveTail(LLIST& l);
void RemoveLLIST(LLIST& l);
int SoNut(LLIST l);
void Copy_Llist(LLIST l, LLIST& l1);

//Tim kiem co (1)/khong(0)
int Search(LLIST l, Data x)
{
	NODE* p;
	p = l.pHead;
	do
	{
		if (p->info == x)
			return 1;
		p = p->pNext;
	} while (p != l.pHead); //Chua giap vong
	return 0;
}
//=======================================================
//Tim vi tri nut dau tien Pos co info la x; Nut dau tien cua DS dem tu 0
//Khong co: ham tra ve -1
//Co : Tra ve vi tri cua nut dau tien co info la x
int Search_Pos_First(LLIST l, Data x)
{
	NODE* p;
	int kq = -1, //khong co
		i = 0;
	p = l.pHead;
	do
	{
		if (p->info == x)
		{
			kq = i;
			break;
		}
		p = p->pNext;
		i++;
	} while (p != l.pHead); //Chua giap vong
	return kq;
}
//=======================================================
// Tim vi tri nut cuoi cung Pos co info la x; Nut dau tien cua DS dem tu 0
//Khong co: ham tra ve -1
//Co : Tra ve vi tri cua nut cuoi cung co info la x
int Search_Pos_End(LLIST l, Data x)
{
	NODE* p;
	int kq = -1, //khong co
		i = 0;
	p = l.pHead;
	do
	{
		if (p->info == x)
			kq = i;
		p = p->pNext;
		i++;
	} while (p != l.pHead); //Chua giap vong
	return kq;
}
//=======================================================
//Tim nut co info la x:
//Khong co: Thong bao khong
//Neu co, ham xuat tat ca cac vi tri x xuat hien
//Nut dau tien dem tu 0
void Search_All_Pos_x(LLIST l, Data x)
{
	NODE* p;
	int i = 0;
	int kq = Search(l, x);
	if (!kq)
	{
		cout << endl << x << " khong co trong danh sach";
		return;
	}
	cout << endl << x << " xuat hien trong danh sach tai cac vi tri :\n";
	p = l.pHead;
	do
	{
		if (p->info == x)
			cout << i << '\t';
		p = p->pNext;
		i++;
	} while (p != l.pHead); //Chua giap vong
}
//=======================================================
//Co : tra ve dia chi nut cuoi cung co x
//Khong : NULL
NODE* Search_End(LLIST l, Data x)
{
	NODE* p, * q = NULL;
	p = l.pHead;
	if (p == NULL);
	else
	{
		do
		{
			if (p->info == x)
				q = p;
			p = p->pNext;
		} while (p != l.pHead); //Chua giap vong
	}
	return q;
}
//=======================================================
//DS moi co Head tro toi nut cuoi x xuat hien
int Head_New(LLIST& l, Data x)
{
	NODE* q, * r = NULL;
	if (l.pHead == NULL)
		return 0;
	q = Search_End(l, x);
	if (q == NULL)
		return -1;
	l.pHead = q;
	do
	{
		r = q;
		q = q->pNext;
	} while (q != l.pHead);
	l.pTail = r;
	l.pTail->pNext = l.pHead;
	return 1;
}
//====================================================
//Huy
//====================================================
//Huy nut dau
void RemoveHead(LLIST& l)
{
	NODE* p = l.pHead;
	if (p == NULL) return;
	if (l.pHead == l.pTail) // 1nut
		l.pHead = l.pTail = NULL;
	else
	{
		l.pHead = p->pNext; // Cap nhat lai Head
		l.pTail->pNext = l.pHead;//Cap nhat Next cua Tail
	}
	delete p;
}
//====================================================
//Huy nut cuoi
void RemoveTail(LLIST& l)
{
	NODE* p, * q;
	if (l.pHead == NULL)
		return;
	//xac dinh dia chi nut dung truoc Tail : q
	p = l.pHead;
	q = NULL;
	do
	{
		q = p;
		p = p->pNext;
	} while (p != l.pTail);
	l.pTail = q; //q->pNext != NULL
	delete p;
	if (l.pTail == NULL)//Tail moi
		l.pHead = NULL;
	else
		l.pTail->pNext = l.pHead;
}
//====================================================
//Huy DS
void RemoveLLIST(LLIST& l)
{
	if (l.pHead == NULL)
		return;
	NODE* p;
	do
	{
		p = l.pHead;
		l.pHead = p->pNext; // Cap nhat lai Head
		l.pTail->pNext = l.pHead;//Cap nhat Next cua Tail
		delete p;
	} while (l.pHead != l.pTail);
	p = l.pHead;
	l.pHead = l.pTail = NULL;
	delete p;
}
//====================================================
//Dem so luong nut
int SoNut(LLIST l)
{
	if (l.pHead == NULL)
		return 0;

	int count = 0;
	NODE* p = l.pHead;
	do
	{
		count++;
		p = p->pNext;
	} while (p != l.pHead); // Chưa giáp vòng

	return count;
}
//====================================================
//Copy l sang l1
void Copy_Llist(LLIST l, LLIST& l1)
{
	CreatLLIST(l1);
	if (l.pHead == NULL)
		return;
	NODE* p;
	p = l.pHead;
	do
	{
		InsertTail(l1, p->info);
		p = p->pNext;
	} while (p != l.pHead);
}