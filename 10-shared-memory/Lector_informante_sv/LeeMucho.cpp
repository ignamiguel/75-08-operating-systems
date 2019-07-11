#include <iostream>
#include "dat.h"
#include "../Sem-sv/sv_shm.h"


using namespace std;
int main(int argc, char *argv[]) {
    if (argc<2){
        cerr<<"Uso"<<argv[0]<<" <tiempo de sleep(seg)"<<endl;
        exit(2);
    }
    int siesta=stoi(argv[1]);
    sv_shm Area51 ("Area51");
    void * ptr;
    dat * area;
    int len=sizeof(dat);
    ptr=Area51.map(len);
    area=reinterpret_cast<dat *> (ptr);
    int local=0,total=0;
    while (!area->ultimo){
        local=area->val;
        sleep(siesta);
        total=total+local;
        area->val=0;
        sleep (siesta/2);
        cout<<"Leido="<<local<<" Total="<<total<<endl;
    }
    cout<<"Leidos "<<total<<endl;
}