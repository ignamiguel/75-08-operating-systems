
#include  "../Sem-sv/sv_sem.h"
#include  "../Sem-sv/sv_shm.h"
#include  "Mensaje.h"
using namespace std;

int main(){
  sv_sem productor ("productor", 1);
  sv_sem consumidor ("consumidor", 0);
  
  Mensaje * msj;
  sv_shm area("area");

  msj = reinterpret_cast<Mensaje *> (area.map(BUFSIZ)); 
  cout << "Ingrese un string a pasar" << endl;
  
  string dato;
  
  while (cin >> dato){
    productor.wait();
    msj->setDato(dato);
    consumidor.post();
    cout<<"Ingrese un string a pasar"<<endl;
  }
  
  productor.wait();
  msj->setDato(string(""));
  msj->setUltimo();
  consumidor.post();
}
