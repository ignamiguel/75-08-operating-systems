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
	int i=1;
	area->val=0;
	int acum=0;
	while (i<30){
		area->ser=i;
		area->val+=i*10;
		acum+=i*10;
		cout<<"Vuelta "<<i<<" parcial " <<area->val<<" sumados "<<acum<<endl;
		i++;
		sleep(3);
	}
	cout << "Grabados "<<i-1<<" datos con un acumulado de "<<acum<<endl;
}
