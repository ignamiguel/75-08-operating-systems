#include <iostream>
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
using namespace std;

int main(int argc, char * argv[]){
  if (argc < 2) {
      cerr<<"Uso: "<<argv[0]<<" nombre del fumador"<<endl;
      exit(2);
  }
  string nom=argv[1]; 
  string entrada;
  sv_sem papel("papel",0);
  sv_sem tabaco("tabaco",0);
  sv_sem fosforos("fosforos",0);
  cout<<"Fumador "<<nom<<" listo para fumar ..."<<endl;
  cin>>entrada;
  cout<<"Fumador "<<nom<<" busca papel "<<endl;
  papel.wait();
  cout<<"Fumador "<<nom<<" tiene papel, busca tabaco "<<endl;
  tabaco.wait();
  cout<<"Fumador "<<nom<<" tiene papel, busca Fosforos "<<endl;
  fosforos.wait();
  cout<<"Fumador "<<nom<<" fumando ..."<<endl;
  cin>>entrada;
  cout<<"Fumador "<<nom<<" se va"<<endl;
}