/* Program care realizeaza combinari de n luate cite m */
#include<iostream.h>
#include<stdlib.h>

float factorial(int numar)
{
int i;
float factorial=1;
	if(numar==0) return 1;
	for(i=1;i<numar+1;i++) factorial*=i;
	return factorial;
}

int main(void)
{
int m,n;
float combinari,aranjamente;
int i,test;
char key;
	test=0;
	while(test!=1)
	{
		cout<<"\n Introduceti exponentii m si n ";
		cin>>m>>n;
		combinari=factorial(n)/factorial(m)/factorial(n-m);
		aranjamente=1;
		for(i=0;i<m;i++) aranjamente*=n-i;
		cout<<"\n Combinari de "<<n<<" luate cite "<<m<<" fac:"<<combinari<<"\n";
		cout<<"\n Aranjamente de "<<n<<" luate cite "<<m<<" fac:"<<aranjamente<<"\n";
		i=0;
		//testez daca s-a introdus corect simbolul de iesire sau continuare si actionez ca atare
		while(i!=1)
		{
			cout<<"\n Doriti sa continuati D/N ";
			cin>>key;
			if((key=='D')||(key=='d'))
			{
				test=0;
				i=1;
			}
			else 	if((key=='N')||(key=='n'))
					{
						test=1;
						i=1;
					}
					else i=0;
		}
	}
	exit(0);
}