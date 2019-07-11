
#include "../Sem-sv/sv_sem.h"
#include "../Sem-sv/sv_shm.h"
typedef struct{  
	int lec=0;
	} shar;

int main (){
  sv_sem mutex("Mutex",1);
  sv_sem entra("Entra",1);
  cout<< "Semaforos inicializados."<<endl<<mutex<<endl<<entra<<endl;
  shar * sh; 
  sv_shm area("Area");
  sh= reinterpret_cast<shar *> (area.map(sizeof (shar)));
  sh->lec=0;
  cout<<"Area compartida inicializada."<<sh->lec<<endl;
} 