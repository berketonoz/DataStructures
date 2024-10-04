class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = {}

    def insert(self, value):
        bucket = hash(value) % self.size
        if bucket in self.table:
            if value in self.table[bucket]:
                return False
            self.table[bucket].append(value)
        else:
            self.table[bucket] = [value]
        return True
    
    def delete(self, value):
        bucket = hash(value) % self.size
        if bucket in self.table and value in self.table[bucket]:
            self.table[bucket].remove(value)
            if not self.table[bucket]:  # if the bucket is empty after removal, you might want to clean up
                del self.table[bucket]

    def lookup(self, value):
        bucket = hash(value) % self.size
        return bucket in self.table and value in self.table[bucket]

def main():
    # Create a hash table with a certain size
    ht = HashTable(10)
    
    # Test inserting elements
    print("Inserting elements into the hash table...")
    ht.insert(1)
    ht.insert(2)
    ht.insert(3)
    ht.insert(10)  # This will collide with 1 if hash function is modulo size

    # Test lookup
    print("Looking up elements...")
    print(f"Element 2 found: {'Yes' if ht.lookup(2) else 'No'}")
    print(f"Element 5 found: {'Yes' if ht.lookup(5) else 'No'}")

    # Test deletion
    print("Deleting element 2...")
    ht.delete(2)
    print(f"Element 2 found after deletion: {'Yes' if ht.lookup(2) else 'No'}")

    # Re-insert and test
    print("Re-inserting element 2...")
    ht.insert(2)
    print(f"Element 2 found after re-inserting: {'Yes' if ht.lookup(2) else 'No'}")

if __name__ == "__main__":
    main()
