#include <iostream>
#include <string>

using namespace std;

struct Node
{
    std::string key;
    int value;
    Node *next;
};

struct HashTable
{
    unsigned int capacity;
    unsigned int size;

    Node **stoarge;
};

HashTable *create_table(unsigned int capacity)
{
    HashTable *table = new HashTable()
                           table->capacity = capacity;
    table->size = 0;

    table->stoarge = new Node *[capacity];

    return table;
}

void destroy_list(Node *&HEAD)
{
    if (HEAD == nullptr)
        return;
    Node *next = HEAD->next;
    while (next != nullptr) {
        delete HEAD;
        HEAD = next;
        next = next->next;
    }
    delete HEAD;
    HEAD = nullptr;
}

void *destroy_table(HashTable *&table)
{

    for (unsigned int idx = 0; idx < table->capacity; ++idx)
    {
        destroy_list(table->stoarge[idx]);
    }
    delete[] table->stoarge;
}
unsigned int hash(HashTable* const & table, std::string key) {
    unsigned int idx = 0u;
    for (auto el : key) {
        idx += (static_cast<unsigned int>(el) - static_cast<unsigned int>('a'));
    }
    return idx % table->capacity;
}

int main()
{
    HashTable *table = create_table(20);
    return 0;
}