#include <iostream>
#include "../Sem-sv/sv_shm.h"

using namespace std;
int main(int argc, char *argv[]) {
    sv_shm AreaMutex("AreaMutex");
    AreaMutex.del();    
}
