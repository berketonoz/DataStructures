#include <vector>
#include <list>

template <typename T>
class HashTable
{
private:
    std::vector<std::list<T>> table;
    int size;

public:
    HashTable(int size) : size(size)
    {
        table.resize(size);
    }

    bool insert(const T &value)
    {
        if(this->lookup(value))
            return false;
        int bucket = std::hash<T>{}(value) % size;
        table[bucket].push_back(value);
        return true;
    }

    bool lookup(const T &value)
    {
        int bucket = std::hash<T>{}(value) % size;
        for (auto &elem : table[bucket])
        {
            if (elem == value)
            {
                return true;
            }
        }
        return false;
    }

    void deleteHash(const T &value)
    {
        int bucket = std::hash<T>{}(value) % size;
        table[bucket].remove(value);
    }
};
