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

int main() {
	// la statia 1
	Cow ACow;
	Passenger APassenger("Monthy");
	RailroadCar<Cow> CarNumber1(1, ACow);
	RailroadCar<Passenger> CarNumber2(2, APassenger);
	CarNumber1.ShowContents();
	CarNumber2.ShowContents();

	//merge catre statia 2 ...
	std::cout << "\n..Choo...Chooo\n\n";

	//la statia 2
	Cow* AtStation2Cow = CarNumber1.Unload();
	Passenger* AtStation2Passenger = CarNumber2.Unload();

	std::cout << "How was the trip, " << AtStation2Passenger->GetName() << "?";
	std::cout << " " << AtStation2Passenger->Complain() << std::endl;
	std::cout << AtStation2Cow->Moo() << std::endl;
}