/*         sali.cc   */
#include<unistd.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void chau(){
  cout <<endl<<"*****Adios, me voy*****"<<getpid()<<endl;
}

int main(){
  cout <<"hola, yo soy "<<getpid()<<endl;
  if (atexit (chau)<0)
	{perror(" No pude regstrar chau");exit(1);}
}
