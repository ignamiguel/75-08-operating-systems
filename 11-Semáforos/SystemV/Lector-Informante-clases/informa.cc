// linkeditar con LOADLIBES=-lrt
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "../Sem-posix/p_shm.h"
using namespace std;

int main (){
/* escribe una medición sobre un area compartida */
	int retcode;
	typedef  struct {
		int ser;
		int val;}dat;
	void * ptr;
	int len=sizeof(dat);
	dat * area;
	const char * nom="Area51";
	p_shm Area51 ("Area51");
	ptr=Area51.map(len);
	area=reinterpret_cast<dat *> (ptr);
	int acum=0;
	int ant=0;
	int total=0;
	int lect;
	while (true){
		acum=area->val;
		if (ant==acum) break;
		lect=area->ser;
		total+=acum;
		ant=acum;
		cout <<"Leido hasta la actualización "<<lect<<" con un parcial de "<<acum<<endl;
		sleep(2);
		area->val=0;
		sleep(5);
	}
	cout<<"Ultima actualizacion "<<lect<<" total leido "<<total<<endl;
	Area51.del();
}
