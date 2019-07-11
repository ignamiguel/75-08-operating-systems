//                    thread/thr1.cc
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

// En Linux, este codigo indica que cada thread es en
// realidad un proceso separado (esta implementado con clone)
// en Kernel 2.4 los pid son distintos, en Kernel 2.6 son
// iguales
// compilar con -lpthread.

void *func(void *arg){
  cout <<"soy la thread pthread_self()->"<<pthread_self();
  cout <<" pertenezco al proceso getpid() "<<getpid()<<endl;
  sleep (10);
  return NULL;
}
int main(){
  pthread_t t;
  cout << "Soy el proceso principal getpid()->"<<getpid();
  cout <<" y mi thread es  pthread_self()->"
    <<pthread_self()<<endl;
  pthread_create(&t,NULL,func,NULL);
  pthread_join(t,NULL);
}
