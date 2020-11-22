#include <iostream>
#include "templts.h"
#include "contents.h"

int main() {
	//La statia 1
	Cow ACow;
	Passenger APassenger("Monthy");
	RailroadCar<Cow> CarNumber1(1, ACow);
	RailroadCar<Passenger> CarNumber2(2, APassenger);

	CarNumber1.ShowContents();
	CarNumber2.ShowContents();
	//merge catre statia 2
	std::cout << "\n..Choo..Choo..\n\n";

	//La statia 2
	Cow* AtStatia2Cow = CarNumber1.Unload();
	Passenger* AtStation2Passenger = CarNumber2.Unload();
	std::cout << "How was the trip, ";
	std::cout << AtStation2Passenger->GetName() << "?";
	std::cout << " " << AtStation2Passenger->Complain() << std::endl;
	std::cout << AtStatia2Cow->Moo() << std::endl;
}