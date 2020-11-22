#pragma once
#include <iostream>
#include <afx.h>

class Employee
{
public:
	Employee();
	void SetId(unsigned NewID) {
		EmployeeID = NewID;
	}
	void SetFirstName(const char *NewName) {
		FirstName = NewName;
	}
	void SetMiddileInitial(char NewInitial) {
		MiddleInitial = NewInitial;
	}
	void SetLastName(const char *NewName) {
		LastName = NewName;
	}
	void SetAddress(const char *NewAddress) {
		Address = NewAddress;
	}
	void SetCity(const char *NewCity) {
		City = NewCity;
	}
	void SetState(const char *NewState) {
		State = NewState;
	}
	void SetZip(unsigned long NewZip) {
		Zip = NewZip;
	}
	void SetNumExpenses(unsigned NewNumExpenses) {
		NumExpenses = NewNumExpenses;
	}
	unsigned GetID() const {
		return EmployeeID;
	}
	CString GetFirstName() const {
		return FirstName;
	}
	char GetMiddleInitial() const {
		return MiddleInitial;
	}
	CString GetLastName() const {
		return LastName;
	}
	CString GetAddress() const {
		return Address;
	}
	CString GetCity() const {
		return City;
	}
	CString GetState() const {
		return State;
	}
	unsigned long GetZip() const {
		return Zip;
	}
	unsigned GetNumExpenses() const {
		return NumExpenses;
	}

private:
	unsigned EmployeeID;
	CString FirstName;
	CString LastName;
	char MiddleInitial;
	CString Address;
	CString City;
	CString State;
	unsigned long Zip;
	unsigned NumExpenses;
	friend std::ostream& operator<<(std::ostream& ostr, const Employee& employee);
	friend std::istream& operator>>(std::istream& istr, Employee& employee);
};

