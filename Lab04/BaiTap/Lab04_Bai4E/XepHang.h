void HoanVi(DataType_XH& x, DataType_XH& y);
void SapGiamTheoDiem_HieuSo_SoBT_DenVong(LIST_KQXH& h, int vong);
void XepHang_DenVong(LIST_KQXH& h, int vong);
void XuatTieuDe_KQ();
void XuatKQ_1D(DataType_XH x);
void Xuat_KQXH(LIST_KQXH h);

void HoanVi(DataType_XH& x, DataType_XH& y)
{
	DataType_XH t = x;
	x = y;
	y = t;
}

void SapGiamTheoDiem_HieuSo_SoBT_DenVong(LIST_KQXH& h, int vong)
{
	NODE_XH* p, * q;

	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->KQXH.Diem < q->KQXH.Diem)
				HoanVi(p->KQXH, q->KQXH);
	
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->KQXH.Diem == q->KQXH.Diem)
				if (p->KQXH.HieuSo < q->KQXH.HieuSo)
					HoanVi(p->KQXH, q->KQXH);
	
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->KQXH.Diem == q->KQXH.Diem)
				if (p->KQXH.HieuSo == q->KQXH.HieuSo)
					if (p->KQXH.SoBanThang < q->KQXH.SoBanThang)
						HoanVi(p->KQXH, q->KQXH);
	
	for (p = h.pHead; p != h.pTail; p = p->pNext)
		for (q = p->pNext; q != NULL; q = q->pNext)
			if (p->KQXH.Diem == q->KQXH.Diem)
				if (p->KQXH.HieuSo == q->KQXH.HieuSo)
					if (p->KQXH.SoBanThang == q->KQXH.SoBanThang)
						if (_strcmpi(p->KQXH.TenDoi, q->KQXH.TenDoi) > 0)
							HoanVi(p->KQXH, q->KQXH);
}

void XepHang_DenVong(LIST_KQXH& h, int vong)
{
	int vt = 1,
		soVT;
	NODE_XH* p, * q;
	SapGiamTheoDiem_HieuSo_SoBT_DenVong(h, vong);
	
	p = h.pHead;
	p->KQXH.XepHang = 1;
	soVT = 1;
	for (q = p->pNext; q != NULL; q = q->pNext)
	{
		if (q->KQXH.Diem == p->KQXH.Diem &&
			q->KQXH.HieuSo == p->KQXH.HieuSo &&
			q->KQXH.SoBanThang == p->KQXH.SoBanThang)
		{
			q->KQXH.XepHang = vt;
			soVT++;
		}
		else
		{
			vt += soVT;
			q->KQXH.XepHang = vt;
			soVT = 1;
		}
		p = q;
	}
}

void XuatTieuDe_KQ()
{
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << NGANGDOI;
	cout << ':';
	cout << endl;
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(15) << "Ten doi"
		<< ": "
		<< setw(4) << "ST"
		<< ": "
		<< setw(4) << "T"
		<< ": "
		<< setw(4) << "H"
		<< ": "
		<< setw(4) << "B"
		<< ": "
		<< setw(4) << "BT"
		<< ": "
		<< setw(4) << "BB"
		<< ": "
		<< setw(4) << "HS"
		<< ": "
		<< setw(4) << "Diem"
		<< ": "
		<< setw(4) << "XH"
		<< ':';
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << NGANGDOI;
	cout << ':';
}

void XuatKQ_1D(DataType_XH x)
{
	cout << setiosflags(ios::left)
		<< ": "
		<< setw(15) << x.TenDoi
		<< ": "
		<< setw(4) << x.SoTran
		<< ": "
		<< setw(4) << x.SoTranThang
		<< ": "
		<< setw(4) << x.SoTranHoa
		<< ": "
		<< setw(4) << x.SoTranThua
		<< ": "
		<< setw(4) << x.SoBanThang
		<< ": "
		<< setw(4) << x.SoBanThua
		<< ": "
		<< setw(4) << x.HieuSo
		<< ": "
		<< setw(4) << x.Diem
		<< ": "
		<< setw(4) << x.XepHang
		<< ':';
}

void Xuat_KQXH(LIST_KQXH h)
{
	NODE_XH* p;
	XuatTieuDe_KQ();
	for (p = h.pHead; p != h.pTail; p = p->pNext)
	{
		cout << endl;
		XuatKQ_1D(p->KQXH);
		cout << endl;
		cout << ':';
		for (int i = 1; i <= 70; i++)
			cout << NGANGDON;
		cout << ':';
	}
	cout << endl;
	XuatKQ_1D(p->KQXH);
	cout << endl;
	cout << ':';
	for (int i = 1; i <= 70; i++)
		cout << NGANGDOI;
	cout << ':';
}