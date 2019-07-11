#include "../Sem-posix/p_shm.h"


using namespace std;
int main(int argc, char *argv[]) {
    p_shm Area51 ("Area51");
    Area51.del();
} 