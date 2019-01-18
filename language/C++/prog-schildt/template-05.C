#include<iostream.h>
template <class X> void compact(X *elemente,int numar,int start,int stop)
{
	register int i;
	for(i=stop+1;i<numar;i++,start++) elemente[start]=elemente[i];
	for(;start<numar;start++) elemente[start]=(X)0;
}
int main()
{
	int num[7]={0,1,2,3,4,5,6};
	char sir[25]="Functions generique";
	int i;
	cout<<"Voici la matrice de int noncompacte: ";
	for(i=0;i<7;i++) cout<<num[i]<<" ";
	cout<<endl;
	compact(num,7,2,4);
	cout<<"Voici la matrice de int compacte: ";
	for(i=0;i<7;i++) cout<<num[i]<<" ";
	cout<<endl;
	cout<<"Voici le sir noncompacte: ";
	for(i=0;i<25;i++) cout<<sir[i]<<" ";
	cout<<endl;
	compact(sir,25,6,10);
	cout<<"Voici le sir compacte: ";
	for(i=0;i<25;i++) cout<<sir[i]<<" ";
	cout<<endl;
}
	