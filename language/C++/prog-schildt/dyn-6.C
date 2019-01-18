#include<iostream.h>
#include<string.h>
#include<stdio.h>

class bilant
{
	double bil_crt;
	char nume[80];
public:
	bilant(double n,char *s)
	{
		bil_crt=n;
		strcpy(nume,s);
	}
	bilant(){}//contructeur sans parametres
	~bilant()
	{
		cout<<"Destructeur "<<nume<<"\n";
	}
	void pune(double n,char *s)
	{
		bil_crt=n;
		strcpy(nume,s);
	}
	void ia_bil(double &n,char *s)
	{
		n=bil_crt;
		strcpy(s,nume);
	}
};
int main()
{
	bilant *p;
	char s[80];
	double n;
	p=new bilant[3];
	if(!p)
	{
		cout<<"erreur de affecte la memoire\n";
		exit(1);
	}
	p[0].pune(12387.87,"Ralph Wilson");
	p[1].pune(144.00,"A.C. Conners");
	p[2].pune(-11.23,"I.S. Falitu");
	for(int i=0;i<3;i++)
	{
		p[i].ia_bil(n,s);
		cout<<s<<" a le bilan: "<<n;
		printf("  %lf \n",n);fflush(stdout);
	}
	delete []p;
}