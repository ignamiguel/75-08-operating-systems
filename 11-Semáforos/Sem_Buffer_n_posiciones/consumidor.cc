#include "includes.h"
#include "Area.h"
#include "../Sem-sv/sv_shm.h"
#include "../Sem-sv/sv_sem.h"

int main(){
  Area * a;
  sv_shm a51("Area51");
  a= static_cast <Area*>(a51.map(sizeof(Area)));
  sv_sem prod("A51p",5);
  sv_sem cons("A51c",0);
  Mensaje dato;
  cout<<"Consumiendo"<<endl;
  while (true){
    cons.wait();
    if (a->esUltimo()) break;
    dato=a->saca();
    cout<<"Leido<"<<dato.getDato()<<">"<<endl;
    cout<<"Consumiendo"<<endl;
    prod.post();
  }
  cout<<"Productor termina"<<endl;
  a51.del();
  prod.del();
  cons.del();
}
    