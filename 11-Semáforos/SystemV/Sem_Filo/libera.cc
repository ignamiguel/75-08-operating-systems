#include "includes.h"
#include "Area.h"

int main(int argc, char * argv[]){
 p_sem * filoSem[5];
 for (int  i=0;i<5;i++){
	 filoSem[i]=new p_sem(string("Filo")+to_string(i),0);
   filoSem[i]->del(); 
 }
}