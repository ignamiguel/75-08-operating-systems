//                    thread/thr2.cc
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

// En Linux, a pesar de que cada thread es un proceso separado 
// se ve que comparte memoria
// compilar con -lpthread.

int variable_compartida;

void *func(void *arg){
  extern int variable_compartida;
  for (int i=0; i<10;i++) 
	variable_compartida++;
  return NULL;
}
int main(){
  pthread_t th1,th2;
  extern int variable_compartida;
  variable_compartida=0;
  pthread_create(&th1,NULL,func,NULL);
  pthread_create(&th2,NULL,func,NULL);
  for(int i=0;i<10;i++)
	variable_compartida++;
  pthread_join(th1,NULL);
  pthread_join(th2,NULL);	
  cout<<"variable_compartida vale "<<variable_compartida<<endl;
}
