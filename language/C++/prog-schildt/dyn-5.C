#include<iostream.h>
#include<string.h>

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
	~bilant()
	{
		cout<<"Destructor ";
		cout<<nume<<"\n";
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
	p=new bilant(12387.87,"Ralph Wilson");
	if(!p)
	{
		cout<<"erreur de affecte la memoire\n";
		exit(1);
	}
	p->ia_bil(n,s);
	cout<<s<<" a le bilan: "<<n<<"\n";
	delete p;
}