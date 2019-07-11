#include <iostream>
#include <cstdlib>
using namespace std;
#include "Mutex.h"
#include "../Sem-sv/sv_shm.h"

int main(int argc, char *argv[]) {
    if (argc<2){
        cerr<<"Uso"<<argv[0]<<" <nro de proceso>"<<endl;
        exit(2);
    }
    int pn=stoi(argv[1]);
    sv_shm aMutex ("Mutex");
    void * ptr;
    AreaMutex * area;
    int len=sizeof(AreaMutex);
    ptr=aMutex.map(len);
    area=reinterpret_cast<AreaMutex *> (ptr);
    
    string sigue;
    cout<<"P"<<pn<<" a punto de ingresar al MutexBegin"<<endl<<"?"<<endl;
    cin>>sigue;
    mutexbegin (area,pn);
        cout<<"P"<<pn<<" en la seccion critica"<<endl<<"?"<<endl;
        cin>>sigue;
    mutexend(area,pn);
    cout<<"P"<<pn<<" termina"<<endl;
}
        
