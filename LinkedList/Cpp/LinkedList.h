// Node struct template
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T value) : data(value), next(nullptr) {}
};

// LinkedList class template
template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}  // Constructor initializes head to nullptr
    ~LinkedList();                   // Destructor to free memory

    void insert(T val);              // Insert a new node
    bool deleteNode(T val);          // Delete a node with a specific value
    void print();                    // Print the linked list
};

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::insert(T val)
{
    Node<T> *newNode = new Node<T>(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

template <typename T>
bool LinkedList<T>::deleteNode(T val)
{
    if (!head) return false;  // Empty list

    // Deleting the head node
    if (head->data == val)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Traverse and delete a non-head node
    Node<T> *temp = head;
    while (temp->next)
    {
        if (temp->next->data == val)
        {
            Node<T> *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            return true;
        }
        temp = temp->next;
    }

    return false;  // Value not found
}

template <typename T>
void LinkedList<T>::print()
{
    Node<T> *temp = head;
    while (temp)
    {
        std::cout << temp->data; 
        if (temp->next != nullptr) 
            std::cout << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
