/*
	Scrieti un program cu clase care sa realizeze un arbore binar de cautare pentru 
	numere intregi pozitive. Apoi din acesta clasa derivati o clasa care ca realizeze
	eliminarea unui nod din arbore.
*/
#include <iostream.h>
struct nod
{
	int val;
	struct nod *fii[2];
};
class arbore
{
public:
	void introducere(int val1);
	void RSD(struct nod *virft);
	void SRD(struct nod *virft);
	void parcurgere(int i);
	arbore();
	~arbore();
protected:
	struct nod *baza;
private:
	void eliberare(struct nod *virft);
	struct nod *temp,*work;
	int val;
	int poz;
};
arbore::arbore()
{
	baza=NULL;
}
arbore::~arbore()
{
	eliberare(baza);
	baza=NULL;
}
void arbore::eliberare(struct nod *virft)
{
	if(virft->fii[0]!=NULL) eliberare(virft->fii[0]);
	if(virft->fii[1]!=NULL) eliberare(virft->fii[1]);
	delete virft;
}
void arbore::introducere(int val1)
{
	temp=new struct nod;
	temp->fii[0]=NULL;
	temp->fii[1]=NULL;
	temp->val=val1;
	if(baza==NULL)
	{
		baza=temp;
		return;
	}
	work=baza;
	poz=(work->val<=val1);
	while(work->fii[poz]!=NULL)
	{
		work=work->fii[poz];
		poz=(work->val<=val1);
	}
	work->fii[poz]=temp;
}
void arbore::RSD(struct nod *virft)
{
	cout<<virft->val<<endl;cout.flush();
	if(virft->fii[0]!=NULL) RSD(virft->fii[0]);
	if(virft->fii[1]!=NULL) RSD(virft->fii[1]);
}
void arbore::SRD(struct nod *virft)
{
	if(virft->fii[0]!=NULL) RSD(virft->fii[0]);
	cout<<virft->val<<endl;cout.flush();
	if(virft->fii[1]!=NULL) RSD(virft->fii[1]);
}
void arbore::parcurgere(int i)
{
	if(i==0) RSD(baza);
	if(i==1) SRD(baza);
}

void main()
{
	arbore arb;
	int val;
	cin>>val;
	while(val>=0)
	{
		arb.introducere(val);
		cin>>val;
	}
	arb.parcurgere(1);
	cout<<endl;
	arb.parcurgere(0);
	cout<<"Eliberare memorie\n";cout.flush();
}