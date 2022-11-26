#include "HashTable.h"

int main() {
//  Create the hash table
    auto *ht = new HashTable(5);

//  Group 0
    ht->insert("car");
    ht->insert("rca");
    ht->insert("rac");

//  Group 1
    ht->insert("ahmed");
    ht->insert("hamed");

//  Group 4
    ht->insert("lma");
    ht->insert("mal");

//  Show keys in the hash table
    ht->print();

//  Delete the hash table
    delete ht;

    return 0;
}
