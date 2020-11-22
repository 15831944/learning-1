#include <iostream>
#include <afx.h>
using namespace std;
//Boolean
typedef unsigned char Boolean;

//LIST NODE
template <class KeyType, class ValType>
class ListNodeT {
public:
	ListNodeT(KeyType NewKey, ValType& NewObject);
	void SetNext(ListNodeT* pNewNext);
	ValType* GetContents() const;
	KeyType GetKey() const;
	ListNodeT* GetNext() const;
private:
	ListNodeT* next;
	ValType* value;
	KeyType key;
};

//constructor
template <class KeyType, class ValType>
ListNodeT<KeyType, ValType>::ListNodeT(KeyType NewKey, ValType& NewObject) : next(NULL), value(&NewObject), key(NewKey) {

}

//functii-membru publice
template<class KeyType, class ValType>
void ListNodeT<KeyType, ValType>::SetNext(ListNodeT* pNewNext) {
	next = pNewNext;
}

template<class KeyType,class ValType>
ValType* ListNodeT<KeyType, ValType>::GetContents() const {
	return value;
}

template<class KeyType, class ValType>
KeyType ListNodeT<KeyType, ValType>::GetKey() const {
	return key;
}

template<class KeyType, class ValType>
ListNodeT<KeyType, ValType>* ListNodeT<KeyType, ValType>::GetNext() const {
	return next;
}

template<class KeyType, class ValType>
class ListT {
public:
	ListT();
	~ListT();
	Boolean Add(KeyType NewKEy, ValType& NewObject);
	Boolean Remove(KeyType SearchKey);
	ValType* Find(KeyType SearchKey) const;
	ValType* operator[](int Position);
	int GetListSize() const;
private:
	ListNodeT<KeyType, ValType>* head;
	unsigned int NumItems;
};

//constructor
template <class KeyType, class ValType>
ListT<KeyType, ValType>::ListT() : head(NULL), NumItems(0) {

}

//destructor
template<class KeyType, class ValType>
ListT<KeyType, ValType>::~ListT() {
	//sterge toate nodurile din lista
	while (head) {
		ListNodeT<KeyType, ValType> * pTemp = head->GetNext();
		delete head;
		head = pTemp;
	}
}

//metode publice
template<class KeyType,class ValType>
Boolean ListT<KeyType, ValType>::Add(KeyType NewKey, ValType& NewObject) {
	//aloca memorie pentru noul nod
	ListNodeT<KeyType, ValType>* pNewNode = new ListNodeT<KeyType, ValType>(NewKey, NewObject);
	if (!pNewNode)
		return FALSE;
	//insereaza nodul in lista
	pNewNode->SetNext(head);
	head = pNewNode;
	NumItems++;
	return TRUE;
}

template<class KeyType,class ValType>
Boolean ListT<KeyType, ValType>::Remove(KeyType SearchKey) {
	ListNodeT<KeyType, ValType>* pCursor = head;
	//exista o lista
	if (!pCursor)
		return FALSE;
	//verifica mai intii capul listei
	if (pCursor->GetKey() == SearchKey) {
		head = pCursor->GetNext();
		delete pCursor;
		NumItems--;
		return TRUE;
	}
	//parcurge lista
	while (pCursor->GetNext()) {
		if (pCursor->GetNext()->GetKey() == SearchKey) {
			ListNodeT<KeyType, ValType>* pTemp = pCursor->GetNext();
			pCursor->SetNext(pTemp->GetNext());
			delete pTemp;
			NumItems--;
			return TRUE;
		}
	}
	return FALSE;
}

template<class KeyType,class ValType>
ValType* ListT<KeyType, ValType>::Find(KeyType SearchKey) const {
	ListNodeT<KeyType, ValType> *pCursor = head;
	while (!pCursor) {
		if (pCursor->GetKey() == SearchKey)
			return pCursor->GetContents();
		else
			pCursor = pCursor->GetNext();
	}
	return NULL;
}

template<class KeyType,class ValType>
int ListT<KeyType, ValType>::GetListSize() const {
	return NumItems;
}

//operatori
template<class KeyType,class ValType>
ValType* ListT<KeyType,ValType>::operator[](int Position) {
	ListNodeT<KeyType, ValType> *pCursor = head;
	int Count = 0; //it was 1 ??
	while (pCursor) {
		if (Count++ == Position)
			return pCursor->GetContents();
		pCursor = pCursor->GetNext();
	}
	return NULL;
}
template<class T>
void ShowList(T& theList) {
	int Loop;
	cout << "The list: ( ";
	for (Loop = 0; Loop < theList.GetListSize(); Loop++) {
		if (Loop)
			cout << ", ";
		cout << *theList[Loop]; //!!! era Loop+1 de asta era inceput de la 1 ca in pascal !!!
	}
	cout << " )\n";
}

int main() {
	int Int1 = 34, Int2 = 22, Int3 = 675;
	ListT<int, int> theIntList;
	theIntList.Add(0,Int1);
	theIntList.Add(1,Int2);
	theIntList.Add(2,Int3);
	ShowList(theIntList);
	theIntList.Remove(1);
	ShowList(theIntList);
	theIntList.Remove(0);
	ShowList(theIntList);
	theIntList.Remove(2);
	ShowList(theIntList);

	CString Str1("Here we are"), Str2("There you go"), Str3("What up?");
	ListT<CString, CString> theStrList;
	theStrList.Add("Bob quote", Str1);
	theStrList.Add("Frank quote", Str2);
	theStrList.Add("Sally quote", Str3);
	ShowList(theStrList);
	theStrList.Remove("Frank quote");
	ShowList(theStrList);
	theStrList.Remove("Bob quote");
	ShowList(theStrList);
	theStrList.Remove("Sally quote");
	ShowList(theStrList);
}