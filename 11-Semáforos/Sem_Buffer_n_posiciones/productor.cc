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
  string lee;
  cout<<"Ingrese un string"<<endl;
  while (cin>>lee){
    prod.wait();
    cout<<"Poniendo "<<lee<<endl;
    a->pone(Mensaje (lee));
    cons.post();
    cout<<"Ingrese un string"<<endl;
  }
  a->setUltimo();
  cons.post();
  cout<<"Productor terminado"<<endl;
}

    