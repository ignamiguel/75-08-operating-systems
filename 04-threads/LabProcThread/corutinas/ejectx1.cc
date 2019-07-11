#include <ucontext.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
using namespace std;
#define FALSE 0
#define die(msg) do{ perror(msg); exit(EXIT_FAILURE);} while (FALSE)

static ucontext_t cont1,contmain;
static int conta1,conta2;

void proc1(void){
	int   localproc=1;   //esta variable no forma parte del contexto, no conserva su valor
	cout <<"Comienza proc1"<<endl;
	
	if (getcontext(&cont1)==-1) die ("Al tomar el contexto de proc1");
	cout<< "proc1 van "<<conta1++<<" proceso "<<getpid()<<
	" Variable local proc1="<<localproc<<endl;
	if (conta1==3) exit (EXIT_SUCCESS);
	if (setcontext(&contmain) == -1)die("stcontext main");
	cout<< "proc1 termina "<<conta1<<endl;
}

int main(){
	cout <<"Main comienza"<<endl;
	conta1=0;
	conta2=0;
	int   localmain=1;
	
	
	if (getcontext(&contmain)==-1) die ("Al tomar el contexto de main");
	if (conta1>0) localmain+=100;
	cout <<"Main pasada "<<conta2<<" proceso "<<getpid()<<
	" Variable local main="<<localmain<< endl;
	if (conta2++==0)proc1(); // la primer vez lo llama
	if (conta2==3){
		cout << "Main termina"<<endl;
		exit (EXIT_SUCCESS);
	}
	if (setcontext(&cont1) == -1)die("stcontext proc1");
	cout<< "main termina "<<conta2<<endl;
}
