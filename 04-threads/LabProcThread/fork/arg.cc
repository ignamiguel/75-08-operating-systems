//                 arg.cc
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
using namespace std; 

int main (int argc, char *argp[])
/*    Lista los argumentos */
{
	cout<<endl<<"Proceso nro "<<getpid()<<endl;
    for (int i=0; argp[i] != NULL; i++)
	    cout <<"a "<<i<<")"<< argp[i]<<endl;
/* acceso al ambiente como variable externa  */
    extern char **environ;
    for (int i=0; environ[i] != NULL; i++)
        cout <<"e "<<i<<")"<< environ[i]<<endl;	
    exit (0);
}
