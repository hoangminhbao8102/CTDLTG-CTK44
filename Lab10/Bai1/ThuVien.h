AVLTreeNode* findNode(AVLTreeNode* root, ElementType key) 
{
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return findNode(root->lChild, key);
    else
        return findNode(root->rChild, key);
}

// LNR (InOrder)
void inOrder(AVLTreeNode* root) 
{
    if (root != nullptr) 
    {
        inOrder(root->lChild);
        cout << root->data << " ";
        inOrder(root->rChild);
    }
}

// LRN (PostOrder)
void postOrder(AVLTreeNode* root) 
{
    if (root != nullptr) 
    {
        postOrder(root->lChild);
        postOrder(root->rChild);
        cout << root->data << " ";
    }
}

AVLTreeNode* leftRightRotate(AVLTreeNode* node) 
{
    node->lChild = leftRotate(node->lChild);
    return rightRotate(node);
}

AVLTreeNode* rightLeftRotate(AVLTreeNode* node) 
{
    node->rChild = rightRotate(node->rChild);
    return leftRotate(node);
}

AVLTreeNode* balanceLeft(AVLTreeNode* node) 
{
    if (node == nullptr)
        return node;

    if (height(node->lChild) - height(node->rChild) > 1) 
    {
        if (height(node->lChild->lChild) >= height(node->lChild->rChild))
            node = rightRotate(node);
        else
            node = leftRightRotate(node);
    }
    return node;
}

AVLTreeNode* balanceRight(AVLTreeNode* node) 
{
    if (node == nullptr)
        return node;

    if (height(node->rChild) - height(node->lChild) > 1) 
    {
        if (height(node->rChild->rChild) >= height(node->rChild->lChild))
            node = leftRotate(node);
        else
            node = rightLeftRotate(node);
    }
    return node;
}

AVLTreeNode* minValueNode(AVLTreeNode* node) 
{
    AVLTreeNode* current = node;
    while (current->lChild != nullptr)
        current = current->lChild;
    return current;
}

AVLTreeNode* deleteNode(AVLTreeNode* root, ElementType key) 
{
    if (root == nullptr) return root;

    if (key < root->data) 
    {
        root->lChild = deleteNode(root->lChild, key);
        root = balanceRight(root);
    }
    else if (key > root->data) 
    {
        root->rChild = deleteNode(root->rChild, key);
        root = balanceLeft(root);
    }
    else 
    {
        if ((root->lChild == nullptr) || (root->rChild == nullptr)) 
        {
            AVLTreeNode* temp = root->lChild ? root->lChild : root->rChild;
            if (temp == nullptr) 
            {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;
            delete temp;
        }
        else 
        {
            AVLTreeNode* temp = minValueNode(root->rChild);
            root->data = temp->data;
            root->rChild = deleteNode(root->rChild, temp->data);
            root = balanceLeft(root);
        }
    }

    if (root == nullptr)
        return root;

    updateBalanceFactor(root);
    return root;
}

AVLTree buildAVLTree(vector<ElementType> data)
{
    AVLTree root = nullptr;
    for (ElementType value : data) 
    {
        root = insert(root, value);
    }
    return root;
}


void printBalanceFactors(AVLTreeNode* root) 
{
    if (root != nullptr) 
    {
        cout << "Data: " << root->data << ", Balance Factor: " << root->balfactor << endl;
        printBalanceFactors(root->lChild);
        printBalanceFactors(root->rChild);
    }
}
