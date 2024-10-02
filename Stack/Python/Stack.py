class Stack:
    def __init__(self):
        self.stack = []  # Initialize an empty list to represent the stack
        self.size = 0

    def __del__(self):
        print("Stack is being deleted")
    
    def push(self,node):
        self.stack.append(node)
        self.size += 1

    def pop(self):
        if self.isEmpty():
            raise RuntimeError("Stack is empty")
        self.size -= 1
        return self.stack.pop()

    def isEmpty(self):
        return len(self.stack) == 0


if __name__ == "__main__":
    stack = Stack()
    sample_list = ["This", "is", "a", "sample", "list"]
    
    print("Is stack empty?", stack.is_empty())  # True initially

    # Push elements
    for item in sample_list:
        print(f"Pushing: {item}")
        stack.push(item)

    # Pop elements until the stack is empty
    while not stack.is_empty():
        print("Popped:", stack.pop())
    
    print("Is stack empty?", stack.is_empty())  # Should be True