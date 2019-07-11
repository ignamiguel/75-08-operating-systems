#include  "../Sem-sv/sv_sem.h"
#include  "../Sem-sv/sv_shm.h"
#include  "Mensaje.h"
using namespace std;

int main(){
  sv_sem productor ("productor", 1);
  sv_sem consumidor ("consumidor", 0);
  Mensaje * msj;
  
  sv_shm area("area");
  msj=reinterpret_cast<Mensaje *> (area.map(BUFSIZ));
  
  consumidor.wait();
  string res = msj->getDato();
  
  while (!msj->esUltimo()){
    productor.post();
    cout << "Obtenido "<< res << endl;
    consumidor.wait();
    res=msj->getDato();
  }
  productor.del();
  consumidor.del();
  area.del();
}
