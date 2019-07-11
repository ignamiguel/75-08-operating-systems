//                  hacezombie.cc
#include<unistd.h>
#include<iostream>
#include<sys/wait.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
	pid_t hijo;
  switch (hijo=fork()) {
		case -1: {
			cout << "Error al lanzar el proceso ";
			exit(3);
		}
		case 0: { // hijo
			cout << "El hijo pid nro "<<getpid()<<" muere"<<endl;
			exit (0);
		}
		default: { // padre
			cout << "El padre pid nro "<<getpid()<<" duerme un poco"<<endl;
			sleep (5);
			cout << "El padre pid nro hace un ps"<<endl;
			system ("ps -o pid,ppid,args,stat");
			cout << endl;
			exit(0);
		}
	}
}
