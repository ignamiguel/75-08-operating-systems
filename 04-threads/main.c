#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
  pid_t yo;
  yo = getpid();
  printf("Yo soy el proceso %d\n",yo);
}
