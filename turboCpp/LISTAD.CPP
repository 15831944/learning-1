/*
 * lista dublu inlantuita cu nod capat
 */
#include <iostream.h>
struct lnod {
	void *data;
	lnod *urm;
	lnod *prec;
	lnod(void *d=0) //constructor
	{
		data = d;
		urm = prec = 0;
	}
};

//lista dublu inlantuita cu nod capat
class ldi {
protected:
	lnod cap, *crt;
public:
	ldi(); // constructor
	~ldi(); //destructor
	//test lista vida
	int nl_vida()
	{
		return &cap != cap.urm;
	}
	//initializeaza indicator curent pe nodul capat
	void capat()
	{
		crt = &cap;
	}
	//initializeaza indicator curent in fata
	void prim()
	{
		crt = cap.urm;
	}
	//initializeaza indicator curent la sfirsit
	void ultim()
	{
		crt = cap.prec;
	}
	//avanseaza indicator curent si intoarce element
	void *spre_dr();
	void *spre_st();
	//citeste elementul curent
	void *citesc();
	//adauga la dreapta nodului curent
	void *adaug_dr(void* d);
	//adauga la stinga nodului curent
	void* adaug_st(void* d);
	//extrage nodul curent
	void* extrag();
};
//constructor
ldi::ldi()
{
	crt = cap.urm = cap.prec = &cap;
}
//citire element curent
void *ldi::citesc()
{
	if(crt != &cap)
		return crt->data;
	else
		return 0;
}
//adaugare la stinga
void* ldi::adaug_st(void* d)
{
	lnod *p;
	p = new lnod(d);
	if(p) {
		p -> urm = crt;
		p -> prec = crt -> prec;
		crt -> prec = crt -> prec -> urm = p;
		crt = p;
		return p;
	}
	return 0;
}
//adaugare la dreapta
void* ldi::adaug_dr(void* d)
{
	lnod *p;
	p = new lnod(d);
	if(p) {
		p -> prec = crt;
		p -> urm = crt -> urm;
		crt -> urm = crt -> urm -> prec = p;
		crt = p;
		return p;
	}
	return 0;
}
//extrage elementul curent
void* ldi::extrag()
{
	lnod *p;
	void *d;
	if(crt != &cap) {
		p = crt;
		crt -> urm -> prec = crt -> prec;
		crt -> prec -> urm = crt -> urm;
		crt = crt -> urm;
		d = p -> data;
		delete p;
		return d;
	}
	return 0;
}
//parcurgerea in sens direct (dreapta)
void *ldi::spre_dr()
{
	if(nl_vida() && crt -> urm != &cap) {
		crt = crt -> urm;
		return crt -> data;
	}
	return 0;
}
//parcurgere in sens invers (stinga)
void* ldi::spre_st()
{
	if(nl_vida() && crt -> prec != &cap) {
		crt = crt -> prec;
		return crt -> data;
	}
	return 0;
}
ldi::~ldi()
{
	lnod *p;
	p = cap.urm;
	while (p != &cap) {
		crt = p;
		p = p -> urm;
		delete crt;
	}
}

void main()
{
	ldi list;
	int *ip, i;
	//inscrie la inceput valorile:0..9
	for(i = 0; i < 10; i++)
		list.adaug_dr(new int(i));
	//inscrie la sfirsit valirle: 10..10
	list.capat();
	for(i = 9; i >= 0; i--)
		list.adaug_st(new int(i+10));
	//citeste primul parametru
	list.prim();
	cout<<*(int *)list.citesc()<<endl;
	//parcurge in sens direct (stinga -> dreapta) si afiseaza
	list.capat();
	while((ip = (int *)list.spre_dr()))
		cout<<*ip<<' ';
	cout<<endl;
	//parcurge in sens invers (dreapta -> stinga) si afiseaza
	list.capat();
	while((ip = (int *)list.spre_st()))
		cout<<*ip<<' ';
	cout<<endl;
	//extrage si elimina elementele
	list.prim();
	while ((ip = (int *)list.extrag())) {
		cout<<*ip<<' ';
		delete ip;
	}
	cout<<endl;
	//test lista vida
	if(!list.nl_vida())
		cout<<"Lista vida"<<endl;
}