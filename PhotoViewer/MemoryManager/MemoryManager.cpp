//
// Created by davidsq on 12/03/18.
//

#include <iostream>
#include "MemoryManager.h"

MemoryManager * MemoryManager::instance = nullptr;

bitset<32> MemoryManager::allocate(int size) {
    listNode * currentPage = pageList;
    bool spaceFound = false;
    bitset<32> newAddress;
    for(;currentPage != nullptr; currentPage = currentPage->next){
        currentPage->usage >>= 1;
        if(currentPage->used + size < 0x400000) {
            spaceFound = true;
            currentPage->usage[0] = 1;
            break;
        }else if(currentPage->next == nullptr){
            break;
        }
    }

    if(!spaceFound){ //Create new page if needed
        currentPage->next = new listNode;
        currentPage->next->start = (currentPage->start + 0x400000);
        currentPage->next->page = currentPage->page + 1;
        currentPage = currentPage->next;
        currentPage->next = nullptr;
        currentPage->used = 0;
        currentPage->usage = bitset<8>("10000000");
    }

    std::cout << "Page to save photo: " << currentPage->page << std::endl;

    if(currentPage->page > 3){
        currentPage->inMemory = false;
        loadPage(currentPage->page);
    }else{
        currentPage->inMemory = true;
    }

    newAddress = bitset<32>(currentPage->page);

    currentPage->used += size;

    newAddress <<= 24;

    newAddress |= bitset<32>(currentPage->used - size);

    return newAddress;
}

MemoryManager::MemoryManager(int size){
    mem = malloc(static_cast<size_t>(size));
    this->size = size;
    pageList = new listNode();
    pageList->page = 1;
    pageList->inMemory = true;
    pageList->start = mem;
    pageList->used = 0;
    pageList->next = nullptr;
    pageList->usage = bitset<8>("00000000");
}

MemoryManager::~MemoryManager(){

}

MemoryManager * MemoryManager::getInstance() {
    if(instance == nullptr){
        instance = new MemoryManager(0xC00000);
    }
    return instance;
}

bool MemoryManager::loadPage(int page) {
    bool success = false;

    listNode * leastUsed;
    listNode * currentPage;
    listNode * toLoad = nullptr;
    if(page > 1){
        leastUsed = pageList;
        currentPage = pageList->next;
    }
    else{
        leastUsed = pageList->next;
        currentPage = pageList->next->next;
        toLoad = pageList;
    }

    for(;currentPage != nullptr; currentPage = currentPage->next){
        if(currentPage->inMemory){ //Checks if the current page is in memory
            if(leastUsed->usage.to_ulong() >= currentPage->usage.to_ulong()){ //Checks if the current page is used more than the one chosen to be taken down
                leastUsed = currentPage;
            }
            currentPage->usage >>= 1;
        }else if(currentPage->page == page){ //Get the details of the page to load
            toLoad = currentPage;
        }
    }

    DiskAccess::writeToDisk(leastUsed->page, leastUsed->start, 0x400000);
    if(toLoad->used > 0) { //Check for something to load
        void *dataToLoad = DiskAccess::readFromDisk(page);

        toLoad->start = memcpy(leastUsed->start, dataToLoad, 0x400000);

        delete dataToLoad;
    }else{ //Clear up the memory
        toLoad->start = leastUsed->start;
        memset(toLoad->start, 0, 0x400000);
    }

    toLoad->inMemory = true;
    leastUsed->inMemory = false;

    emit change(*pageList);

    return success;
}

void *MemoryManager::dereference(bitset<32> address) {
    return MMU::getAddress(address);
}
