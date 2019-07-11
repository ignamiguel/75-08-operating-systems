#include <unistd.h>
#include "../Sem-posix/p_shm.h"
#include "../Sem-posix/p_sem.h"
/* libera */

using namespace std;
int main(int argc, char *argv[]) {
	p_shm sillas_ocup("Sillas");
	sillas_ocup.del();
	p_sem mutex("Mutex",1);
	mutex.del();
	p_sem figaro("Barbero",0);
	figaro.del();
	p_sem cliente ("Cliente",0);
	cliente.del();
	p_sem salida ("Salida",0);
	salida.del();
}
	
