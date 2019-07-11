//Test & Set
#include "Area_TS.h"
#ifndef TS_h
#define TS_h
using namespace std;

void inicializa(AreaInsEsp * area){
    area->valor=false;
    cout<<boolalpha<<"Inicializado en "<<boolalpha<<area->valor<<endl;
}

bool TS (AreaInsEsp * area){   //indivisible
  if (area->valor) return (area->valor);
  else {
    area->valor=true;
    return false;
  }
}

void mutexbegin(AreaInsEsp * area){
    string sigue;
    while (TS(area)){
        cout<<"MutexBegin: valor="<<boolalpha<<area->valor<<endl;
        cout<<"Sigo?"<<endl;
        cin>>sigue;
    }
    cout<<"MutexBegin: entra en seccion critica, valor="
            <<boolalpha<<area->valor<<endl;        
}

void mutexend(AreaInsEsp * area){
    area->valor=false;
    cout<<"MutexEnd: sale de seccion critica, valor="
            <<boolalpha<<area->valor<<endl;  
}
#endif
