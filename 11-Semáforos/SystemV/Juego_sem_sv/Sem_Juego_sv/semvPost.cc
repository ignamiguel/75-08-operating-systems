#include "includes.h"
using namespace std;

int main(int argc, char * argv[]){
  if (argc <2){
    cerr<<"Uso: "<<argv[0]
      <<" <nombre semaforo>"<<endl;
    exit(1);
  }
   sv_sem s (argv[1],0);
   s.post();
  cout<<"post del semaforo "<<s<<endl;
}