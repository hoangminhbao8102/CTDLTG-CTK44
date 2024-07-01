#define MAX 100
#define NULLDATA ' '
typedef char Data;//Kieu thanh phan du lieu cua nut
struct TagNode //Kieu Nut
{
	Data info;
	TagNode* pNext;
};
typedef TagNode NODE;
//Kieu DSLK don
struct QUEUE
{
	NODE* pHead; //Chua dc nut dau
	NODE* pTail; //Chua dc nut cuoi
};
//======================================
NODE* GetNode(Data x);
void CreatQueue(QUEUE& q);
void EnQueue(QUEUE& q, Data x);
Data DeQueue(QUEUE& q);
void File_String(char* f, char a[MAX]);
void XuatQueue(QUEUE q);
void XuLy_ThaoTac(char a[MAX]);

NODE* GetNode(Data x)
{
	NODE* p = new NODE; // Cấp phát bộ nhớ cho NODE mới
	if (p == NULL) 
	{
		cout << "Khong du bo nho de cap phat nut moi!";
		return NULL;
	}
	p->info = x; // Gán giá trị x cho info của NODE
	p->pNext = NULL; // Khởi tạo con trỏ pNext là NULL
	return p;
}
void CreatQueue(QUEUE& q)
{
	q.pHead = NULL; // Khởi tạo pHead là NULL
	q.pTail = NULL; // Khởi tạo pTail là NULL
}
void EnQueue(QUEUE& q, Data x)
{
	NODE* p = GetNode(x); // Lấy NODE mới từ GetNode
	if (p == NULL) return;
	if (q.pHead == NULL) 
	{ // Nếu Queue rỗng
		q.pHead = p; // NODE đầu tiên là p
		q.pTail = p; // NODE cuối cùng là p
	}
	else 
	{
		q.pTail->pNext = p; // Liên kết NODE cuối hiện tại với p
		q.pTail = p; // Cập nhật NODE cuối là p
	}
}
Data DeQueue(QUEUE& q)
{
	NODE* p;
	Data x;
	if (q.pHead == NULL)
		return NULLDATA;
	p = q.pHead;
	x = p->info;
	q.pHead = q.pHead->pNext;
	delete p;
	if (q.pHead == NULL)
		q.pTail = NULL;
	return x;
}
void File_String(char* f, char a[MAX]) //Tap tin -> Chuoi
{
	ifstream fin(f); // Mở file để đọc
	if (!fin) 
	{
		cout << "Khong the mo file!" << endl;
		return;
	}
	fin.getline(a, MAX); // Đọc dòng từ file vào mảng a
	fin.close(); // Đóng file
}
void XuatQueue(QUEUE q)
{
	NODE* p = q.pHead; // Bắt đầu từ NODE đầu tiên
	while (p != NULL) 
	{
		cout << p->info << " "; // In giá trị của NODE
		p = p->pNext; // Di chuyển đến NODE tiếp theo
	}
	cout << endl;
}
void XuLy_ThaoTac(char a[MAX])
{
	QUEUE q;
	CreatQueue(q);
	char c;
	int i;
	for (i = 0; a[i] != NULL; i++)
	{
		c = a[i];
		if ('A' <= c && c <= 'Z')
		{
			EnQueue(q, c);
			XuatQueue(q);
		}
		else
			if (c == '*')
			{
				if (DeQueue(q));
				XuatQueue(q);
			}
	}
	cout << "\nKet qua sau khi thuc hien chuoi thao tac \"" << a << "\":\n";
	XuatQueue(q);
	cout << endl;
	system("PAUSE");
}