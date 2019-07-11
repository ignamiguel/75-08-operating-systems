#include "includes.h"
#include "Area.h"
#include "../Sem-sv/sv_shm.h"
#include "../Sem-sv/sv_sem.h"

int main(int argc, char * argv[]){
  if (argc<2){
    cerr<<"Uso"<<argv[0]<<" <nro de productor>"<<endl;
        exit(2);
  }
  string nom="Productor"+string(argv[1]);
  string rta;
  Area * a;
  sv_shm a51("Area51");
  a= static_cast <Area*>(a51.map(sizeof(Area)));
  sv_sem prod("A51p",5);
  sv_sem cons("A51c",0);
  sv_sem mutex("A51m",1);
  string lee;
  cout<<nom<<" Ingrese un string"<<endl;
  while (cin>>lee){
    prod.wait();
    cout<<nom<<" poniendo "<<lee<<endl;
    mutex.wait();
     cout<< nom<<" en el mutex ..."<<endl;
     cin>>rta;
     a->pone(Mensaje (lee));
    mutex.post();
    cons.post();
    cout<<nom<<" Ingrese un string"<<endl;
  }
  cout<<nom<<" terminado"<<endl;
}

    