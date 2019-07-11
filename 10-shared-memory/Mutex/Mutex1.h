//Mutex 1
#include "Area_Mutex.h"
#ifndef Mutex_h
#define Mutex_h
using namespace std;

void inicializa(AreaMutex * area, int yo=0){
    area->ocupado=false;
    cout<<boolalpha<<"Inicializado en "<<boolalpha<<area->ocupado<<endl;
}

void mutexbegin(AreaMutex * area,int yo){
    string sigue;
    while (area->ocupado){
        cout<<"MutexBegin: ocupado="<<boolalpha<<area->ocupado<<endl;
        cout<<"Sigo?"<<endl;
        cin>>sigue;
    }
    cout<<"MutexBegin: a punto de cambiar ocupado "<<boolalpha<<area->ocupado<<endl;
    cout<<"Sigo?"<<endl;
    cin>>sigue;
    area->ocupado=true;
    cout<<"MutexBegin: entra en seccion critica, ocupado="
            <<boolalpha<<area->ocupado<<endl;        
}

void mutexend(AreaMutex * area,int yo){
    area->ocupado=false;
    cout<<"MutexEnd: sale de seccion critica, ocupado="
            <<boolalpha<<area->ocupado<<endl;  
}
#endif
