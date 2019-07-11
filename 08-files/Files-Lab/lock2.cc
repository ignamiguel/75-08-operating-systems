//
// Idem lock1.exe pero con Share lock
//

#include <sys/file.h> 
#include <iostream>
#include <cstdlib>    // agregado
#include <cstdio>     // agregado

using namespace std;

int main(int argc, char * argv[]){
	if (argc != 2 ){
		cerr<<"uso: "<<argv[0]<<" <archivo>"<<endl;
		exit (1);
	}
	int f =open (argv[1],O_RDONLY|0600);
	if (f==-1){
		perror ("Al abrir el archivo ");
		exit (2);
	}
	flock (f,LOCK_SH);
	cout<<"argv[1]"<<" esta bloqueado, enter para seguir."<<endl;
	cin.get();
	flock(f,LOCK_UN);
	cout<<"argv[1]"<<" esta liberado"<<endl;
}
	
