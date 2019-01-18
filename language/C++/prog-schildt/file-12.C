#include<iostream.h>
#include<fstream.h>
#include<string.h>

class agendatelefon
{
public:
	char nume [80];
	char codzona[4];
	char prefix[4];
	char numar[5];

	agendatelefon() {};
	agendatelefon(char *n,int *a,int *p,int *nm)
	{
		strcpy(nume,n);
		strcpy(codzona,(char *)a);
		strcpy(prefix,(char *)p);
		strcpy(numar,(char *)nm);
	}
	friend ostream &operator<<(ostream &stream,agendatelefon o);
	friend istream &operator>>(istream &stream,agendatelefon &o);
};
ostream &operator<<(ostream &stream,agendatelefon o)
{
	stream<<o.nume<<" ";
	stream<<"("<<o.codzona<<") ";
	stream<<o.prefix<<"-";
	stream<<o.numar<<"\n";
	return stream;
}
istream &operator>>(istream &stream,agendatelefon &o)
{
	cout<<"Introduisez le nom: ";
	stream>>o.nume;
	cout<<"Introduisez codzona: ";
	stream>>o.codzona;
	cout<<"Introduisez le prefix: ";
	stream>>o.prefix;
	cout<<"Introduisez le numero: ";
	stream>>o.numar;
	cout<<"\n";
	return stream;
}
int main()
{
	agendatelefon a;
	char c;
	fstream at("telefon",ios::in | ios::out | ios::app);
	if(!at)
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	for(;;)
	{
		do
		{
			cout<<"1. Introduisez les numeros\n";
			cout<<"2. Affiche les numeros\n";
			cout<<"3. Quiter le legiciel\n";
			cin>>c;
		} while (c<'1' || c>'c');
		switch(c)
		{
			case '1':
				cin>>a;
				cout<<"Le entre cest: ";
				cout<<a;
				at<<a;
				break;
			case '2':
				char ch;
				at.seekg(0,ios::beg);
				while(!at.eof())
				{
					at.get(ch);
					cout<<ch;
				}
				at.clear();
				cout<<endl;
				break;
			case '3':
				at.close();
				return 0;
		}
	}
}

					