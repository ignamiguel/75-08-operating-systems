
#include "includes.h"
using namespace std;

int main(int argc, char * argv[]){
	if (argc <3){
		cerr<<"Uso: "<<argv[0]
			<<" <area de memoria> <string a escribir>"<<endl;
		exit(1);
	}
	Mensaje * msj;
	sv_shm area (argv[1]);
	msj=reinterpret_cast<Mensaje *>(area.map(sizeof (Mensaje)));
	msj->setDato(argv[2]);
	cerr<<"Escrito en el area "<<area<<" el mensaje <"<<(*msj)<<" >"<<endl;
}
		

