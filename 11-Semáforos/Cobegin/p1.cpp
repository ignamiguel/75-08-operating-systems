#include "../Sem-sv/sv_sem.h"
#include <iostream>
using namespace std;
// P1

int main(){
	string a;
	sv_sem sp1 ("s1",0);
  	cout<<"P1 arranca"<<endl;
  	cout<<"P1 Ejecutando, un string para continuar..."<<endl;
	cin>>a;
  	sp1.post();
  	cout<<"P1 terminado."<<endl;
}
