#include<iostream.h>
#include<string.h>

class bilant
{
	double bil_crt;
	char nume[80];
public:
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
	p=new bilant;
	if(!p)
	{
		cout<<"erreur de affecte la memoire\n";
		exit(1);
	}
	p->pune(12387.87,"Ralph Wilson");
	p->ia_bil(n,s);
	cout<<s<<" a le bilan: "<<n<<"\n";
	delete p;
}