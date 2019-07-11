#ifndef Area_h
#define Area_h

enum est {pen,ham,com};

class Area{	
	est estado[5]={pen,pen,pen,pen,pen};
public:
	Area(){};
	est getEst(int i){return estado[i];}
	void setEst (int i, est e){estado[i]=e;}
};

#endif