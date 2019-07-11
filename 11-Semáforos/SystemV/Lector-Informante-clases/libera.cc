// linkeditar con LOADLIBES=-lrt
#include <iostream>
#include <sys/mman.h>
#include "../Sem-posix/p_shm.h"

using namespace std;

int main (){
  const char * nom="Area51";
  p_shm Area51 ("Area51");
  Area51.del();
}
