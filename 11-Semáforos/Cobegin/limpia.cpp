#include "../Sem-sv/sv_sem.h"
#include <iostream>
using namespace std;

int main(){
	sv_sem sp1 ("s1");
	sv_sem sp2 ("s2");
	sp1.del();
	sp2.del();
}