#include "includes.h"
#include "Area.h"
#include "../Sem-sv/sv_shm.h"
#include "../Sem-sv/sv_sem.h"

int main(){
  sv_shm a51("Area51");
  sv_sem prod("A51p");
  sv_sem cons("A51c");
   sv_sem mutex("A51m");
  a51.del();
  prod.del();
  cons.del();
  mutex.del();
}
