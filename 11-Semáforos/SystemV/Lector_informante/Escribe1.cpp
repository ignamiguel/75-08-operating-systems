#include <iostream>
#include "dat.h"
#include "../Sem-posix/p_shm.h"


using namespace std;
int main(int argc, char *argv[]) {
    p_shm Area51 ("Area51");
    void * ptr;
    dat * area;
    int len=sizeof(dat);
    ptr=Area51.map(len);
    area=reinterpret_cast<dat *> (ptr);
    area->val=100;        
}