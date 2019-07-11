#ifndef Mensaje_h
#define Mensaje_h
class Mensaje{
	char dato [40];
	public:
		Mensaje() {
			strcpy (dato,"");
			}
		Mensaje(std::string d) {
			strcpy (dato,d.c_str());
			}
		Mensaje (const Mensaje & m){
			strcpy(dato,m.dato);
			}
		std::string getDato(){return dato;};
		void setDato(std::string d,bool sen=false){
		  strcpy (dato,d.c_str());
		}
		
			
		friend std::ostream& operator<<(std::ostream& os, Mensaje m){
			return os<<m.getDato();
			} 
};
#endif
