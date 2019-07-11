#include "includes.h"
#ifndef SHM_H
#define SHM_H
#define BUFSIZE 8192

class p_shm{
  string clave; 
  int shm;
  public:
    p_shm(string cla="/default");
    void del();
    int getShm(){return shm;}
    void * map(int size=BUFSIZE);
    string getClave(){return clave;}
friend ostream& operator <<(ostream& os, p_shm shm);
};
p_shm::p_shm(string cla){
  char * nom;
  if (cla[0] != '/') cla='/'+cla;
  clave=cla;
  shm=shm_open(clave.c_str(),O_RDWR|O_CREAT,S_IREAD|S_IWRITE); //permits 0600
  if (shm==-1){
		perror ("no se puede abrir/crear la shared memory");
		cerr<<"Clave <"<<clave<<"> "<<endl;
		exit(1);}
}

void p_shm::del(){
  int retcode;
  retcode=shm_unlink(clave.c_str());
  if (retcode==-1){
		perror ("no se puede borrar la shared memory");
		cerr<<"Clave<"<<clave<<"> "<<endl; 
		exit(1);}
}

ostream& operator <<(ostream& os, p_shm shm){
  int retcode;
  struct stat valor;
  retcode=fstat(shm.shm, &valor);
   if (retcode==-1){
 		perror ("No se puede hacer fstat() al area ");
		cerr<<"Clave<"<<shm.clave<<"> "<<endl; 
 		exit(1);}
  return os<<"Shm <"<<shm.clave<<">("<<valor.st_size<<")";
}

void * p_shm::map(int size){
	ftruncate(shm,size);
	return(
		mmap (NULL,size,PROT_READ|PROT_WRITE,MAP_SHARED,shm,0));
}

#endif
