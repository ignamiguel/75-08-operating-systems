#include "../Sem-sv/sv_sem.h"
#include <iostream>
using namespace std;

// P3

int main(){
  string a;
  sv_sem sp1 ("s1");
  sv_sem sp2 ("s2");

  cout<<"P3 arranca"<<endl;
  cout<<"Esperando a P1 "<<endl;
  sp1.wait();
  cout<<"Esperando a P2 "<<endl;
  sp2.wait();
  cout<<"P3 Ejecutando, un string para continuar..."<<endl;
  cin>>a;
  cout<<"P3 terminado."<<endl;
}
