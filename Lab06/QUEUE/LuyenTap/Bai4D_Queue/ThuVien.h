struct Nhom
{
	char ns[5];
	int stt;
};
typedef Nhom Data;//Kieu thanh phan du lieu cua nut
struct TagNode //Kieu Nut
{
	Data info;
	TagNode* pNext;
};
typedef TagNode NODE;
//Kieu DSLK don
struct QUEUE
{
	NODE* pHead;
	NODE* pTail;
};
//=======================================================
NODE* GetNode(Data x);
void CreatQueue(QUEUE& q);
void EnQueue(QUEUE& q, Data x);
Data DeQueue(QUEUE& q);
void TapTin_Queue(char* f, QUEUE& q);
int SoNhom(QUEUE q);
void XuatQueue(QUEUE q);
void Sap_Tang_TTTruc(QUEUE& q);//sap tang q theo thu tu truc
void XuatLichTruc(QUEUE& q, int m); //Xep va xuat Lich truc xoay vong n nhom trong m ngay
void NhapThongTinNhomTuBanPhim(QUEUE& q);
void ChonPhuongThucNhap(QUEUE& q);
//========================================
NODE* GetNode(Data x)
{
	NODE* p = new NODE; // Tạo một node mới
	if (p == NULL)
	{
		return NULL; // Không đủ bộ nhớ
	}
	p->info = x; // Gán giá trị
	p->pNext = NULL; // Thiết lập liên kết
	return p;
}
void CreatQueue(QUEUE& q)
{
	q.pHead = q.pTail = NULL; // Khởi tạo head và tail cùng trỏ đến NULL
}
void EnQueue(QUEUE& q, Data x)
{
	NODE* p = GetNode(x); // Lấy node mới từ dữ liệu x
	if (p == NULL) return; // Nếu node không hợp lệ, thoát

	if (q.pHead == NULL)
	{
		q.pHead = q.pTail = p; // Nếu hàng đợi rỗng, node mới là head và tail
	}
	else
	{
		q.pTail->pNext = p; // Liên kết node cuối hiện tại với node mới
		q.pTail = p; // Cập nhật tail
	}
}
Data DeQueue(QUEUE& q)
{
	if (q.pHead == NULL) // Kiểm tra hàng đợi rỗng
	{
		// Nên xử lý trường hợp này tốt hơn, ví dụ như thông báo lỗi hoặc trả về giá trị mặc định
		Data empty;
		return empty; // Trả về giá trị rỗng nếu không có gì để dequeue
	}

	NODE* p = q.pHead; // Node để dequeue
	Data x = p->info; // Lưu giữ dữ liệu
	q.pHead = q.pHead->pNext; // Di chuyển head
	if (q.pHead == NULL)
		q.pTail = NULL; // Nếu hàng đợi trống, cập nhật tail
	delete p; // Xóa node
	return x; // Trả về dữ liệu
}
void TapTin_Queue(char* f, QUEUE& q)
{
	ifstream file(f);  // Mở file để đọc
	if (!file)
	{
		cout << "Khong the mo file!" << endl;
		return;  // Thoát nếu file không mở được
	}

	Data x;
	while (file >> x.ns >> x.stt)  // Đọc chuỗi và số nguyên từ file
	{
		EnQueue(q, x);  // Thêm dữ liệu vào hàng đợi
	}

	file.close();  // Đóng file
}
int SoNhom(QUEUE q)
{
	int count = 0;
	NODE* p = q.pHead;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count; // Trả về số lượng nhóm
}
void XuatQueue(QUEUE q)
{
	NODE* p = q.pHead;
	while (p != NULL)
	{
		cout << p->info.ns << " " << p->info.stt << endl; // In thông tin của mỗi nhóm
		p = p->pNext;
	}
}
void Sap_Tang_TTTruc(QUEUE& q)
{
	for (NODE* p = q.pHead; p != NULL; p = p->pNext)
	{
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->info.stt > q->info.stt)
			{
				Data temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
		}
	}
}
//sn nhom truc xoay vong trong m ngay
void XuatLichTruc(QUEUE& q, int m)
{
	int i, sn;
	Data x;
	int vong = 1;
	sn = SoNhom(q); // so nhom : so nut trong q
	Sap_Tang_TTTruc(q);//dap tang q theo thu tu truc
	cout << "\nVong " << vong << " :\n";
	for (i = 1; i <= m; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(13) << "\nTruc ngay thu " << setw(4) << i << setw(10) << " la nhom : ";
		x = DeQueue(q);
		cout << setw(5);
		cout << x.ns;
		EnQueue(q, x);
		if (i % sn == 0)
		{
			cout << "\n================================";
			vong++;
			cout << "\nVong " << vong << " :\n";
		}
	}
	cout << endl;
}
void NhapThongTinNhomTuBanPhim(QUEUE& q) 
{
	int n;
	Data x;
	cout << "Nhap so luong nhom: ";
	cin >> n;
	cout << "Nhap ma nhom va so thu tu truc cho moi nhom:\n";
	for (int i = 0; i < n; i++) 
	{
		cout << "Nhom " << i + 1 << ":\n";
		cout << "Ma nhom (max 4 ky tu): ";
		cin >> x.ns;
		cout << "So thu tu truc: ";
		cin >> x.stt;
		EnQueue(q, x);
	}
}

void ChonPhuongThucNhap(QUEUE& q) 
{
	int choice;
	cout << "Chon phuong thuc nhap thong tin:\n";
	cout << "1. Nhap tu ban phim\n";
	cout << "2. Nhap tu tap tin\n";
	cin >> choice;

	if (choice == 1) 
	{
		NhapThongTinNhomTuBanPhim(q);
	}
	else if (choice == 2) 
	{
		char filename[100];
		cout << "Nhap ten tap tin: ";
		cin >> filename;
		TapTin_Queue(filename, q);
	}
	else 
	{
		cout << "Lua chon khong hop le, vui long nhap lai.\n";
		ChonPhuongThucNhap(q);
	}
}