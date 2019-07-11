#include "includes.h"
#include "Area.h"
#include "../Sem-posix/p_shm.h"
#include "../Sem-posix/p_sem.h"

int main(){
  Area * a;
  p_shm a51("Area51");
  a= static_cast <Area*>(a51.map(sizeof(Area)));
  p_sem prod("A51p",5);
  p_sem cons("A51c",0);
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

    