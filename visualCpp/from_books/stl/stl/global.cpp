//template that use static member methods and variables
#include <iostream>

using namespace std;
//defineste tipul boolean
typedef unsigned char Boolean;
const Boolean TRUE = 1;
const Boolean FALSE = 0;

template <class T>
class GlobalValue {
public:
	GlobalValue();
	GlobalValue(T* pNewGlobalValue);
	~GlobalValue();
	static T* GetGlobalValuePtr();
private:
	static T* pGlobalValue;
	static Boolean ShouldDelete;
};

//initializare date statice
template <class T>
T* GlobalValue<T>::pGlobalValue = NULL;

template<class T>
Boolean GlobalValue<T>::ShouldDelete = FALSE;

//constructori
template<class T>
GlobalValue<T>::GlobalValue() {
	pGlobalValue = new T;
	ShouldDelete = TRUE;
}

template <class T>
GlobalValue<T>::GlobalValue(T* pNewGlobalValue) {
	pGlobalValue = pNewGlobalValue;
	ShouldDelete = FALSE;
}

//destructor
template<class T>
GlobalValue<T>::~GlobalValue() {
	if (ShouldDelete && pGlobalValue)
		delete pGlobalValue;
}

template<class T>
T* GlobalValue<T>::GetGlobalValuePtr() {
	return pGlobalValue;
}

void AFarAwayFunc() {
	cout << "The int GlobalValue is ";
	cout << *GlobalValue<int>::GetGlobalValuePtr() << endl;
}

int main() {
	int AVeryImportantInt = 123;
	GlobalValue<int> GlobalInt(&AVeryImportantInt);
	//afiseaza valoare curenta
	AFarAwayFunc();
	//Modifica valoare
	AVeryImportantInt++;
	AFarAwayFunc();
}