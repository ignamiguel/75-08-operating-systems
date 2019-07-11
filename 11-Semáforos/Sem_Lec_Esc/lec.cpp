/* Lectores escritores con semaforos -- LECTORES */

#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
typedef struct{  
	int lec=0;
	} shar;

int main(int argc, char * argv[]){
  if (argc<2){
    cerr<<"Uso"<<argv[0]<<" <id de lector>"<<endl;
        exit(2);
    }
  string nom="Lector"+string(argv[1]);
  string rta;
  sv_sem mutex("Mutex");
  sv_sem entra("Entra");
  shar * sh; 
  sv_shm area("Area");
  sh= reinterpret_cast<shar *> (area.map(sizeof (shar)));

  cout<<nom<<" "<<getpid()<<" a punto de ingresar ..."<<endl;
  cin>>rta;
  cout<<nom<<" "<<getpid()<<" prueba ingreso \n";		 
  mutex.wait();
	if (++sh->lec == 1)entra.wait(); //el primero verifica si hay wtr adentro
						// si quedo bloqueado, el resto de los lectores 
            // tambien se quedan en el mutex.wait()
  mutex.post();
		                /* Operacion_de_lectura*/
   cout<<nom<<" "<<getpid()<<" leyendo..."<<endl;
	 cin>>rta;
  mutex.wait();	
		if (--sh->lec == 0){
        cout<<nom<<" "<<" es el ultimo lector "<<endl;
        entra.post(); //el ultimo abre la puerta
      }
  mutex.post();
  cout<<nom<<" "<<" termina."<<endl;
}
