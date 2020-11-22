#include <iostream>
#include "templts.h"
#include "contents.h"

using namespace std;

template<class T>
RailroadCar<T>::RailroadCar(int NewCarNumber, T& NewContents) {
	CarNumber = NewCarNumber;
	pContents = &NewContents;
}

template<class T>
RailroadCar<T>::~RailroadCar() {
	Unload();
}

template<class T>
void RailroadCar<T>::ShowContents() {
	cout << "Rairoad car #" << CarNumber;
	cout << " is filled with " << pContents->isA();
	cout << "s\n";
}

template <class T>
T* RailroadCar<T>::Unload() {
	T* temp = pContents;
	pContents = NULL;
	return temp;
}

//fortarea instantierea sablonului
template RailroadCar<Cow>;
template RailroadCar<Passenger>;