//
// Created by youssef on 11/26/22.
//

#include "HashTable.h"
#include <iostream>

//  Print the hash table
void HashTable::print() {
//  For each cell in the hash table
    for (int i = 0; i < this->tableSize; i++) {
        std::cout << i << ": ";

//      Traverse the linked list at this cell
        LinkedListNode *current = this->table[i];
        while (current != nullptr) {
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << '\n';
    }
}

//  Helper method for getting the index in the hash table for the key
int HashTable::hash(std::string &key) const {
    int asciiSum = 0;

//  Sum the ASCII codes for all characters in the key
    for (char i: key)
        asciiSum += i;

//  Return this sum modulus the table size
    return (asciiSum % this->tableSize);
}

//  Insert a new key into the hash table
void HashTable::insert(std::string value) {
//  Hash the key
    int idx = this->hash(value);

//  Check if there is no node found at table[hash(key)]
    if (this->table[idx] == nullptr) {
//      If not, create a new node
        this->table[idx] = new LinkedListNode();
    } else {
//      Otherwise, insert a new node at the head
        LinkedListNode *tmp = this->table[idx];
        this->table[idx] = new LinkedListNode();
//      And fix the next pointers on the nodes
        this->table[idx]->next = tmp;
    }
//  Update the new node's value to the inserted key
    this->table[idx]->value = value;
}

HashTable::HashTable(int s) {
    this->tableSize = s;
    this->table = new LinkedListNode *[this->tableSize];

//  Initialize the hash table linked lists
    for (int i = 0; i < this->tableSize; i++)
        this->table[i] = nullptr;
}

HashTable::~HashTable() {
//  Iterate over all cells in the hash table
    for (int i = 0; i < this->tableSize; ++i) {
//      Traverse the linked list at this cell
        LinkedListNode *current = this->table[i];
        LinkedListNode *p = current;
//      As long as there are nodes in the linked list
        while (p != nullptr) {
//          Keep freeing the allocated linked list node memory
            p = p->next;
            delete current;
            current = p;
        }
    }

//  Delete the hash table
    delete[] this->table;
}
