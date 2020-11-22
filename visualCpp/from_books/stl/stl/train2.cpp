//specializare functie membru showContents a clasei RailroadCar pentru numere intregi
#include <iostream>
#include <afx.h>

//lucruri care vor fi incluse in RailroadCar
class Cow {
public:
	CString isA() {
		return "Cow";
	}
	CString Moo() {
		return "Moo!";
	}
};

class Passenger {
public:
	Passenger(CString NewName) {
		Name = NewName;
	}
	CString isA() {
		return "Passenger";
	}
	CString GetName() {
		return Name;
	}
	CString Complain() {
		return "Oh my poor back!";
	}
private:
	CString Name;
};

//template for RailroadCar
template<class T>
class RailroadCar {
public:
	RailroadCar(int NewCarNumber, T& NewContents);
	~RailroadCar();
	void ShowContents();
	T* Unload();
private:
	T* pContents;
	int CarNumber;
};

//constructor
template <class T>
RailroadCar<T>::RailroadCar(int NewCarNumber, T& NewContents) {
	CarNumber = NewCarNumber;
	pContents = &NewContents;
}

template <class T>
RailroadCar<T>::~RailroadCar() {
	Unload();
}

template<class T>
void RailroadCar<T>::ShowContents() {
	std::cout << "Railroad car #" << CarNumber;
	std::cout << " is filled with " << pContents->isA();
	std::cout << "s\n";
}

template <class T>
T* RailroadCar<T>::Unload() {
	T* temp = pContents;
	pContents = NULL;
	return temp;
}

//ShowContents specializarea pentru numere intregi
void RailroadCar<int>::ShowContents() {
	std::cout << "RailroadCar #" << CarNumber;
	std::cout << " is filled with integer (" << *pContents << ")\n";
}

int main() {
	int IntegerCargo = 456;
	Cow Bessie;
	RailroadCar<int> CarNumber1(1, IntegerCargo);
	RailroadCar < Cow> CarNumber2(1, Bessie);

	CarNumber1.ShowContents();
	CarNumber2.ShowContents();
}