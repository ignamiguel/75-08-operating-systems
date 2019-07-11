//Swap
#include "Area_Swap.h"
#ifndef Swap_h
#define Swap_h
using namespace std;

static bool val_local=true;  // un asco, pero oculta informacion a proceso.cpp

void inicializa(AreaInsEsp * area){
    area->valor=false;
    cout<<boolalpha<<"Inicializado en "<<boolalpha<<area->valor<<endl;
}



void mi_Swap (AreaInsEsp * area, bool& val){   //indivisible  ojo swap existe en c++
  bool local=area->valor;
    area->valor=val;
    val=local;

}
void mutexbegin(AreaInsEsp * area){
    string sigue;
    mi_Swap(area,val_local);
    while (val_local){
        cout<<"MutexBegin: valor local="<<boolalpha<<val_local<<endl;
        cout<<"Sigo?"<<endl;
        cin>>sigue;
        mi_Swap(area,val_local);
    }
    cout<<"MutexBegin: entra en seccion critica, valor local="
            <<boolalpha<<val_local<<endl;        
}

void mutexend(AreaInsEsp * area){
    mi_Swap(area,val_local);
    cout<<"MutexEnd: sale de seccion critica, valor local="
            <<boolalpha<<val_local<<endl;  
}
#endif
