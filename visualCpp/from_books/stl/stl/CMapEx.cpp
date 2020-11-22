#include <afx.h>
#include <iostream>
#include <afxtempl.h>

using namespace std;

int main() {
	CMap<int, int, CString, CString&> NrClient;
	CString szAlex("Alex");
	CString szRene("Rene");
	CString szMaynard("Maynard");
	NrClient.SetAt(12564, szAlex);
	NrClient.SetAt(12453, szRene);
	NrClient.SetAt(16342, szMaynard);
	//afiseaza numarul de articole stocate in lista
	int cClienti = NrClient.GetCount();
	cout << "Avem " << cClienti << " clienti:" << endl;
	cout << "\nNume\tNumarClient" << endl;
	//iteratie pe map, afisare articole pe rind
	POSITION pos = NrClient.GetStartPosition();
	while (pos != NULL) {
		CString szClient; //numele clientului
		int idClient; //codul clientului
		NrClient.GetNextAssoc(pos, idClient, szClient);
		cout << szClient << "\t" << idClient << endl;
	}
	//cauta un client in map folosing cheia
	CString szClient;
	BOOL fGasit = NrClient.Lookup(12453, szClient);
	if (TRUE == fGasit) {
		cout << "\nNr.12453 apartine clientului " << szClient << endl;
	}
	//elimina articolele stocate
	NrClient.RemoveAll();
	return EXIT_SUCCESS;
}