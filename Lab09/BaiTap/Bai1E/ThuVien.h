struct NODE 
{
    BSTree info;
    NODE* pNext;
};

struct List 
{ // Queue, Stack
    NODE* pHead;
    NODE* pTail;
};
//==================================
//Khai bao nguyen mau cac ham
//Cac ham he thong
NODE* GetNode(BSTree info);
void CreateList(List& l);
int IsEmpty(List l);
void InsertTail(List& l, BSTree info);
BSTree RemoveHead(List& l);
void InsertHead(List& s, BSTree info);
int CountNodes(BSTree root);
int Height(BSTree root);
int CountLevelNodes(BSTree root, int level);
int CountLeafNodes(BSTree root);
int CountFullNodes(BSTree root);
int DeleteNode(BSTree& root, KeyType key);
void BFS(BSTree root);
void DFS(BSTree root);
// Tạo một node mới
NODE* GetNode(BSTree info) 
{
    NODE* p = new NODE;
    if (p == NULL) 
    {
        return NULL;
    }
    p->info = info;
    p->pNext = NULL;
    return p;
}

// Khởi tạo danh sách rỗng
void CreateList(List& l) 
{
    l.pHead = l.pTail = NULL;
}

// Kiểm tra danh sách có rỗng không
int IsEmpty(List l) 
{
    return (l.pHead == NULL);
}

// Thêm vào cuối danh sách (hàng đợi)
void InsertTail(List& l, BSTree info) 
{
    NODE* p = GetNode(info);
    if (p == NULL) return;
    if (IsEmpty(l)) 
    {
        l.pHead = l.pTail = p;
    }
    else 
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Xóa phần tử đầu danh sách (hàng đợi)
BSTree RemoveHead(List& l) 
{
    if (IsEmpty(l)) return NULL;
    NODE* p = l.pHead;
    BSTree info = p->info;
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL) 
    {
        l.pTail = NULL;
    }
    delete p;
    return info;
}

// Thêm vào đầu danh sách (ngăn xếp)
void InsertHead(List& s, BSTree info) 
{
    NODE* p = GetNode(info);
    if (p == NULL) return;
    if (IsEmpty(s)) {
        s.pHead = s.pTail = p;
    }
    else {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}
// 3. Đếm số nút của cây
int CountNodes(BSTree root) 
{
    if (root == NULL)
        return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}
// 4. Xác định chiều cao của cây
int Height(BSTree root) 
{
    if (root == NULL)
        return -1;  // Chiều cao của cây rỗng là -1
    return 1 + max(Height(root->left), Height(root->right));
}
// 5. Đếm số nút của cây ở mức K
int CountLevelNodes(BSTree root, int level) 
{
    if (root == NULL)
        return 0;
    if (level == 0)
        return 1;  // Đỉnh hiện tại là nút cần đếm
    return CountLevelNodes(root->left, level - 1) + CountLevelNodes(root->right, level - 1);
}
// 6. Đếm số nút lá của cây
int CountLeafNodes(BSTree root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return CountLeafNodes(root->left) + CountLeafNodes(root->right);
}
// 7. Đếm số nút có đúng hai nút con khác rỗng
int CountFullNodes(BSTree root) 
{
    if (root == NULL)
        return 0;
    int count = 0;
    if (root->left != NULL && root->right != NULL)
        count = 1;
    return count + CountFullNodes(root->left) + CountFullNodes(root->right);
}
// 8. Hủy nút có khóa cho trước
int DeleteNode(BSTree& root, KeyType key) 
{
    if (root == NULL)
        return 0;
    if (key < root->key)
        return DeleteNode(root->left, key);
    else if (key > root->key)
        return DeleteNode(root->right, key);

    // Node with one child or no child
    if (root->left == NULL || root->right == NULL) 
    {
        BSTree temp = root->left ? root->left : root->right;
        if (temp == NULL) 
        {  // No child case
            temp = root;
            root = NULL;
        }
        else  // One child case
            *root = *temp;
        delete temp;
    }
    else 
    {
        // Node with two children: Get the inorder successor
        BSTree temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        root->key = temp->key;
        return DeleteNode(root->right, temp->key);
    }
    return 1;
}
// 9. Duyệt cây theo chiều rộng(BFS)
void BFS(BSTree root) 
{
    if (root == NULL) return;
    List queue;
    CreateList(queue);
    InsertTail(queue, root);

    while (!IsEmpty(queue)) 
    {
        BSTree current = RemoveHead(queue);
        cout << current->key << " ";

        if (current->left != NULL)
            InsertTail(queue, current->left);
        if (current->right != NULL)
            InsertTail(queue, current->right);
    }
}
// 10. Duyệt cây theo chiều sâu(DFS)
void DFS(BSTree root) 
{
    if (root == NULL) return;
    List stack;
    CreateList(stack);
    InsertHead(stack, root);

    while (!IsEmpty(stack)) 
    {
        BSTree current = RemoveHead(stack);
        cout << current->key << " ";

        if (current->right != NULL)
            InsertHead(stack, current->right);
        if (current->left != NULL)
            InsertHead(stack, current->left);
    }
}
