#define NULLDATA '\0'
#define MAX 100

//======================================
typedef char Data; // Kieu thanh phan du lieu cua nut
struct TagNode // Kieu Nut
{
    Data info;
    TagNode* pNext;
};
typedef TagNode NODE;
struct STACK
{
    NODE* pHead; // Chua nut dau
    NODE* pTail; // Chua nut cuoi
};
//======================================
NODE* GetNode(Data x);
void CreatStack(STACK& s);
void Push(STACK& s, Data x);
Data Pop(STACK& s);
int Do_UuTien_ToanTu(char c);
int LaToanTu(char c);
void Chen_Cuoi_Chuoi(char a[MAX], char c);
int LaKySo(char c);
void TrungTo_HauTo(char sin[MAX], char sout[MAX]);

//======================================
// Ham tao nut co du lieu x, co next tro toi NULL
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

// Tao DS rong
void CreatStack(STACK& s)
{
    s.pHead = s.pTail = NULL;
}

// Ham chen x vao dau s
void Push(STACK& s, Data x)
{
    NODE* new_ele = GetNode(x);
    if (new_ele == NULL)
    {
        cout << "\nloi cap phat bo nho! khong thuc hien duoc thao tac nay";
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

// Ham do uu tien cua toan tu
int Do_UuTien_ToanTu(char c)
{
    if (c == '+' || c == '-') {
        return 1; // Lowest precedence
    }
    else if (c == '*' || c == '/') {
        return 2; // Higher precedence
    }
    else if (c == '^') {
        return 3; // Highest precedence (right-associative)
    }
    return -1; // Not an operator
}

// Ham kiem tra toan tu
int LaToanTu(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Ham chen ky tu c vao cuoi chuoi a
void Chen_Cuoi_Chuoi(char a[MAX], char c)
{
    int len = strlen(a);
    if (len < MAX - 1) {
        a[len] = c;
        a[len + 1] = '\0'; // Ensure the string is null-terminated
    }
}

// Ham kiem tra toan hang - kiem tra co phai la ky so hoac ky tu chu
int LaKySo(char c)
{
    return isdigit(c) | isalpha(c);
}

// Ham chuyen tu trung to sang hau to
void TrungTo_HauTo(char sin[MAX], char sout[MAX])
{
    STACK s; // stack luu cac toan tu
    char c; // Ky tu hien hanh - dang xet
    Data x; // luu toan tu o dinh stack trong thao tac Pop(s);
    int i; // duyet chuoi vao : sin
    CreatStack(s);
    // duyet tu trai sang phai cac phan tu cua bieu thuc trung to P
    for (i = 0; sin[i] != NULL; i++)
    {
        c = sin[i]; // ky tu dang xet
        if (LaKySo(c)) // la ky so hoac chu: toan hang
            Chen_Cuoi_Chuoi(sout, c); // chen c vao cuoi sout
        else if (c == '(')
            Push(s, c); // day '(' vao stack s
        else if (c == ')')
        {
            x = Pop(s);
            while (x != '(')
            {
                Chen_Cuoi_Chuoi(sout, x);
                x = Pop(s);
            }
        }
        else // la toan tu
        {
            while (s.pHead != NULL && LaToanTu(s.pHead->info) == 1)
            {
                if (Do_UuTien_ToanTu(s.pHead->info) >= Do_UuTien_ToanTu(c))
                {
                    x = Pop(s);
                    Chen_Cuoi_Chuoi(sout, x);
                }
                else
                    break;
            }
            // Push toan tu dang xet vao s
            Push(s, c);
        }
    }
    // lay cac toan tu con lai trong s chen vao cuoi sout
    while (s.pHead != NULL)
    {
        x = Pop(s);
        Chen_Cuoi_Chuoi(sout, x);
    }
}