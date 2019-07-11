#include  "../Sem-posix/p_sem.h"
#include  "../Sem-posix/p_shm.h"
#include  "Mensaje.h"
using namespace std;

int main(){
  p_sem produce ("productor",1);
  p_sem consume ("consumidor",0);
  p_shm area("area");
  produce.del();
  consume.del();
  area.del();
}