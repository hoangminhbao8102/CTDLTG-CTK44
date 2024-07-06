typedef string KeyType; // từ gốc tiếng Anh

struct BSNode 
{
    KeyType key; // Từ gốc tiếng Anh
    string meanings; // Chuỗi chứa tất cả các nghĩa của từ, ngăn cách bởi dấu phẩy
    BSNode* left; // Con trái
    BSNode* right; // Con phải
};

typedef BSNode* BSTree;

void CreateBST(BSTree& root) 
{
    root = NULL;
}

BSNode* CreateNode(KeyType key, const string& meanings) 
{
    BSNode* p = new BSNode;
    if (p != NULL) {
        p->key = key;
        p->meanings = meanings;
        p->left = NULL;
        p->right = NULL;
    }
    return p;
}

int InsertNode(BSTree& root, KeyType key, const string& meanings) 
{
    if (root != NULL) 
    {
        if (root->key == key) 
        {
            // Nếu từ này đã tồn tại, cập nhật thêm nghĩa mới
            root->meanings += ", " + meanings;
            return 0;
        }
        if (root->key > key)
            return InsertNode(root->left, key, meanings);
        else
            return InsertNode(root->right, key, meanings);
    }
    root = CreateNode(key, meanings);
    return root ? 1 : -1;
}

void InOrder(BSTree root) 
{
    if (root != NULL) 
    {
        InOrder(root->left);
        cout << root->key << ": " << root->meanings << endl;
        InOrder(root->right);
    }
}
