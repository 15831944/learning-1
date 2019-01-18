#include<iostream.h>
template <class X> void amestec(X *elemente,int numar)
{
	register int a,b;
	X t;
	for(a=1;a<numar;a++)
		for(b=numar-1;b>=a;b--)
			if(elemente[b-1]>elemente[b])
			{
				t=elemente[b-1];
				elemente[b-1]=elemente[b];
				elemente[b]=t;
			}
}
int main()
{
	int imatrice[7]={7,5,4,3,9,8,6};
	double dmatrice[5]={4.3, 2.5, -0.9, 100.2, 3.0};
	int i;
	cout<<"Voici la matrice de int nonsorte: ";
	for(i=0;i<7;i++) cout<<imatrice[i]<<" ";
	cout<<endl;
	amestec(imatrice,7);
	cout<<"Voici la matrice de int sorte: ";
	for(i=0;i<7;i++) cout<<imatrice[i]<<" ";
	cout<<endl;
	cout<<"Voice la matrice de double nonsorte: ";
	for(i=0;i<5;i++) cout<<dmatrice[i]<<" ";
	cout<<endl;
	amestec(dmatrice,5);
	cout<<"Voici la matrice de double sorte: ";
	for(i=0;i<5;i++) cout<<dmatrice[i]<<" ";
	cout<<endl;
}
