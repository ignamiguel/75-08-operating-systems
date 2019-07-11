#include <iostream>
#include <unistd.h>
#include "../Sem-posix/p_shm.h"
#include "../Sem-posix/p_sem.h"
#define CAP 3
/* Cliente */

using namespace std;
int main(int argc, char *argv[]) {
	int * en_espera,yo;
	yo=getpid();
	p_shm sillas_ocup("Sillas");
	en_espera=static_cast<int *>	(sillas_ocup.map(sizeof (int)));
	p_sem mutex("Mutex",1);
	p_sem figaro("Barbero",0);
	p_sem cliente ("Cliente",0);
	p_sem salida ("Salida",0);
	string rta;
	
	cout<<"Cliente "<<yo<<" quiere afeitarse"<<endl;
	mutex.wait();
	if ((*en_espera)<3){
		*en_espera=(*en_espera)+1;
		cliente.post();
		mutex.post();
		cout<<"Cliente "<<yo<<" esperando barbero. Posicion "<<(*en_espera)<<endl;
		figaro.wait();
		cout<<" Afeitandose ... "<<endl;
		salida.wait();
		cout<<"Adios"<<endl;
     }
	else {
		cout<<"No hay lugar."<<endl;
		mutex.post();
	}
}	
