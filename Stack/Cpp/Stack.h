// Template struct for a Node
template <typename T>
struct Node
{
    T data;     // Data stored in the node
    Node<T> *prev; // Pointer to the next node

    // Constructor to initialize the node
    Node<T>(T value) : data(value), prev(nullptr) {}
};

template <typename T>
class Stack
{
private:
    int size;
    Node<T> *head;

public:
    Stack(/* args */);
    ~Stack();

    T pop();
    void push(T value);
    bool isEmpty();
};

template <typename T>
Stack<T>::Stack(/* args */)
{
    this->size = 0;
    this->head = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
    while (!this->isEmpty())
        T item = this->pop();
}

// Pop method
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty"); // Throw an error if stack is empty
    }

    Node<T>* temp = this->head;          // Store the top node
    T value = temp->data;          // Get the data from the top node
    this->head = this->head->prev;             // Move head to the next node
    delete temp;                   // Delete the old top node
    this->size--;                         // Decrement size
    return value;                  // Return the popped value
}

template <typename T>
void Stack<T>::push(T value)
{
        Node<T> *new_head = new Node<T>(value);
        new_head->prev = this->head;
        this->head = new_head;
        this->size++;
        // Node<T> *old_head = this->head;
        // delete this->head;
        // this->head = new Node<T>(value);
        // this->head->prev = old_head;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return this->head == nullptr;
}
