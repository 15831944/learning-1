#include<iostream.h>
#include<string.h>

class angajat
{
	char nume[80];
public:
	void punenume(char *n);
	void ianume(char *n);
private:
	double plata;
public:
	void puneplata(double w);
	double iaplata();
};

void angajat::punenume(char *n)
{
	strcpy(nume,n);
}
void angajat::ianume(char *n)
{
	strcpy(n,nume);
}
void angajat::puneplata(double w)
{
	plata=w;
}
double angajat::iaplata()
{
	return plata;
}

int main()
{
	angajat teo;
	char nume[80];
	
	teo.punenume("Teo Ionescu");
	teo.puneplata(75000);
	teo.ianume(nume);
	
	cout<<nume<<" are $";
	cout<<teo.iaplata()<<" pe an.\n";
}