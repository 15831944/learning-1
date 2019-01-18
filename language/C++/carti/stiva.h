//clase pentru diverse stive
#ifndef load_struct
#include<structura.h>
#endif

//clasa pentru stiva alocata static
class stiva_statica
{
	struct structura **data;
	int contor;
	int MAX;
public:
	stiva_statica(int adresa=0,int maxim=20)
	{
		MAX=maxim;
		contor=adresa;
		data=new structura *[MAX];
	}
	int introduce(struct structura *input);
	struct structura *scoate(void);
};
int stiva_statica::introduce(struct structura *input)
{
	if(contor+1>MAX)
	{
		cout<<"Stiva este plina\n";
		return 0;
	}
	data[contor]=input;
	contor++;
	return 1;
}
struct structura *stiva_statica::scoate(void)
{
	struct structura *struct_temp;
	if(contor-1<0)
	{
		cout<<"Stiva este plina\n";
		return NULL;
	}
	contor=contor-1;
	return data[contor];
}

//Stiva alocata dinamica sub forma unei liste inlantuite
