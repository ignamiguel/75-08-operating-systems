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

int izq(int x){
	int r=x-1;
	if (r==-1) r=4;
	return r;
}

int der(int x){
	int r=x+1;
	if (r==5) r=0;
	return r;
}


#endif