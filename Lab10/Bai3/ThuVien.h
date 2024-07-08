struct WordMeaning 
{
    string key;     // từ gốc tiếng Anh
    string meaning; // nghĩa tiếng Việt
};

struct AVLTN 
{
    WordMeaning data;
    int balfactor; // Chỉ số cân bằng
    AVLTN* lChild; // Con trái
    AVLTN* rChild; // Con phải
};

typedef AVLTN AVLTreeNode;
typedef AVLTreeNode* AVLTree;

AVLTreeNode* createNode(string key, string meaning) 
{
    AVLTreeNode* node = new AVLTreeNode;
    node->data.key = key;
    node->data.meaning = meaning;
    node->balfactor = 0;
    node->lChild = nullptr;
    node->rChild = nullptr;
    return node;
}

// Hàm này là ví dụ về hàm cân bằng lại cây khi cây lệch về bên trái
void balanceLeft(AVLTreeNode*& root) {
    AVLTreeNode* tmp = root->lChild;
    if (tmp->balfactor == -1) { // Left-Left case
        root->lChild = tmp->rChild;
        tmp->rChild = root;
        root->balfactor = 0;
        root = tmp;
    }
    else { // Left-Right case
        AVLTreeNode* tmp2 = tmp->rChild;
        tmp->rChild = tmp2->lChild;
        tmp2->lChild = tmp;
        root->lChild = tmp2->rChild;
        tmp2->rChild = root;
        root->balfactor = 0;
        tmp->balfactor = 0;
        root = tmp2;
    }
    root->balfactor = 0;
}

// Các hàm cân bằng cho Right-Right và Right-Left case tương tự
void rotateLeft(AVLTreeNode*& root) 
{
    AVLTreeNode* tmp = root->rChild;
    root->rChild = tmp->lChild;
    tmp->lChild = root;
    root = tmp;
    root->lChild->balfactor = 0;
    root->balfactor = 0;
}

void rotateRightLeft(AVLTreeNode*& root) 
{
    AVLTreeNode* tmp = root->rChild;
    AVLTreeNode* tmp2 = tmp->lChild;

    // Xoay phải ở nút con phải
    tmp->lChild = tmp2->rChild;
    tmp2->rChild = tmp;

    // Xoay trái ở nút gốc
    root->rChild = tmp2->lChild;
    tmp2->lChild = root;

    // Cập nhật balfactor
    root->balfactor = (tmp2->balfactor == 1) ? -1 : 0;
    tmp->balfactor = (tmp2->balfactor == -1) ? 1 : 0;
    tmp2->balfactor = 0;

    root = tmp2;
}

void rotateRight(AVLTreeNode*& root) 
{
    AVLTreeNode* tmp = root->lChild;
    root->lChild = tmp->rChild;
    tmp->rChild = root;
    root = tmp;
    root->rChild->balfactor = 0;
    root->balfactor = 0;
}

void rotateLeftRight(AVLTreeNode*& root) 
{
    AVLTreeNode* tmp = root->lChild;
    AVLTreeNode* tmp2 = tmp->rChild;

    // Xoay trái tại nút con trái
    tmp->rChild = tmp2->lChild;
    tmp2->lChild = tmp;

    // Xoay phải tại nút gốc
    root->lChild = tmp2->rChild;
    tmp2->rChild = root;

    // Cập nhật balfactor
    root->balfactor = (tmp2->balfactor == -1) ? 1 : 0;
    tmp->balfactor = (tmp2->balfactor == 1) ? -1 : 0;
    tmp2->balfactor = 0;

    root = tmp2;
}

void balanceTree(AVLTreeNode*& root) 
{
    if (root->balfactor == 2) 
    {
        if (root->rChild->balfactor >= 0) 
        {
            rotateLeft(root);
        }
        else 
        {
            rotateRightLeft(root);
        }
    }
    else if (root->balfactor == -2) 
    {
        if (root->lChild->balfactor <= 0) 
        {
            rotateRight(root);
        }
        else 
        {
            rotateLeftRight(root);
        }
    }
}

// Hàm thêm vào cây AVL
void insert(AVLTree& root, string key, string meaning) 
{
    if (root == nullptr) 
    {
        root = createNode(key, meaning);
    }
    else if (key < root->data.key) 
    {
        insert(root->lChild, key, meaning);
        if (height(root->lChild) - height(root->rChild) == 2) 
        {
            if (key < root->lChild->data.key) 
            {
                rotateRight(root);
            }
            else 
            {
                rotateLeftRight(root);
            }
        }
    }
    else if (key > root->data.key) 
    {
        insert(root->rChild, key, meaning);
        if (height(root->rChild) - height(root->lChild) == 2) 
        {
            if (key > root->rChild->data.key) 
            {
                rotateLeft(root);
            }
            else 
            {
                rotateRightLeft(root);
            }
        }
    }
    root->balfactor = 1 + max(height(root->lChild), height(root->rChild));
}

int height(AVLTreeNode* node) 
{
    if (node == nullptr) return -1;
    return 1 + max(height(node->lChild), height(node->rChild));
}

// Hàm tìm kiếm từ trong cây AVL
string find(AVLTree root, string key) 
{
    if (root == nullptr) 
    {
        // Nếu cây rỗng hoặc không tìm thấy từ
        return "Not found";
    }
    if (key < root->data.key) 
    {
        // Tìm trong cây con trái
        return find(root->lChild, key);
    }
    else if (key > root->data.key) 
    {
        // Tìm trong cây con phải
        return find(root->rChild, key);
    }
    else
    {
        // Nếu tìm thấy khóa
        return root->data.meaning;
    }
}
