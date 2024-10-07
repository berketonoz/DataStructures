template <typename T>
struct Node
{
    T data;
    Node *right;
    Node *left;
    Node *parent;

    Node(T data, Node *parent = nullptr) : right(nullptr), left(nullptr), data(data), parent(parent) {}
};

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    void destroyTree(Node<T> *node);
    void inorder(Node<T> *node);
    void insertPreOrder(Node<T> *node);

public:
    BinaryTree(/* args */);
    ~BinaryTree();

    void insert(T value);
    Node<T> *search(T value);
    void deleteNode(T value);
    void inorder();
};

template <typename T>
BinaryTree<T>::BinaryTree(/* args */)
{
    this->root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    this->destroyTree(this->root);
}

template <typename T>
inline void BinaryTree<T>::destroyTree(Node<T> *node)
{
    if (node)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

template <typename T>
void BinaryTree<T>::inorder()
{
    std::cout << "Inorder: ";
    this->inorder(this->root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::inorder(Node<T> *node)
{
    if (node)
    {
        this->inorder(node->left);
        std::cout << node->data << " ";
        this->inorder(node->right);
    }
}

template <typename T>
void BinaryTree<T>::insert(T value)
{
    if (this->root == nullptr)
        this->root = new Node<T>(value);
    else
    {
        Node<T> *temp = this->root;
        while (temp != nullptr)
        {
            if (temp->data >= value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = new Node<T>(value, temp);
                    temp = temp->left; // to force temp nullptr after creation
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = new Node<T>(value, temp);
                    temp = temp->right; // to force temp nullptr after creation
                }
                temp = temp->right;
            }
        }
    }
}

template <typename T>
void BinaryTree<T>::insertPreOrder(Node<T> *node)
{
    if (node)
    {
        this->insert(node->data);
        this->insertPreOrder(node->left);
        this->insertPreOrder(node->right);
    }
}

template <typename T>
Node<T> *BinaryTree<T>::search(T value)
{
    Node<T> *temp = this->root;
    bool found = false;
    bool traversed = false;
    while (!found && !traversed)
    {
        if (temp->data > value)
            if (temp->left == nullptr)
                traversed = true;
            else
                temp = temp->left;
        else if (temp->data < value)
            if (temp->right == nullptr)
                traversed = true;
            else
                temp = temp->right;
        else
            found = true;
    }
    return found ? temp : nullptr;
}

template <typename T>
void BinaryTree<T>::deleteNode(T value)
{
    if (!this->root)
        return;
    else if (this->root->data == value)
    {
        Node<T> *current = this->root;
        if (this->root->right != nullptr)
        {
            this->root = root->right;
            this->insertPreOrder(current->left);
        }
        else if (this->root->left != nullptr)
        {
            this->root = root->left;
            this->insertPreOrder(current->right);
        }
        std::cout << current->data << " deleted(Root)" << std::endl;
        delete current;
    }
    else
    {
        Node<T> *current = this->search(value);
        if (current != nullptr)
        {
            Node<T> *parent = current->parent;
            if (current->data > parent->data) // Right child
            {
                parent->right = nullptr;
            }
            else // Left child
            {
                parent->left = nullptr;
            }
            this->insertPreOrder(current->right);
            this->insertPreOrder(current->left);
            std::cout << current->data << " deleted" << std::endl;
            delete current;
        }
        else
        {
            std::cout << value << " Not Found" << std::endl;
        }
    }
}
