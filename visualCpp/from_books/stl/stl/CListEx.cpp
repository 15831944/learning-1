#include <afx.h>
#include <iostream>
#include <afxtempl.h>

using namespace std;

int main() {
	CList<CString, CString& > listaAsteptare;
	CString szAlex("Alex");
	CString szJames("James");
	CString szRoger("Roger");
	//add the three elements to the end of the list
	listaAsteptare.AddTail(szAlex);
	listaAsteptare.AddTail(szJames);
	listaAsteptare.AddTail(szRoger);
	//print the number of the elemnts into the list
	int cWaiting = listaAsteptare.GetCount();
	cout << "Waiting " << cWaiting << " nr or persons." << endl;
	//print the the contain of the list
	POSITION pos = listaAsteptare.GetHeadPosition();
	while (pos != NULL) {
		CString szWaiting = listaAsteptare.GetNext(pos);
		cout << "\t" << szWaiting << endl;
	}
	//remove the stored elements
	listaAsteptare.RemoveAll();
	return EXIT_SUCCESS;
}