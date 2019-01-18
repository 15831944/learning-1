#include<iostream.h>

int main()
{
	int *p,i;
	p=new int[10]; //il affecte de memoire pour un matrice de 10 elements
	if(!p)
	{
		cout<<"Error de affecte de memoire\n";
		exit(1);
	}
	for(i=0;i<10;i++) p[i]=i;
	for(i=0;i<10;i++) cout<<p[i]<<" ";
	delete []p; //il elibere la memoire pour la matrice
	cout<<"\n";
}