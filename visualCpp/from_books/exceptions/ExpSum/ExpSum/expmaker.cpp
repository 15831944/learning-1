//programul de generare a fisierelor de cheltuieli

#include <fstream>
#include <iomanip>
#include "Employee.h"
#include "Expense.h"
using namespace std;

void GetNewExpenseItem(ofstream& outfile, const unsigned itemNum) {
	Expense NewExpense;
	float ExpenseAmount;
	char TempBuffer[256], ChompNewline;
	//Elemente de imbunatatire a interfetei cu utilizatorul
	cout << "\nExpense #" << itemNum + 1 << endl;
	//completare elementelor de baza
	cout << "Expense date   : ";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewline);
	NewExpense.SetDate(TempBuffer);
	cout << "Description    : ";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewline);
	NewExpense.SetDescription(TempBuffer);
	cout << "Expense amount : ";
	cin >> ExpenseAmount;
	cin.get(ChompNewline);
	NewExpense.SetExpenseAmount(ExpenseAmount);
	//scrierea inregistratii pe disk
	outfile << NewExpense;
}

void GetNewEmployee(ofstream& outfile) {
	Employee NewEmployee;
	unsigned long NewZip;
	unsigned loop, NewID, NewNumExpenses;
	char TempBuffer[256], ChompNewLine, NewInitial;
	//Elemente de imbunatatire a interfatei cu utilizatorul
	cout << "\nNew employee record\n";
	cout << "======================\n";
	//completarea elementelor de baza
	cout << "Employee ID    : ";
	cin >> NewID;
	cin.get(ChompNewLine);
	NewEmployee.SetId(NewID);
	cout << "First name     :";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewLine);
	NewEmployee.SetFirstName(TempBuffer);
	cout << "Middle initial : ";
	cin >> NewInitial;
	cin.get(ChompNewLine);
	NewEmployee.SetMiddileInitial(NewInitial);
	cout << "Last name      : ";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewLine);
	NewEmployee.SetLastName(TempBuffer);
	cout << "Address        : ";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewLine);
	NewEmployee.SetAddress(TempBuffer);
	cout << "City           : ";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewLine);
	NewEmployee.SetCity(TempBuffer);
	cout << "State          : ";
	cin.get(TempBuffer, 256);
	cin.get(ChompNewLine);
	NewEmployee.SetState(TempBuffer);
	cout << "ZIP Code       : ";
	cin >> NewZip;
	cin.get(ChompNewLine);
	NewEmployee.SetZip(NewZip);
	cout << "\nNumber of expense items for this employee ?";
	cin >> NewNumExpenses;
	cin.get(ChompNewLine);
	NewEmployee.SetNumExpenses(NewNumExpenses);
	//scrirea inregistratyii angajatului in fisier
	outfile << NewEmployee;
	//obtinem o noua inregistrare
	for (loop = 0; loop < NewEmployee.GetNumExpenses(); loop++)
		GetNewExpenseItem(outfile, loop);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "USAGE: " << argv[0] << " <outfile name>" << endl << endl;
		return -1;
	}
	//deschide fisierul
	ofstream outfile(argv[1]);
	//scrie acel numa fara sens  de anagajat
	unsigned EmployeeCount = 0;
	outfile << setw(5) << EmployeeCount << setw(0) << " ";
	//ciclul principal pentru angajat
	char Again;
	do {
		char ChompNewLine;
		EmployeeCount++;
		GetNewEmployee(outfile);
		cout << "\nEnter another emplyee (Y/N)? ";
		cin >> Again;
		cin.get(ChompNewLine);
	} while (Again == 'y' || Again == 'Y');
	//mergi la inceputul fisierului si completeaz a numaraul real al angajatului
	outfile.seekp(0, ios::beg);
	outfile.setf(ios::left);
	outfile << setw(5) << EmployeeCount;
	//inchide fisierul de iesire
	outfile.close();
}