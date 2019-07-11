#include "includes.h"
#include "../Sem-sv/sv_sem.h"


using namespace std;
int main(int argc, char *argv[]) {
	sv_sem prod("A51p",5);
	sv_sem cons("A51c",0);
	sv_sem mutex("A51m",1);
	cout<<"Inicializados A51p A51c A51m"<<endl;
}