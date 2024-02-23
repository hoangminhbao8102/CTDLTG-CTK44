int* ChiaThuongRecursive(int m, int n);
int* ChiaThuong(int m, int n);

int* ChiaThuongRecursive(int m, int n) 
{
    if (m == 0 || n == 0) 
    {
        int* result = new int[n];
        for (int i = 0; i < n; ++i) 
        {
            result[i] = 0;
        }
        return result;
    }

    if (n == 1) 
    {
        int* result = new int[1];
        result[0] = m;
        return result;
    }

    int soPhanThuong = m / n;

    int* phanThuongChoHocSinhDauTien = new int[n];
    for (int i = 0; i < n; ++i) 
    {
        phanThuongChoHocSinhDauTien[i] = soPhanThuong;
    }

    int soPhanThuongConLai = m - soPhanThuong * n;

    for (int i = 0; i < soPhanThuongConLai; ++i) {
        phanThuongChoHocSinhDauTien[i] += 1;
    }

    return phanThuongChoHocSinhDauTien;
}

int* ChiaThuong(int m, int n) 
{
    if (m <= 0 || n <= 0) 
    {
        cerr << "Loi: Phai co it nhat 1 phan thuong va 1 hoc sinh.\n";
        return nullptr;
    }

    return ChiaThuongRecursive(m, n);
}