#include "includes.h"
using namespace std;

int main(int argc, char * argv[]){
	if (argc <2){
		cerr<<"Uso: "<<argv[0]
			<<" <nombre area de memoria>"<<endl;
		exit(1);
	}
	sv_shm s (argv[1]);
	cerr <<"Creada el area "<<argv[1]
		<<" con clave 0x"<<s<<endl;
}
