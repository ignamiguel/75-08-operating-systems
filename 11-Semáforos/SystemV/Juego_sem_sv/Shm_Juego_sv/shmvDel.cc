#include "includes.h"
using namespace std;

int main(int argc, char * argv[]){
  if (argc <2){
    cerr<<"Uso: "<<argv[0]
      <<" <nombre area>"<<endl;
    exit(1);
  }
   sv_shm s (argv[1]);
   cout<<"Borrada el area "<<s<<endl;
   s.del();
  
}