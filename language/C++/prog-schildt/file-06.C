#include<iostream.h>
#include<fstream.h>
#include<string.h>

struct stare
{
	char nume[80];
	float bilant;
	unsigned long numar_cont;
};
int main()
{
	struct stare ct;
	strcpy(ct.nume,"Ralph Trantor");
	ct.bilant=1123.23;
	ct.numar_cont=34235678;
	ofstream outbal("bilant",ios::out | ios::binary);
	if(!outbal)
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	outbal.write((unsigned char *)&ct,sizeof(struct stare));
	outbal.close();
	
	//dans ce moment je lise qu'est ce j'avais ecrit
	ifstream inbal("bilant",ios::in | ios::binary);
	if(!inbal)
	{
		cout<<"Je ne peux pas ouvrir le fichier.\n";
		return 1;
	}
	inbal.read((unsigned char *)&ct,sizeof(struct stare));
	cout<<ct.nume<<endl;
	cout<<"Cont # "<<ct.numar_cont;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout<<endl<<"Bilant: $ "<<ct.bilant<<endl;
	inbal.close();
}