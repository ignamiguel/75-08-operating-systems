#include  "../Sem-sv/sv_sem.h"
#include  "../Sem-sv/sv_shm.h"
#include  "Mensaje.h"
using namespace std;

int main(){
  sv_sem produce ("productor",1);
  sv_sem consume ("consumidor",0);
  sv_shm area("area");
  produce.del();
  consume.del();
  area.del();
}