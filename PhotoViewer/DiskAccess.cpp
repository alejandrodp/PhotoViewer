//
// Created by davidsq on 12/03/18.
//

#include <cstring>
#include "DiskAccess.h"

void *DiskAccess::readFromDisk(int pageNumber) {
    fstream file = fstream('Page' + pageNumber + ".bin",ios::in|ios::binary);
    void * data = calloc(1024, 1024 * 4);
    file.read((char *)data, 0x400000);
    file.close();
    return data;
}

bool DiskAccess::writeToDisk(int pageNumber, void *memorySpace, int size) {
    ofstream file = ofstream('Page' + pageNumber + ".bin",ios::out|ios::binary);
    char * buffer = static_cast<char *>(memorySpace);
    file.write(buffer, size);
    file.close();
    return false;
}
