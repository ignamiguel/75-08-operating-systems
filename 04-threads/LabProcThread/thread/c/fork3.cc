//                    thread/fork3.cc
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

// En Linux, version con fork del programa thr3
// con globales y algo de debug
// Las direcciones impresas son las mismas (porque?)

int variable_compartida;

void func(){
  extern int variable_compartida;
  for (int i=0; i<10;i++) 
	variable_compartida++;
  cout<<"Proceso "<<getpid()<<", variable_compartida "
	<<variable_compartida<<", &variable_compartida "
	<<&variable_compartida<<endl;
}
int main(){
  extern int variable_compartida;
  pid_t p1,p2;
  int status;
  variable_compartida=0;
  if ((p1=fork())==0) {func();exit(0);};
  if ((p2=fork())==0) {func();exit(0);};
  for(int i=0;i<10;i++)
	variable_compartida++;
  waitpid(p1,&status,0);
  waitpid(p2,&status,0);;	
  cout<<"variable_compartida vale "<<variable_compartida<<endl;
  cout<<"Proceso "<<getpid()<<", variable_compartida "
	<<variable_compartida<<", &variable_compartida "
	<<&variable_compartida<<endl;
}
