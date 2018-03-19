//
// Created by davidsq on 12/03/18.
//

#ifndef TAREACORTA_MEMORYMANAGER_H
#define TAREACORTA_MEMORYMANAGER_H

#include "MMU.h"
#include "DiskAccess.h"
#include <cstring>
#include "bitset"
#include <QObject>

using namespace std;


class MemoryManager : public QObject {

    Q_OBJECT

    friend class MMU;

private:

    explicit MemoryManager(int size);
    void * mem;
    int size;
    ~MemoryManager();

    static MemoryManager * instance; //Singleton

public:

    static MemoryManager * getInstance();

    bitset<32> allocate(int size);

    void * dereference(bitset<32> address);

    struct listNode{
        int page;
        void * start;
        int used;
        bool inMemory;
        listNode * next;
        bitset<8> usage;
    };

signals:
    void change(listNode pages);

protected:

    listNode * pageList;

    bool loadPage(int page);

};


#endif //TAREACORTA_MEMORYMANAGER_H
