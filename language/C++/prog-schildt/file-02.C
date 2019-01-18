#include<iostream.h>
#include<fstream.h>
int main()
{
	ifstream in("INVENTAR");
	if(!in)
	{
		cout<<"Je ne pexux pas ouvre  le fichier INVENTAR.\n";
		return 1;
	}
	char articol[20];
	float pret;
	for(int i=0;i<3;i++)
	{
		in>>articol>>pret;
		cout<<articol<<" "<<pret<<"\n";
	}
	in.close();
}
	