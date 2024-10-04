class Queue:
    def __init__(self, capacity=None):
        self.capacity = capacity
        self.q = []

    def enqueue(self, value):
        if self.capacity is not None and len(self.q) >= self.capacity:
            raise RuntimeError("Queue is full")
        self.q.append(value)

    def dequeue(self):
        if not self.isEmpty():
            return self.q.pop(0)
        return "Queue is empty"

    def peek(self):
        if self.isEmpty():
            return "Queue is empty"
        return self.q[0]
    
    def isEmpty(self):
        return len(self.q) == 0

    def __len__(self):
        return len(self.q)


def main():
    q = Queue()  # Create a queue for integers
    print("Enqueuing elements{1,2,3,4}...")
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    q.enqueue(4)  # This was not included in your original C++ enqueuing, but added as per the printed message

    print(f"Current front element: {q.peek()}")  # Should print 1

    print("Dequeuing...")
    q.dequeue()
    print(f"New front element after one dequeue: {q.peek()}")  # Should print 2

    print(f"Checking if queue is empty: {'Yes' if q.isEmpty() else 'No'}")  # Should print No

    print("Dequeuing remaining elements...")
    q.dequeue()
    q.dequeue()
    q.dequeue()  # Added one more dequeue to empty the queue after adding 4th element

    print(f"Checking if queue is empty after dequeuing all elements: {'Yes' if q.isEmpty() else 'No'}")  # Should print Yes

    try:
        print("Attempting to peek into an empty queue: ", end="")
        print(q.peek())
    except IndexError as e:
        print(e)  # Should catch and print "Queue is empty"

if __name__ == "__main__":
    main()