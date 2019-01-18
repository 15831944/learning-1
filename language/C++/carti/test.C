#include<iostream.h>
#include<fstream.h>
#include<structura.h>
#include<coada.h>
#include<stiva.h>
int main()
{
	int in1=10,t1;
	char temp[10]="Cristina";
	char temp1[10]="Diana";
	char *in2,*in3,*t2;
	in2=temp;
	in3=temp1;
	structura *test1,*test11,*coada_temporara;
	test1=new structura;
	test1->initializare(in1,in2);
	test11=new structura;
	test11->initializare(in1,in3);
	coada_statica test2(0,0,10);
	test2.introduce(test1);
	test2.introduce(test11);
	coada_temporara=test2.scoate();
	if(coada_temporara==NULL) exit(1);
	cout<<coada_temporara->intreg<<" "<<coada_temporara->nume<<"\n";
	coada_temporara=test2.scoate();
	if(coada_temporara==NULL) exit(1);
	cout<<coada_temporara->intreg<<" "<<coada_temporara->nume<<"\n";
	coada_dinamica test3;
	test3.introduce(test1);
	test3.introduce(test11);
	cout<<"Coada dinamica\n";
	coada_temporara=test3.scoate();
	while(coada_temporara!=NULL)
	{
		cout<<coada_temporara->intreg<<" "<<coada_temporara->nume<<"\n";
		coada_temporara=test3.scoate();
	}
	cout<<"Stiva statica\n";
	stiva_statica test4;
	test4.introduce(test1);
	test4.introduce(test11);
	coada_temporara=test4.scoate();
	cout<<coada_temporara->intreg<<" "<<coada_temporara->nume<<"\n";
	coada_temporara=test4.scoate();
	cout<<coada_temporara->intreg<<" "<<coada_temporara->nume<<"\n";
}