class Node:
    def __init__(self, value) -> None:
        self.data: int = value  # Store the data value
        self.next: 'Node' = None  # Initialize the next pointer to None

class LinkedList:
    def __init__(self) -> None:
        self.head: Node = None  # Initialize the head to None, indicating an empty list

    def insert(self, val) -> None:
        """Inserts a new node with the specified value at the end of the list."""        
        newNode = Node(val)

        if self.head is None:
            self.head = newNode
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = newNode

    def delete(self, val) -> bool:
        """Deletes the first node with the specified value from the list.
        Returns True if the node was deleted, False if not found.
        """
        if self.head is None:  # If the list is empty
            return False

        # Deleting the head node
        if self.head.data == val:
            self.head = self.head.next  # Move the head to the next node
            return True

        # Traverse the list to find the node to delete
        current = self.head
        while current.next:  # Ensure we're not accessing null pointers
            if current.next.data == val:  # Node to delete found
                current.next = current.next.next  # Bypass the node to delete it
                return True
            current = current.next  # Move to the next node

        return False  # Value not found in the list
    
    def printList(self):
        temp = self.head
        while temp:
            print(temp.data,end="")
            if temp.next:
                print(" -> ",end="")
            temp = temp.next
        print()

def main():
    linked_list = LinkedList()

    # Insert items into the linked list
    linked_list = LinkedList()
    linked_list.insert(1)
    linked_list.insert(2)
    linked_list.insert(3)
    linked_list.printList() # Output: 1 -> 2 -> 3

    linked_list.delete(2)
    linked_list.printList() # Output: 1 -> 3
    linked_list.delete(1)
    linked_list.printList() # Output: 3
    linked_list.delete(3)
    linked_list.printList() # Output: 

if __name__ == "__main__":
    main()
