#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
using namespace std;

int main(int argc, char * argv[]){
  if (argc < 4) {
      cerr<<"Uso: "<<argv[0]<<" papel tabaco fosforos"<<endl;
      exit(2);
  }
  string p=argv[1], t=argv[2], f=argv[3]; 
  string entrada;
  int ip=atoi(p.c_str());
  int it=atoi(t.c_str());
  int ifo=atoi(f.c_str());
  cout<<"Agente pone "<<ip<<" papel, "<<it<<" tabaco y "
      <<ifo<<" fosforos."<<endl;
      
  sv_sem papel("papel",0);
  sv_sem tabaco("tabaco",0);
  sv_sem fosforos("fosforos",0);
  
  for (int i=0; i<ip; i++) papel.post();
  for (int i=0; i<it; i++) tabaco.post();
  for (int i=0; i<ifo; i++) fosforos.post();

}