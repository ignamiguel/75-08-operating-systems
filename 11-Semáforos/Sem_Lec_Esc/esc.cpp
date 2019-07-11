/*  escritor   */

#include "../Sem-sv/sv_sem.h"



int main(int argc, char * argv[]){
	if (argc<2){
		cerr<<"Uso"<<argv[0]<<" <id de escritor>"<<endl;
				exit(2);
	}	
	string nom="Escritor"+string(argv[1]);
	string rta;
	sv_sem entra("Entra");
	cout <<nom<<" "<<getpid()<<" prueba ingreso..."<<endl;
	cin>>rta;
	entra.wait();
		cout<<nom<<" "<<getpid()
			<<" adentro..."<<endl;
		cin>>rta;
	entra.post();
	cout <<nom<<" "<<getpid()<<" termina."<<endl;
}
