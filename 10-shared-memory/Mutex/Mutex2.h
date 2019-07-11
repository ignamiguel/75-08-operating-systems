//Mutex 2
#include "Area_Mutex.h"
#ifndef Mutex_h
#define Mutex_h
using namespace std;

int el_otro(int pn){
    if (pn==1)return 2;
    else return 1;
}

void inicializa(AreaMutex * area, int pn){
    area->turno=pn;
    cout<<boolalpha<<"Inicializado"<<endl;
}

void mutexbegin(AreaMutex * area, int pn){
    string sigue;
    while (area->turno!=pn){
        cout<<"MutexBegin: turno="<<area->turno<<endl;
        cout<<"Sigo?"<<endl;
        cin>>sigue;
    }
    cout<<"MutexBegin: entra en seccion critica, turno="
            <<area->turno<<endl;        
}



void mutexend(AreaMutex * area, int pn){
    area->turno=el_otro(pn);
    cout<<"MutexEnd: sale de seccion critica, turno="
            <<area->turno<<endl;  
}
#endif
