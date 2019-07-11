#include "includes.h"
using namespace std;

int main(int argc, char * argv[]){
	if (argc <2){
		cerr<<"Uso: "<<argv[0]
			<<" <area de memoria> "<<endl;
		exit(1);
	}
	Mensaje * msj;
	sv_shm area (argv[1]);
	msj=reinterpret_cast<Mensaje *>(area.map(sizeof (Mensaje)));
	string sali=msj->getDato();
	cout<<"Leido de "<<area<<"<"<<sali<<">"<<endl;	
}	