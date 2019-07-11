#include <iostream>
#include <cstdlib>
using namespace std;
#include "InsEsp.h"
#include "../Sem-sv/sv_shm.h"

int main(int argc, char *argv[]) {
    if (argc<2){
        cerr<<"Uso"<<argv[0]<<" <nro de proceso>"<<endl;
        exit(2);
    }
    int pn=stoi(argv[1]);
    sv_shm aInsEsp ("aInsEsp");
    void * ptr;
    AreaInsEsp * area;
    int len=sizeof(AreaInsEsp);
    ptr=aInsEsp.map(len);
    area=reinterpret_cast<AreaInsEsp *> (ptr);
    
    string sigue;
    cout<<"P"<<pn<<" a punto de ingresar al MutexBegin"<<endl<<"?"<<endl;
    cin>>sigue;
    mutexbegin (area);
        cout<<"P"<<pn<<" en la seccion critica"<<endl<<"?"<<endl;
        cin>>sigue;
    mutexend(area);
    cout<<"P"<<pn<<" termina"<<endl;
}
        
