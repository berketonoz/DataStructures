#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList<int> linkedList;

    // Insert items into the linked list
    linkedList.insert(1);
    linkedList.insert(2);
    linkedList.insert(3);
    linkedList.print();

    // Delete items and print the list after each operation
    linkedList.deleteNode(1);
    linkedList.print();
    linkedList.deleteNode(2);
    linkedList.print();
    linkedList.deleteNode(3);
    linkedList.print();

    return 0;
}
