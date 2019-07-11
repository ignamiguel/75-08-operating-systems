#include "../Sem-sv/sv_sem.h"
#include <iostream>
using namespace std;

int main(){
	sv_sem sp1 ("s1",0);
	sv_sem sp2 ("s2",0);
	cout<<" Inicializados:"<<endl;
	cout<<"s1 "<<sp1<<"s2 "<<sp2<<endl;
}
