//Mutex 4
#include "Area_Mutex.h"
#ifndef Mutex_h
#define Mutex_h
using namespace std;

int el_otro(int pn){
    if (pn==1)return 2;
    else return 1;
}

void inicializa(AreaMutex * area, int yo=0){
    area->flag[1]=area->flag[2]=false;
    cout<<boolalpha<<"Inicializado"<<endl;
}

void mutexbegin(AreaMutex * area,int yo){
    string sigue;
    area->flag[yo]=true;
    cout<<"MutexBegin: establecido flag["<<yo<<"]"<<endl;
    cout<<"MutexBegin: flags[1,2]="<<area->flag[1]<<","<<
                                    area->flag[2]<<endl;
    cout<<"Sigo?"<<endl;
    cin>>sigue;
    while (area->flag[el_otro(yo)]){
        cout<<"MutexBegin: flags[1,2]="<<area->flag[1]<<","<<
                                area->flag[2]<<endl;
        cout<<"Sigo?"<<endl;
        cin>>sigue;
    }
    cout<<"MutexBegin: entra en seccion critica, flags[1,2]="
                    <<area->flag[1]<<","<<area->flag[2]<<endl;
}

void mutexend(AreaMutex * area,int yo){
    area->flag[yo]=false;
    cout<<"MutexEnd: sale de seccion critica, flags[1,2]="
                    <<area->flag[1]<<","<<area->flag[2]<<endl;
}
#endif
