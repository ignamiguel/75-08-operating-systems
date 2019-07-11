//                          fork01.cc
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main ()
/* ver los pid's que genera un fork */
{	
    int pidhijo;
    cout<<endl<<"El PADRE antes del fork: pid="<<getpid()<<
	" group pid= "<<getpgrp()<<endl;
    if ( (pidhijo = fork () ) == -1) 
	{perror("no se puede hacer el fork");exit(1);}
	else if (pidhijo 	)
		{/* es el proceso del hijo */
		cout<<endl<< "---> Es el HIJO con pid = "<<getpid()<<
		     " cuyo padre es pid = "<< getppid()<<endl;
		cout<<"     El group pid del hijo es = "<< getpgrp()<<endl;
		exit(0);
		}
	    else
	        {/* es el proceso del padre */
		cout <<endl<< "Es el PADRE con pid = "<<getpid()<<
		    " y su hijo es pid = "<<pidhijo<<endl;
		exit(0);
		}
}

