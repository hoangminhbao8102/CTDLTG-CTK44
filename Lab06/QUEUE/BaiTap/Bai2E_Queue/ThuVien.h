// Kiểu dữ liệu cho thông tin chứng từ
struct Document 
{
    string date; // Ngày tháng năm dạng DD/MM/YYYY
    int quantity; // Số lượng
    string currency; // Đơn vị tiền tệ
    double exchangeRate; // Tỷ giá
    string type; // Loại nhập (IN) hoặc xuất (OUT)
    double amountVND; // Thành tiền VND
};

// Cập nhật NODE để chứa thông tin chứng từ
struct TagNode 
{
    Document info;
    TagNode* pNext;
};

typedef TagNode NODE;
struct QUEUE 
{
    NODE* pHead;
    NODE* pTail;
};

NODE* GetNode(Document x);
void CreatQueue(QUEUE& q);
void EnQueue(QUEUE& q, Document x);
Document DeQueue(QUEUE& q);
void TapTin_Queue(char* f, QUEUE& q);
void XuatQueue(QUEUE q);

NODE* GetNode(Document x) 
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

void EnQueue(QUEUE& q, Document x) 
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

Document DeQueue(QUEUE& q) 
{
    if (q.pHead == nullptr) 
    {
        cout << "Queue is empty!";
        return Document(); // Return an empty Document if the queue is empty
    }
    NODE* p = q.pHead;
    Document info = p->info;
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
    ifstream inFile(f); // Mở file để đọc
    if (!inFile) 
    {
        cout << "Cannot open file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) 
    { // Đọc từng dòng trong file
        stringstream ss(line);
        Document doc;

        // Đọc dữ liệu từ dòng, giả định các trường cách nhau bởi dấu phẩy
        getline(ss, doc.date, ',');
        string quantity;
        getline(ss, quantity, ',');
        doc.quantity = stoi(quantity);
        getline(ss, doc.currency, ',');
        string exchangeRate;
        getline(ss, exchangeRate, ',');
        doc.exchangeRate = stod(exchangeRate);
        getline(ss, doc.type, ',');
        string amountVND;
        getline(ss, amountVND);
        doc.amountVND = stod(amountVND);

        EnQueue(q, doc); // Thêm chứng từ vào hàng đợi
    }

    inFile.close(); // Đóng file
    cout << "Data loaded into the queue successfully." << endl;
}

void XuatQueue(QUEUE q) 
{
    NODE* p = q.pHead;
    while (p != nullptr) 
    {
        cout << p->info.date << " " << p->info.quantity << " " << p->info.currency << " "
            << p->info.exchangeRate << " " << p->info.type << " " << p->info.amountVND << endl;
        p = p->pNext;
    }
    cout << endl;
}
