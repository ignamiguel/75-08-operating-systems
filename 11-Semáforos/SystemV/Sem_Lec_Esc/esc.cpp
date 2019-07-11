/*  escritor   */

#include "../Sem-posix/p_sem.h"

int main (){
	p_sem entra("Entra",1);
	cout <<"Escritor "<<getpid()<<" prueba ingreso"<<endl;
	entra.wait();
		cout<<"Escritor "<<getpid()
			<<" adentro, ingrese un caracter para salir"<<endl;
		cin.get();
	entra.post();
}
