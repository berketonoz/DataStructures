#include <iostream>
#include "Queue.h"  // Assuming your Queue class is defined in Queue.h

int main() {
    Queue<int> q(10);  // Create a queue for integers

    std::cout << "Enqueuing elements{1,2,3,4}..." << std::endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Current front element: " << q.peek() << std::endl;  // Should print 1

    std::cout << "Dequeuing remaining elements..." << std::endl;
    q.dequeue();
    std::cout << "New front element after one dequeue: " << q.peek() << std::endl;  // Should print 2

    std::cout << "Checking if queue is empty: " << (q.isEmpty() ? "Yes" : "No") << std::endl;  // Should print No

    std::cout << "Dequeuing remaining elements..." << std::endl;
    q.dequeue();
    q.dequeue();  // Queue should be empty after this

    std::cout << "Checking if queue is empty after dequeuing all elements: " << (q.isEmpty() ? "Yes" : "No") << std::endl;  // Should print Yes

    try {
        std::cout << "Attempting to peek into an empty queue: ";
        std::cout << q.peek() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;  // Should catch and print "Queue is empty"
    }

    return 0;
}
