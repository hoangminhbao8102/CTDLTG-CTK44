#define MAX 100

typedef int DataType;

struct TagNode
{
    DataType info;
    TagNode* pNext;
};

typedef TagNode NODE;

struct SET
{
    NODE* pHead;
    NODE* pTail;
};

void XuatDS(SET l);
void File_List(const char* f, SET& l);
NODE* GetNode(DataType x);
void CreatList(SET& l);
int IsEmpty(SET l);

void InsertTail(SET& l, DataType x);
int SoNut(SET l);

SET Giao(SET l1, SET l2);
SET Hop(SET l1, SET l2);
SET Hieu(SET l1, SET l2);
SET HieuDoiXung(SET l1, SET l2);
void TichDescartes(SET l1, SET l2);
bool IsExist(SET l, DataType x);
bool IsSubset(SET l1, SET l2);
int Cardinality(SET l);

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

void CreatList(SET& l)
{
    l.pHead = l.pTail = NULL;
}

int IsEmpty(SET l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}

void File_List(const char* f, SET& l)
{
    ifstream in(f);
    if (!in)
    {
        cout << "\nLoi mo file!\n";
        return;
    }
    CreatList(l);
    DataType x;
    in >> x;
    InsertTail(l, x);
    while (!in.eof())
    {
        in >> x;
        InsertTail(l, x);
    }
    in.close();
}

void XuatDS(SET l)
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

void InsertTail(SET& l, DataType x)
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

int SoNut(SET l)
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

// Hàm giao 2 tập hợp
SET Giao(SET l1, SET l2)
{
    SET giao;
    CreatList(giao);

    NODE* p = l1.pHead;
    while (p != NULL)
    {
        if (IsExist(l2, p->info))
        {
            InsertTail(giao, p->info);
        }
        p = p->pNext;
    }

    return giao;
}

// Hàm hợp 2 tập hợp
SET Hop(SET l1, SET l2)
{
    SET hop;
    CreatList(hop);

    // Thêm tất cả các phần tử từ tập hợp thứ nhất vào tập hợp kết quả
    NODE* p = l1.pHead;
    while (p != NULL)
    {
        InsertTail(hop, p->info);
        p = p->pNext;
    }

    // Thêm các phần tử từ tập hợp thứ hai vào tập hợp kết quả (trừ những phần tử đã có)
    p = l2.pHead;
    while (p != NULL)
    {
        if (!IsExist(hop, p->info))
        {
            InsertTail(hop, p->info);
        }
        p = p->pNext;
    }

    return hop;
}

// Hàm hiệu 2 tập hợp (l1 - l2)
SET Hieu(SET l1, SET l2)
{
    SET hieu;
    CreatList(hieu);

    NODE* p = l1.pHead;
    while (p != NULL)
    {
        if (!IsExist(l2, p->info))
        {
            InsertTail(hieu, p->info);
        }
        p = p->pNext;
    }

    return hieu;
}

// Hàm hiệu đối xứng 2 tập hợp
SET HieuDoiXung(SET l1, SET l2)
{
    SET hieu1 = Hieu(l1, l2);
    SET hieu2 = Hieu(l2, l1);
    SET hieu_doi_xung = Hop(hieu1, hieu2);

    return hieu_doi_xung;
}

// Hàm tích Descartes 2 tập hợp
void TichDescartes(SET l1, SET l2)
{
    NODE* p1 = l1.pHead;
    while (p1 != NULL)
    {
        NODE* p2 = l2.pHead;
        while (p2 != NULL)
        {
            cout << "(" << p1->info << ", " << p2->info << ") ";
            p2 = p2->pNext;
        }
        p1 = p1->pNext;
    }
    cout << endl;
}

// Hàm kiểm tra phần tử có thuộc vào tập hợp
bool IsExist(SET l, DataType x)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
        if (p->info == x)
        {
            return true;
        }
        p = p->pNext;
    }
    return false;
}

// Hàm kiểm tra quan hệ bao hàm giữa 2 tập
bool IsSubset(SET l1, SET l2)
{
    NODE* p = l1.pHead;
    while (p != NULL)
    {
        if (!IsExist(l2, p->info))
        {
            return false;
        }
        p = p->pNext;
    }
    return true;
}

// Hàm tính lực lượng tập hợp
int Cardinality(SET l)
{
    return SoNut(l);
}