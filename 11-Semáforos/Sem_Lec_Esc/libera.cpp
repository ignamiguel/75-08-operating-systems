#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"

using namespace std;
int main(int argc, char *argv[]) {
    sv_sem mutex("Mutex");
    sv_sem entra("Entra");
    sv_shm area("Area");
    mutex.del();
    entra.del();
    area.del();
    
}