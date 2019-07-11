/* Lectores escritores con semaforos -- LECTORES */

#include "../Sem-posix/p_sem.h"
#include "../Sem-posix/p_shm.h"
typedef struct{  
	int lec=0;
	} shar;

int main (){
  p_sem mutex("Mutex",1);
  p_sem entra("Entra",1);
  shar * sh; 
  p_shm area("Area");
  sh= reinterpret_cast<shar *> (area.map(sizeof (shar)));
  cout<<"Lector "<<getpid()<<" prueba ingreso \n";		 
  mutex.wait();
	if (++sh->lec == 1)entra.wait(); //el primero cierra la entrada a wtr
						// el resto de los lectores queda en el mutex.wait()
  mutex.post();

		/* Operacion_de_lectura*/
   cout<<"Lector "<<getpid()<<" leyendo,  ingrese un caracter para salir\n";
		cin.get();
  mutex.wait();	
		if (--sh->lec == 0)entra.post(); //el ultimo abre la puerta
  mutex.post();
}
