//clase pentru diverse cozi
#ifndef load_struct
#include<structura.h>
#endif
//clasa pentru coada statica vazuta ca un vector circular care se aloca dinamic
//la fiecare initializare
class coada_statica
{
	int MAX;
	structura **data;
	int out,in;
public:
	coada_statica(int inp=0,int outp=0,int vector=20){in=inp;out=outp;MAX=vector; data=new structura *[MAX];}
	int introduce(struct structura *input);
	struct structura *scoate(void);
};
int coada_statica::introduce(struct structura *input)
{
	if((in+1==out) || ((in+1==MAX) && (out!=0))) 
	{
		cout<<"Coada plina\n";
		return 0;
	}
	data[in]=input;
	in++;
	if(in==MAX) in=0;
	return 1;
}

struct structura *coada_statica::scoate(void)
{
	if(out==MAX) out=0;
	structura *temporar;
	temporar=data[out];
	if(out==in) {cout<<"Coada goala\n";return NULL;}
	out++;
	return temporar;
}


//clasa pentru coada dinamica (alocata sub forma de structura simplu inlantuita
class coada_dinamica
{
	class element
	{
	public:
		struct structura *data;
		element *next;
		element(structura *input){data=input;next=NULL;}
	};
	element *primul;
	element *temporar;
public:
	coada_dinamica(void){primul=NULL;temporar=NULL;}
	int introduce(struct structura *input);
	struct structura *scoate(void);
};
int coada_dinamica::introduce(struct structura *input)
{
	if(primul==NULL) 
	{
		primul=new class element(input);
		return 1;
	}
	temporar=primul;
	while(temporar->next!=NULL)
	{
		temporar=temporar->next;
	}
	temporar->next=new class element(input);
	return 1;
}
struct structura *coada_dinamica::scoate(void)
{
	structura *struct_temporar;
	if(primul==NULL)
	{
		cout<<"Coada este goala\n";
		return NULL;
	}
	struct_temporar=primul->data;
	temporar=primul;
	primul=primul->next;
	delete temporar;
	return struct_temporar;
}