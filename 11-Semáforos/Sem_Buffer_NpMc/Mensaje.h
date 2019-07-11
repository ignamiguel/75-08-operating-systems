#ifndef Mensaje_h
#define Mensaje_h
using namespace std;
class Mensaje{
	char dato [40];
	public:
		Mensaje() {
			strcpy (dato,"");
			}
		Mensaje(string d) {
			strcpy (dato,d.c_str());
			}
		Mensaje (const Mensaje & m){
			strcpy(dato,m.dato);
			}
		string getDato(){return dato;};
		void setDato(string d){
		  strcpy (dato,d.c_str());
		}
		
		
	
		friend ostream& operator<<(ostream& os, Mensaje m){
			return os<<"("<<m.getDato()<<")";
			} 
};
#endif
