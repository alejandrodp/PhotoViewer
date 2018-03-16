#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

#include <iostream>
#include "bitset"

class SimpleList{
private:
    struct Node{
        struct Node* next;
        std::bitset<32> address;
        int value;

    } *root;
    unsigned int size;
public:
    SimpleList();
    ~SimpleList();
    void AddEnd(std::bitset<32> value);
    std::bitset<32> getValue(int pos);
    int getSize();
};
#endif
