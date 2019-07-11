//                   envir.cc
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main (int argc, char * argv[], char * envp[])
/* ver los argumentos del comando y las variables de ambiente */
{
	/* ver los argumentos   */
	for (int i = 0; i < argc; i++)
	    cout<< "argv["<<i<<"]="<<argv[i]<<endl;
	/* ver las variables del ambiente */    
	for (int i = 0; envp[i] != NULL; i++)
		cout<<"envp["<<i<<"]="<< envp[i]<<endl;
	exit(0);
}

