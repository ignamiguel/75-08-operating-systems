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
  cout<<"Ingrese un string a pasar"<<endl;
  string dato;
  while (cin>>dato){
    produce.wait();
    msj->setDato(dato);
    consume.post();
    cout<<"Ingrese un string a pasar"<<endl;
  }
  produce.wait();
  msj->setDato(string(""));
  msj->setUltimo();
  consume.post();
}
