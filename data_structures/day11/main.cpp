#include "hashTable.hpp"

int main() {

    HashTable t(20);
    string name = "Anna";
    t.Insert(name, 45);
    t.PrintTable();
    t.Search(name);
    t.Delete(name);
    t.PrintTable();

    return 0;
}