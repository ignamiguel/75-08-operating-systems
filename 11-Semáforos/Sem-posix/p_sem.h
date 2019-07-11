#include "includes.h"
#ifndef SEM_H
#define SEM_H
class p_sem{
  string clave;
  sem_t *sem;
  public:
    p_sem(string cla="/default",int ini=1);
    void del();
    string getnom() {return clave;}
    sem_t* getsem()  {return sem;}
    void post();
    void wait();
    friend ostream& operator <<(ostream& os, p_sem sem);
 };

p_sem::p_sem(string cla,int ini){
  char * nom;
  if (cla[0] != '/') cla='/'+cla;
  clave=cla;
  sem=sem_open(clave.c_str(),O_RDWR|O_CREAT,S_IREAD|S_IWRITE,ini); //permits 0600
  if (sem==SEM_FAILED){
		perror ("no se puede abrir/crear el semaforo");
		cerr<<"Semaforo <"<<clave<<"> "<<endl;
		exit(1);}
}

void p_sem::del(){
  int retcode;
  retcode=sem_close (sem);
    if (retcode==-1){
 		perror ("No se puede cerrar el semaforo");
		cerr<<"Semaforo<"<<clave<<"> "<<endl; 
 		exit(1);}
  retcode=sem_unlink(clave.c_str());
  if (retcode==-1){
		perror ("no se puede borrar al semaforo");
		cerr<<"Cola<"<<clave<<"> "<<endl; 
		exit(1);}
}

void p_sem::post(){
  int retcode;
  retcode=sem_post(sem);
  if (retcode==-1){
 		perror ("No se puede hacer post al semaforo");
		cerr<<"Semaforo<"<<clave<<"> "<<endl; 
 		exit(1);}
}

void p_sem::wait(){
  int retcode;
  retcode=sem_wait(sem);
  if (retcode==-1){
 		perror ("No se puede hacer wait en el semaforo");
		cerr<<"Semaforo<"<<clave<<"> "<<endl; 
 		exit(1);}
}

ostream& operator <<(ostream& os, p_sem sem){
  int valor, retcode;
  retcode=sem_getvalue(sem.sem, &valor);
   if (retcode==-1){
 		perror ("No se puede obtener el valor del semaforo");
		cerr<<"Semaforo<"<<sem.clave<<"> "<<endl; 
 		exit(1);}
  return os<<"Semaforo "<<sem.clave<<"("<<valor<<")";
}

#endif
