template <typename T>
struct Node
{
    T data;
    Node *right;
    Node *left;

    Node(T data) : right(nullptr), left(nullptr), data(data) {}
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
    this->destroyTree(this - root);
}

template <typename T>
void BinaryTree<T>::insert(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (this->root == nullptr)
        this->root = newNode;
    }
    else
    {
        Node<T> *temp = this->root;
        while (temp != nullptr)
        {
            if (temp->data >= value)
            {

                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    temp = temp->left; // to force temp nullptr after creation
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
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
    else
    {
        if (this->search(value) != nullptr)
        {
            if (this->root->data == value)
            {
            }
            else
            {

                Node<T> *temp = this->root;
                bool found = false;

                while (!found)
                {
                    if (temp->data > value)
                    {
                        temp = temp->left;
                    }
                    else if (temp->data < value)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        found = true;
                    }
                }

                Node<T> *tt = temp;
                this->destroyTree(temp);
                this->insertPreOrder(tt->left);
                this->insertPreOrder(tt->right);
            }
        }
    }
}

template <typename T>
inline void BinaryTree<T>::inorder()
{
    this->inorder(this->root);
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
void BinaryTree<T>::inorder(Node<T> *node)
{
    if (node)
    {
        this->inorder(node->left);
        std::cout << node->data << " " << std::endl;
        this->inorder(node->right);
    }
}
