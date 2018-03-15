//
// Created by davidsq on 12/03/18.
//

#ifndef TAREACORTA_DISKACCESS_H
#define TAREACORTA_DISKACCESS_H

#include "fstream"

using namespace std;


class DiskAccess {
public:
    static void * readFromDisk(int pageNumber);

    static bool writeToDisk(int pageNumber, void * memorySpace, int size);
};


#endif //TAREACORTA_DISKACCESS_H
