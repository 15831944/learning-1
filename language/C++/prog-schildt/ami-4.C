#include<iostream.h>

class monede
{
	//la suivant c'est une enumeration particuliere
	enum unitati {penney,nickel,dime,quarter,jumatate_dolar};
friend class cantitate;
};

class cantitate
{
	monede::unitati bani;//garde le modul monede::unitati
public:
	void dam();
	int iam();
} ob;

int cantitate::iam()
{
	return bani;
}
void cantitate::dam()
{
	//l'unite de numeration sunt accesible ici parce que cantitate c'est un ami pour monede.
	bani=monede::dime;
}

int main()
{
	ob.dam();
	cout<<ob.iam()<<"\n";	//il affiche le numero 2
}