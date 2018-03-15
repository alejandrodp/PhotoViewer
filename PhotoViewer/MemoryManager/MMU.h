//
// Created by davidsq on 07/03/18.
//

#ifndef TAREACORTA_MMU_H
#define TAREACORTA_MMU_H

#include "MemoryManager.h"
#include "bitset"

using namespace std;

class MMU {

public:
    static void * getAddress(bitset<32> virtAddress);;

};

#endif //TAREACORTA_MMU_H
