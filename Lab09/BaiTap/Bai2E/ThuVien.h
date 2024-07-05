// Khai báo nguyên mẫu
int DemSoNut(BSTree root);
int ThayDoiDiaChi(BSTree root, const char* maHV, const char* diaChiMoi);
BSNode* TimNodeTheMang(BSTree& p);
int HuyHocVien(BSTree& root, const char* maHV);
void HuyHocVienDiemThap(BSTree& root);
//=====================================
// Đếm số nút
int DemSoNut(BSTree root)
{
    if (root == NULL)
        return 0;
    return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}
// Thay đổi địa chỉ của học viên khi biết mã học viên
int ThayDoiDiaChi(BSTree root, const char* maHV, const char* diaChiMoi)
{
    if (root == NULL)
        return 0; // Không tìm thấy mã học viên

    if (strcmp(root->info.MaHV, maHV) == 0)
    {
        strcpy_s(root->info.Diachi, sizeof(root->info.Diachi), diaChiMoi); // Thay đổi địa chỉ
        return 1; // Thành công
    }
    if (strcmp(root->info.MaHV, maHV) > 0)
        return ThayDoiDiaChi(root->left, maHV, diaChiMoi);
    else
        return ThayDoiDiaChi(root->right, maHV, diaChiMoi);
}
// Hàm tìm node thế mạng
BSNode* TimNodeTheMang(BSTree& p)
{
    if (p->right != NULL)
        return TimNodeTheMang(p->right);
    else
    {
        BSNode* temp = p;
        p = p->left;
        return temp;
    }
}
// Hủy học viên có mã học viên cho trước ra khỏi bảng điểm
int HuyHocVien(BSTree& root, const char* maHV)
{
    if (root == NULL)
        return 0; // Không tìm thấy mã học viên

    if (strcmp(root->info.MaHV, maHV) > 0)
        return HuyHocVien(root->left, maHV);
    else if (strcmp(root->info.MaHV, maHV) < 0)
        return HuyHocVien(root->right, maHV);
    else
    {
        BSNode* temp = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        else
        {
            BSNode* nodeTheMang = TimNodeTheMang(root->left);
            root->info = nodeTheMang->info;
            temp = nodeTheMang;
        }
        delete temp;
        return 1; // Thành công
    }
}
// Hủy các học viên có điểm < 5
void HuyHocVienDiemThap(BSTree& root)
{
    if (root == NULL)
        return;

    HuyHocVienDiemThap(root->left);
    HuyHocVienDiemThap(root->right);

    if (root->info.Diem < 5)
    {
        HuyHocVien(root, root->info.MaHV);
    }
}
