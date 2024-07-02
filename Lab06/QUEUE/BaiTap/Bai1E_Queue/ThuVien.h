typedef string Data; // Thay đổi kiểu dữ liệu của info thành string để lưu nội dung từng dòng của tập tin.
struct TagNode // Kieu Nut
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
void CreatQueue(QUEUE& q);
void EnQueue(QUEUE& q, Data x);
Data DeQueue(QUEUE& q);
void TapTin_Queue(char* f, QUEUE& q);
void XuatQueue(QUEUE q);
void PrintBuffer(QUEUE& buffer);
bool isBufferFull(QUEUE& buffer, int bufferSize);

NODE* GetNode(Data x)
{
    NODE* p = new NODE;
    if (p == nullptr)
    {
        cout << "Memory allocation failed!";
        return nullptr;
    }
    p->info = x;
    p->pNext = nullptr;
    return p;
}

void CreatQueue(QUEUE& q)
{
    q.pHead = nullptr;
    q.pTail = nullptr;
}

void EnQueue(QUEUE& q, Data x)
{
    NODE* p = GetNode(x);
    if (p == nullptr) return; // Memory allocation failed
    if (q.pHead == nullptr)
    {
        q.pHead = q.pTail = p;
    }
    else
    {
        q.pTail->pNext = p;
        q.pTail = p;
    }
}

Data DeQueue(QUEUE& q)
{
    if (q.pHead == nullptr)
    {
        cout << "Queue is empty!";
        return ""; // or any sentinel value
    }
    NODE* p = q.pHead;
    Data info = p->info;
    q.pHead = q.pHead->pNext;
    if (q.pHead == nullptr)
    {
        q.pTail = nullptr;
    }
    delete p;
    return info;
}

void TapTin_Queue(char* f, QUEUE& q)
{
    ifstream inFile(f);
    Data x;
    while (getline(inFile, x))
    {
        EnQueue(q, x);
    }
    inFile.close();
}

void XuatQueue(QUEUE q)
{
    NODE* p = q.pHead;
    while (p != nullptr)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}

void PrintBuffer(QUEUE& buffer)
{
    while (buffer.pHead != nullptr)
    {
        cout << DeQueue(buffer) << endl;
    }
}

bool isBufferFull(QUEUE& buffer, int bufferSize)
{
    int count = 0;
    NODE* p = buffer.pHead;
    while (p != nullptr)
    {
        count++;
        p = p->pNext;
    }
    return count >= bufferSize;
}