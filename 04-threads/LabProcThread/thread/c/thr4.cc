//                    thread/thr4.cc
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

// En Linux, forma "civilizada" de compartir variables 
// (sin globales pero con un show de * y &)
// No soluciona el problema de acceso simultaneo (ver clases de exclusion mutua)
// compilar con -lpthread.


void *func(void *arg){
  int * par_p=(int * )arg;
  for (int i=0; i<10;i++) (*par_p)++;
  cout<<"Thread "<<pthread_self()<<", par_p "<<par_p
	<<", (*par_p) "<<(*par_p)<<endl;
  return NULL;
}
int main(){
  pthread_t th1,th2;
  int variable;
  variable=0;
  pthread_create(&th1,NULL,func,(void *)&variable);
  pthread_create(&th2,NULL,func,(void *)&variable);
  for(int i=0;i<10;i++)
	variable++;
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);	
  cout<<"variable vale "<<variable<<", &variable "<<&variable<<endl;
}
