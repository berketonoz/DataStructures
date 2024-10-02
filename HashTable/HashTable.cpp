#include "HashTable.h"
#include <iostream>
#include <string>

int main() {
    // Create a hash table with a certain size
    HashTable<int> ht(10);

    // Test inserting elements
    std::cout << "Inserting elements into the hash table..." << std::endl;
    ht.insert(1);
    ht.insert(2);
    ht.insert(3);
    ht.insert(10);  // This will collide with 1 if hash function is modulo size

    // Test lookup
    std::cout << "Looking up elements..." << std::endl;
    std::cout << "Element 2 found: " << (ht.lookup(2) ? "Yes" : "No") << std::endl;
    std::cout << "Element 5 found: " << (ht.lookup(5) ? "Yes" : "No") << std::endl;

    // Test deletion
    std::cout << "Deleting element 2..." << std::endl;
    ht.deleteHash(2);
    std::cout << "Element 2 found after deletion: " << (ht.lookup(2) ? "Yes" : "No") << std::endl;

    // Re-insert and test
    std::cout << "Re-inserting element 2..." << std::endl;
    ht.insert(2);
    std::cout << "Element 2 found after re-inserting: " << (ht.lookup(2) ? "Yes" : "No") << std::endl;

    return 0;
}
