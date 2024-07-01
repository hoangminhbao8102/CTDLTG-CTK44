#define NULLDATA '\0'
#define MAX 100

// Data type and node structure for infix to postfix conversion
typedef char DataChar;
struct TagNodeChar 
{
    DataChar info;
    TagNodeChar* pNext;
};
typedef TagNodeChar NODEChar;
struct STACKChar 
{
    NODEChar* pHead;
    NODEChar* pTail;
};

NODEChar* GetNodeChar(DataChar x);
void CreateStackChar(STACKChar& s);
void PushChar(STACKChar& s, DataChar x);
DataChar PopChar(STACKChar& s);
int Do_UuTien_ToanTu(char c);
int LaToanTu(char c);
void Chen_Cuoi_Chuoi(char a[MAX], char c);
int LaKySo(char c);
void Chen_Cuoi_Chuoi(char a[MAX], char c);

NODEChar* GetNodeChar(DataChar x) 
{
    NODEChar* p = new NODEChar;
    if (p != NULL) 
    {
        p->info = x;
        p->pNext = NULL;
    }
    return p;
}

void CreateStackChar(STACKChar& s) 
{
    s.pHead = s.pTail = NULL;
}

void PushChar(STACKChar& s, DataChar x) 
{
    NODEChar* new_ele = GetNodeChar(x);
    if (new_ele == NULL) 
    {
        cout << "\nMemory allocation failed! Cannot perform this operation";
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

DataChar PopChar(STACKChar& s) 
{
    DataChar x;
    NODEChar* p;
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

int Do_UuTien_ToanTu(char c) 
{
    if (c == '+' || c == '-') 
    {
        return 1;
    }
    else if (c == '*' || c == '/') 
    {
        return 2;
    }
    else if (c == '^') 
    {
        return 3;
    }
    return -1;
}

int LaToanTu(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void Chen_Cuoi_Chuoi(char a[MAX], char c) 
{
    int len = strlen(a);
    if (len < MAX - 1) 
    {
        a[len] = c;
        a[len + 1] = '\0';
    }
}

int LaKySo(char c) 
{
    return isdigit(c);
}

void TrungTo_HauTo(char sin[MAX], char sout[MAX]) 
{
    STACKChar s;
    char c;
    DataChar x;
    int i;
    CreateStackChar(s);
    for (i = 0; sin[i] != NULL; i++) 
    {
        c = sin[i];
        if (LaKySo(c) == 1) 
        {
            Chen_Cuoi_Chuoi(sout, c);
        }
        else if (c == '(') 
        {
            PushChar(s, c);
        }
        else if (c == ')') 
        {
            x = PopChar(s);
            while (x != '(') 
            {
                Chen_Cuoi_Chuoi(sout, x);
                x = PopChar(s);
            }
        }
        else 
        {
            while (s.pHead != NULL && LaToanTu(s.pHead->info) == 1) 
            {
                if (Do_UuTien_ToanTu(s.pHead->info) >= Do_UuTien_ToanTu(c)) 
                {
                    x = PopChar(s);
                    Chen_Cuoi_Chuoi(sout, x);
                }
                else 
                {
                    break;
                }
            }
            PushChar(s, c);
        }
    }
    while (s.pHead != NULL) 
    {
        x = PopChar(s);
        Chen_Cuoi_Chuoi(sout, x);
    }
}

// Data type and node structure for postfix evaluation
typedef int DataInt;
struct TagNodeInt {
    DataInt info;
    TagNodeInt* pNext;
};
typedef TagNodeInt NODEInt;
struct STACKInt {
    NODEInt* pHead;
    NODEInt* pTail;
};

NODEInt* GetNodeInt(DataInt x);
void CreateStackInt(STACKInt& s);
void PushInt(STACKInt& s, DataInt x);
DataInt PopInt(STACKInt& s);
int So(char c);
int Tinh_BT_HauTo(char a[MAX]);

NODEInt* GetNodeInt(DataInt x) 
{
    NODEInt* p = new NODEInt;
    if (p != NULL) 
    {
        p->info = x;
        p->pNext = NULL;
    }
    return p;
}

void CreateStackInt(STACKInt& s) 
{
    s.pHead = s.pTail = NULL;
}

void PushInt(STACKInt& s, DataInt x) 
{
    NODEInt* new_ele = GetNodeInt(x);
    if (new_ele == NULL) 
    {
        cout << "\nMemory allocation failed! Cannot perform this operation";
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

DataInt PopInt(STACKInt& s) 
{
    DataInt x;
    NODEInt* p;
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

int So(char c) 
{
    return c - '0';
}

int Tinh_BT_HauTo(char a[MAX])
{
    int i;
    char c;
    DataInt x, y;
    STACKInt s;
    CreateStackInt(s);
    for (i = 0; a[i] != NULL; i++) 
    {
        c = a[i];
        if (LaKySo(c) == 1) 
        {
            x = So(c);
            PushInt(s, x);
        }
        else 
        {
            x = PopInt(s);
            y = PopInt(s);
            switch (c) 
            {
            case '+':
                PushInt(s, y + x);
                break;
            case '-':
                PushInt(s, y - x);
                break;
            case '*':
                PushInt(s, y * x);
                break;
            case '/':
                PushInt(s, y / x);
                break;
            }
        }
    }
    return s.pHead->info;
}