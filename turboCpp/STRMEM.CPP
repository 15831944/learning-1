/*
 * operatii de scriere si citire din memorie
 */
#include <strstream.h>
#include <iomanip.h>
int main()
{
	char nm[11], pr[11], lin[122];
	int n;
	float m;
	for(;;) {
		cout<<"Introduceti: ";
		cout<<"Nr,Nume<11),Prenume<11),Medie"<<endl;
		cin.getline(lin,122);
		istrstream tamp(lin,cin.gcount());
		tamp >> n>> setw(10)>>nm>>setw(10)>>pr>>m;
		if(tamp && m <= 10) break;
		else cout <<"Eroare !\n";
	}
	cout<<"Ati introdus: ";
	cout<<setw(4)<<n<<setw(11)<<nm<<setw(11)<<pr<<setw(5)<<m<<endl;
}