//
// Created by youssef on 11/26/22.
//

#ifndef LAB_3_HASHTABLE_H
#define LAB_3_HASHTABLE_H
#include "LinkedListNode.h"

class HashTable {
private:
    int tableSize;
    LinkedListNode **table;

public:
    explicit HashTable(int s);

    virtual ~HashTable();

    void insert(std::string val);

    void print();

private:
    int hash(std::string &key) const;
};


#endif //LAB_3_HASHTABLE_H
