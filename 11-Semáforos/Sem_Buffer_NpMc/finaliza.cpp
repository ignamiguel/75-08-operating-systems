#include "includes.h"
#include "Area.h"
#include "../Sem-sv/sv_shm.h"
#include "../Sem-sv/sv_sem.h"

int main(int argc, char * argv[]){
	sv_shm a51("Area51");
		sv_sem cons("A51c");
	Area * a;
	a= static_cast <Area*>(a51.map(sizeof(Area)));
	a->setFin();
	cons.post();
	cout<<"Marcado el Fin"<<endl;
}