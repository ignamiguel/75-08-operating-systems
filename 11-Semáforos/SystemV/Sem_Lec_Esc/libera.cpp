#include <iostream>
#include "../Sem-posix/p_sem.h"
#include "../Sem-posix/p_shm.h"

using namespace std;
int main(int argc, char *argv[]) {
    p_sem mutex("Mutex",1);
    p_sem entra("Entra",1);
    p_shm area("Area");
    mutex.del();
    entra.del();
    area.del();
    
}