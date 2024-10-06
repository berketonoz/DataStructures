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

public:
    BinaryTree(/* args */);
    ~BinaryTree();

    void insert(T value);
    bool search(T value);
    bool deleteNode(T value);

    void inorder(Node<T> *node);
    Node<T> *getRoot();

};

template <typename T>
BinaryTree<T>::BinaryTree(/* args */)
{
    this->root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
}

template <typename T>
void BinaryTree<T>::insert(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (this->root == nullptr)
    {
        this->root = newNode;
    }
    else
    {
        Node<T> *temp = this->root;
        bool inserted = false;
        while (!inserted)
        {
            if (temp->data < value)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    inserted = true;
                }
                temp = temp->right;
            }
            else if (temp->data > value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    inserted = true;
                }
                temp = temp->left;
            }
            else
            {
                throw std::runtime_error("Key already exists"); // Throw an error if stack is empty
            }
        }
    }
}

template <typename T>
bool BinaryTree<T>::search(T value)
{
    Node<T> *temp = this->root;
    bool found = false;
    bool traversed = false;
    while(!found && !traversed){
        if(temp->data == value){
            found = true;
        }

        if(temp->data > value){
            if(temp->left == nullptr){
                traversed = true;
            }
            else{
                temp = temp->left;
            }
        }
        else if(temp->data < value){
            if(temp->right == nullptr){
                traversed = true;
            }
            else{
                temp = temp->right;
            }
        }
    }
    return found && !traversed;
}

template <typename T>
bool BinaryTree<T>::deleteNode(T value)
{
    return false;
}

template <typename T>
void BinaryTree<T>::inorder(Node<T> *node)
{
    if(node->left != nullptr)
        this->inorder(node->left);
    std::cout << node->data << " " << std::endl;
    if(node->right != nullptr)
        this->inorder(node->right);
}

template <typename T>
Node<T> *BinaryTree<T>::getRoot()
{
    return this->root;
}
