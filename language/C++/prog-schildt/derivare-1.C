#include<iostream.h>
class cladire
{
	int camere;
	int etaje;
	int supraf;
public:
	void nr_camere(int num);
	int cite_camere();
	void nr_etaje(int num);
	int cite_etaje();
	void nr_supraf(int num);
	int cite_supraf();
};
//la maison c'est derive de construction
class casa: public cladire
{
	int dormitoare;
	int bai;
public:
	void nr_dormitoare(int num);
	int cite_dormitoare();
	void nr_bai(int num);
	int cite_bai();
};
//l'ecole c'est aussi derove de construction
class scoala:public cladire
{
	int saliclasa;
	int laborat;
public:
	void nr_saliclasa(int num);
	int cite_saliclasa();
	void nr_laborat(int num);
	int cite_laborat();
};

void cladire::nr_camere(int num)
{
	camere=num;
}
void cladire::nr_etaje(int num)
{
	etaje=num;
}
void cladire::nr_supraf(int num)
{
	supraf=num;
}
int cladire::cite_camere()
{
	return camere;
}
int cladire::cite_etaje()
{
	return etaje;
}
int cladire::cite_supraf()
{
	return supraf;
}

void casa::nr_dormitoare(int num)
{
	dormitoare=num;
}
void casa::nr_bai(int num)
{
	bai=num;
}
int casa::cite_dormitoare()
{
	return dormitoare;
}
int casa::cite_bai()
{
	return bai;
}

void scoala::nr_saliclasa(int num)
{
	saliclasa=num;
}
void scoala::nr_laborat(int num)
{
	laborat=num;
}
int scoala::cite_saliclasa()
{
	return saliclasa;
}
int scoala::cite_laborat()
{
	return laborat;
}

int main()
{
casa c;
scoala s;
	c.nr_camere(12);
	c.nr_etaje(2);
	c.nr_supraf(4500);
	c.nr_dormitoare(5);
	c.nr_bai(3);
	cout<<"la maison a "<<c.cite_dormitoare();
	cout<<" dormitoare\n";
	
	s.nr_camere(200);
	s.nr_saliclasa(180);
	s.nr_laborat(5);
	s.nr_supraf(25000);
	cout<<"l'ecole a "<<s.cite_saliclasa();
	cout<<" salle de classe\n";
	cout<<"Son area est de "<<s.cite_supraf()<<"\n";
}
