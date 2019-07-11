#include <iostream>
#include <cstdlib>
using namespace std;
#include "Mutex.h"
#include "../Sem-sv/sv_shm.h"

int main(int argc, char *argv[]) {
    
    sv_shm aMutex ("Mutex");
    void * ptr;
    AreaMutex * area;
    int len=sizeof(AreaMutex);
    ptr=aMutex.map(len);
    area=reinterpret_cast<AreaMutex *> (ptr);
    
    inicializa (area);
  
}
