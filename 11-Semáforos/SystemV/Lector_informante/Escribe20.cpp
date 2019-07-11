#include <iostream>
#include <cstdlib>
#include "dat.h"
#include "../Sem-posix/p_shm.h"


using namespace std;
int main(int argc, char *argv[]) {
    if (argc<2){
        cerr<<"Uso"<<argv[0]<<" <tiempo de sleep(seg)"<<endl;
        exit(2);
    }
    int siesta=stoi(argv[1]);
    p_shm Area51 ("Area51");
    void * ptr;
    dat * area;
    int len=sizeof(dat);
    int total=0;
    ptr=Area51.map(len);
    area=reinterpret_cast<dat *> (ptr);
    for (int i=0;i<20;i++){
        sleep(siesta);
        area->val=area->val+i;
        total=total+i;
        cout<<"Val="<<area->val<<" Total="<<total<<endl;
    }
    sleep(1);
    
    area->ultimo=true;
    cout<<"Enviados datos por un total de "<<total<<endl;
}