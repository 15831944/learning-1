#include <afx.h>
#include <iostream>
#include <afxtempl.h>

using namespace std;

int main() {
	CArray<CString, CString&> rgCarti;
	CString szAs("As de pica");
	CString szPopa("Popa de pica");
	CString szDama("Dama de pica");
	CString szValet("Valet de pica");
	CString szZece("Zece de pica");
	//adauga cinci carti la matrice
	rgCarti.SetAtGrow(0, szAs);
	rgCarti.SetAtGrow(1, szPopa);
	rgCarti.SetAtGrow(2, szDama);
	rgCarti.SetAtGrow(3, szValet);
	rgCarti.SetAtGrow(4, szZece);
	//afiseaza continutul matricei de carti de joc
	cout << "Se pare ca am mina cistigatoare!" << endl;
	int cCarti = rgCarti.GetSize();
	for (int nIndCarte = 0; nIndCarte < cCarti; nIndCarte++) {
		cout << "\t" << rgCarti[nIndCarte] << endl;
	}
	//elimina articolele stocate in matrice
	rgCarti.RemoveAll();
	return EXIT_SUCCESS;
}