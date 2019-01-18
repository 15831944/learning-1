#include<iostream.h>
#include<string.h>

struct sirulmeu
{
	void facesir(char *s);//public
	void aratasir();
private:	//dans ce moment c'est particulaire
	char sir[255];
};

void sirulmeu::facesir(char *s)
{
	if(!*s) *sir='\0';	//initialize le serie
	else strcat(sir,s);
}
void sirulmeu::aratasir()
{
	cout<<sir<<"\n";
}
int main()
{
	sirulmeu s;
	
	s.facesir("");//initialize
	s.facesir("Va ");
	s.facesir("salut!");	
	s.aratasir();
}
