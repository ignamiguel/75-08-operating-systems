#include "includes.h"
#include "Area.h"
#include "../Sem-sv/sv_shm.h"
#include "../Sem-sv/sv_sem.h"

int main(int argc, char * argv[]){
  if (argc<2){
    cerr<<"Uso"<<argv[0]<<" <nro de consumidor>"<<endl;
        exit(2);
  }
  string nom="Consumidor"+string(argv[1]);
  string rta;
  Area * a;
  sv_shm a51("Area51");
  a= static_cast <Area*>(a51.map(sizeof(Area)));
  sv_sem prod("A51p");
  sv_sem cons("A51c");
  sv_sem mutex("A51m");
  Mensaje dato;
  cout<< nom<<" sigo ..."<<endl;
  cin>>rta;
  cout<<nom<<" consumiendo"<<endl;
  while (true){
    cons.wait();
    if (a->esFin()) break;
    mutex.wait();
     dato=a->saca();
    mutex.post();
    //if (a->esFin()) break;
    cout<<nom<<" leido<"<<dato.getDato()<<">"<<endl;
    cout<<nom<<" consumiendo"<<endl;
    prod.post();
    cout<< nom<<" sigo ..."<<endl;
    cin>>rta;
  }
  cons.post();  //libera en cadena a los consumidores
  cout<<nom<<" termina"<<endl;
}
    