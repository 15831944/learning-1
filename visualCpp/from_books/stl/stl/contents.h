#pragma once

#include<afx.h>

//continutul obiectelor RailroadCar
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
		return "Name";
	}
	CString Complain() {
		return "Oh my poor back!";
	}
private:
	CString Name;
};
