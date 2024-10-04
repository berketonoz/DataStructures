#include <vector>
#include <stdexcept>

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node<T>(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;

public:
    Queue();
    ~Queue();

    void enqueue(T value);
    void dequeue();
    T peek();
    bool isEmpty();
};

template <typename T>
Queue<T>::Queue()
{
    this->front = nullptr;
    this->rear = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
    while (this->front != nullptr)
    {
        this->dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (this->isEmpty())
    {
        this->front = this->rear = newNode;
    }
    else
    {
        this->rear->next = newNode;
        this->rear = newNode;
    }
}

template <typename T>
void Queue<T>::dequeue()
{
    if (!this->isEmpty())
    {
        Node<T> *temp = this->front;
        this->front = this->front->next;
        if (this->front == nullptr)
        {
            this->rear = nullptr;
        }
        delete temp;
    }
}

template <typename T>
T Queue<T>::peek()
{
    return (!this->isEmpty()) ? this->front->data : -1;
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return this->front == nullptr;
}