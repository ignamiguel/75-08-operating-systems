#include  "../Sem-posix/p_sem.h"
#include  "../Sem-posix/p_shm.h"
#include  "Mensaje.h"
using namespace std;

int main(){
  p_sem produce ("productor",1);
  p_sem consume ("consumidor",0);
  Mensaje * msj;
  p_shm area("area");
  msj=reinterpret_cast<Mensaje *> (area.map(BUFSIZ));
  if (msj== MAP_FAILED){
	  perror ("No se puede mapear el area ");
	  cerr<<"Clave<"<<area.getClave()<<"> "<<endl; 
	  exit(1);
  }
  consume.wait();
  string res=msj->getDato();
  while (!msj->esUltimo()){
    produce.post();
    cout<<"Obtenido "<<res<<endl;
    consume.wait();
    res=msj->getDato();
  }
  produce.del();
  consume.del();
  area.del();
}
