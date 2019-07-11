#include "includes.h"
#include "Area.h"
#include "../Sem-posix/p_shm.h"
#include "../Sem-posix/p_sem.h"

int main(){
  p_shm a51("Area51");
  p_sem prod("A51p",5);
  p_sem cons("A51c",0);
  a51.del();
  prod.del();
  cons.del();
}
