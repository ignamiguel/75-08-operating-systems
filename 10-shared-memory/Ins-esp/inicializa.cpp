#include <iostream>
#include <cstdlib>
using namespace std;
#include "InsEsp.h"
#include "../Sem-sv/sv_shm.h"

int main(int argc, char *argv[]) {
    
    sv_shm aInsEsp ("aInsEsp");
    void * ptr;
    AreaInsEsp * area;
    int len=sizeof(AreaInsEsp);
    ptr=aInsEsp.map(len);
    area=reinterpret_cast<AreaInsEsp *> (ptr);
    
    inicializa (area);
  
}
