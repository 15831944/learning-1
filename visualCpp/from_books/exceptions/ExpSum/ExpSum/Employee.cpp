#include "Employee.h"
using namespace std;
Employee::Employee() : EmployeeID(0), MiddleInitial('\0'), Zip(0UL), NumExpenses(0) {

}

ostream& operator<<(ostream& ostr, const Employee& employee) {
	ostr << employee.EmployeeID;
	ostr << employee.FirstName << " ";
	ostr << employee.LastName << " ";
	ostr << employee.MiddleInitial << " ";
	ostr << employee.Address << endl;
	ostr << employee.City << " ";
	ostr << employee.State << " ";
	ostr << employee.Zip << " ";
	ostr << employee.NumExpenses << endl;
	return ostr;
}

istream& operator>>(istream& istr, Employee& employee) {
	char TempBuffer[256];
	istr >> employee.EmployeeID;
	istr >> TempBuffer;
	employee.FirstName = TempBuffer;
	istr >> TempBuffer;
	employee.LastName = TempBuffer;
	istr >> employee.MiddleInitial;
	istr.getline(TempBuffer, 256);
	employee.Address = TempBuffer;
	istr >> TempBuffer;
	employee.City = TempBuffer;
	istr >> TempBuffer;
	employee.State = TempBuffer;
	istr >> employee.Zip;
	istr >> employee.NumExpenses;
	return istr;
}
