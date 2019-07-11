/*            fork02.cc  */
#include<unistd.h>
#include<iostream>
#include<sys/wait.h>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main ()
/* ver los pid's que genera un fork, con un padre que espera */
/* espera con wait por el primer hijo que termine y el uso de las macros */
{
	int pidhijo, status;
	printf ("\n\n");
	printf ("El PADRE antes del fork: pid=%d, group pid=%d\n",
			getpid(), getpgrp());
	if ( (pidhijo = fork () ) == -1) 
	{
		perror("no se puede hacer el fork");
		exit(1);
	}
	else if (pidhijo == 0)
		{	/* es el proceso del hijo */
			printf ("\n---> Es el HIJO con pid = %d, cuyo padre es pid = %d\n", getpid(), getppid());
			printf ("     El group pid del hijo es = %d\n", getpgrp());
			exit(0);
		}
		else
		{	/* es el proceso del padre */
			printf ("\nEs el PADRE con pid = %d, y su hijo es pid = %d\n", getpid(), pidhijo);
			if (wait(&status) != pidhijo) 
				perror("error en el wait ");
			if (WIFEXITED(status))
				printf ("termino bien, estado = %d\n", WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
					printf ("termino mal, nro.senial = %d\n", WTERMSIG(status));
				 else if (WIFSTOPPED(status))
				 	printf ("hijo parado, nro senial = %d\n", WSTOPSIG(status));	
			exit(0);
		}
}
