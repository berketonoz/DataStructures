#include <vector>
#include <stdexcept>

template <typename T>
class Queue
{
private:
    int size;
    std::vector<T> *queue;

public:
    Queue(int size);
    ~Queue();

    void enqueue(T value);
    void dequeue();
    T peek();
    bool isEmpty();
};

template <typename T>
Queue<T>::Queue(int size)
{
    this->size = size;
    this->queue = new std::vector<T>();
}

template <typename T>
Queue<T>::~Queue()
{
    this->size = 0;
    queue->clear();
    delete queue;
}

template <typename T>
void Queue<T>::enqueue(T value)
{
    this->queue->push_back(value);
}

template <typename T>
void Queue<T>::dequeue()
{
    if (this->isEmpty())
    {
        throw std::runtime_error("Queue is empty, cannot dequeue");
    }
    this->queue->erase(this->queue->begin());
}

template <typename T>
T Queue<T>::peek()
{
    if (this->isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    return (*this->queue)[0];
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return this->queue->empty();
}