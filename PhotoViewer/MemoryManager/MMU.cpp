//
// Created by davidsq on 07/03/18.
//

#include "MMU.h"
#include <iostream>
void * MMU::getAddress(bitset<32> virtAddress) {
    int page = 0;
    int offset = 0;

    offset = (int) (bitset<32>(virtAddress) & bitset<32>("00000000111111111111111111111111")).to_ulong();
    page = static_cast<int>(((virtAddress) >> 24).to_ulong());
    std::cout << "Page number: " << page << " Desplazamiento: " << offset << std::endl;

    MemoryManager * manager = MemoryManager::getInstance();

    MemoryManager::listNode * currentNode = manager->pageList;

    for(;currentNode != nullptr; currentNode = currentNode->next){
        currentNode->usage >>= 1;
        if(currentNode->page == page){
            currentNode->usage[0] = 1;
            break;
        }
    }

    if(currentNode->inMemory == false){
        manager->loadPage(page);
    }

    void * address = currentNode->start + offset;

    return address;
}
