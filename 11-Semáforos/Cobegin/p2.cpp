#include "../Sem-sv/sv_sem.h"
#include <iostream>
using namespace std;

// P2

int main(){
	string a;
	sv_sem sp2 ("s2",0);
	cout<<"P2 arranca"<<endl;
	cout<<"P2 Ejecutando, un string para continuar..."<<endl;
	cin>>a;
	sp2.post();
	cout<<"P2 terminado."<<endl;
}
