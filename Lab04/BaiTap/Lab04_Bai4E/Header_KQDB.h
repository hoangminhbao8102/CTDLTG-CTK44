struct KetQuaXepHang
{
	char TenDoi[15];
	int SoTran; 
	int SoTranThang;
	int SoTranHoa;
	int SoTranThua;
	int SoBanThang; 
	int SoBanThua;
	int HieuSo;
	int Diem;
	int XepHang;
};

typedef KetQuaXepHang DataType_XH;

struct TagNODE_XH
{
	DataType_XH KQXH;
	TagNODE_XH* pNext;
};

typedef TagNODE_XH NODE_XH;

struct LIST_KQXH
{
	NODE_XH* pHead;
	NODE_XH* pTail;
};

NODE_XH* GetNODE_XH(DataType_XH x);
void CreatList_KQXH(LIST_KQXH& h);
void InsertTail_XH(LIST_KQXH& h, DataType_XH x);
void KhoiTao_List_KQXH(LIST_KQXH& h);
NODE_TD* Tro_Sau_Cuoi_Vong(LIST_KQTD l, int vong);
void TaoList_KQDB_Vong(LIST_KQXH& h, LIST_KQTD l, int vong);

NODE_XH* GetNODE_XH(DataType_XH x)
{
	NODE_XH* p;
	p = new NODE_XH;
	if (p != NULL)
	{
		p->KQXH = x;
		p->pNext = NULL;
	}
	return p;
}

void CreatList_KQXH(LIST_KQXH& h)
{
	h.pHead = h.pTail = NULL;
}

void InsertTail_XH(LIST_KQXH& h, DataType_XH x)
{
	NODE_XH* new_ele = GetNODE_XH(x);
	if (new_ele == NULL)
	{
		cout << "\nKhong du bo nho";
		system("PAUSE");
		return;
	}
	if (h.pHead == NULL)
	{
		h.pHead = new_ele; h.pTail = h.pHead;
	}
	else
	{
		h.pTail->pNext = new_ele;
		h.pTail = new_ele;
	}
}

void KhoiTao_List_KQXH(LIST_KQXH& h)
{
	ifstream in("Khoitao_KQDB.txt");
	if (!in)
	{
		cout << "\nLoi mo file !\n";
		system("PAUSE");
		return;
	}
	CreatList_KQXH(h);
	DataType_XH x;
	while (!in.eof())
	{
		in >> x.TenDoi;
		in >> x.SoTran;
		in >> x.SoTranThang;
		in >> x.SoTranHoa;
		in >> x.SoTranThua;
		in >> x.SoBanThang;
		in >> x.SoBanThua;
		in >> x.HieuSo;
		in >> x.Diem;
		in >> x.XepHang;
		InsertTail_XH(h, x);
	}
	in.close();
}

NODE_TD* Tro_Sau_Cuoi_Vong(LIST_KQTD l, int vong)
{
	NODE_TD* p;
	int sTran = 10 * vong;
	int i = 0;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		i++;
		if (i > sTran)
			break;
	}
	return p;
}

void TaoList_KQDB_Vong(LIST_KQXH& h, LIST_KQTD l, int vong)
{
	NODE_TD* p;
	NODE_XH* q;
	DataType_XH x;
	NODE_TD * r = Tro_Sau_Cuoi_Vong(l, vong);
	KhoiTao_List_KQXH(h);
	for (q = h.pHead; q != NULL; q = q->pNext)
	{
		x = q->KQXH;
		for (p = l.pHead; p != r; p = p->pNext)
		{
			if (_strcmpi(x.TenDoi, p->KQTD.ChuNha) == 0)
			{
				x.SoBanThang += p->KQTD.BanThangChu;
				x.SoBanThua += p->KQTD.BanThangKhach;
				if (p->KQTD.BanThangChu > p->KQTD.BanThangKhach)
				{
					x.SoTranThang++;
					x.Diem += 3;
				}
				else
					if (p->KQTD.BanThangChu < p->KQTD.BanThangKhach)
						x.SoTranThua++;
					else
					{
						x.SoTranHoa++;
						x.Diem += 1;
					}
			}
			else
				if (_strcmpi(x.TenDoi, p->KQTD.DoiKhach) == 0)
				{
					x.SoBanThang += p->KQTD.BanThangKhach;
					x.SoBanThua += p->KQTD.BanThangChu;
					if (p->KQTD.BanThangChu < p->KQTD.BanThangKhach)
					{
						x.SoTranThang++;
						x.Diem += 3;
					}
					else
						if (p->KQTD.BanThangChu > p->KQTD.BanThangKhach)
							x.SoTranThua++;
						else
						{
							x.SoTranHoa++;
							x.Diem += 1;
						}
				}
			x.HieuSo = x.SoBanThang - x.SoBanThua;
			x.SoTran = x.SoTranThang + x.SoTranHoa + x.SoTranThua;
		}
		q->KQXH = x;
	}
}