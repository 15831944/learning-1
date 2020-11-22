//aplicatia ExpSum folosind metode traditionale de tratare a erorilor
#include "Employee.h"
#include "Expense.h"
#include <fstream>
#include <iomanip>

using namespace std;

//definitii
const int MIN_ALLOWABLE_EMPLOYEES = 1;
const int MAX_ALLOWABLE_EMPLOYEES = 20;
const int MIN_NUM_EXPENSES = 1;
const int MAX_NUM_EXPENSES = 10;
const float MIN_ALLOWABLE_EXPENSE = 1.0F;
const float MAX_ALLOWABLE_EXPENSE = 1000.0F;
const float MAX_ALLOWABLE_REIMBURSEMENT = 5000.0F;

//coduri de eroare
typedef enum {
	EXP_NO_ERROR,
	EXP_ERR_EXPENSE_TOO_SMALL,
	EXP_ERR_EXPENSE_TOO_LARGE,
	EXP_ERR_NO_EXPENSE_ITEMS,
	EXP_ERR_TOO_MANY_EXPENSE_ITEMS,
	EXP_ERR_TOTAL_EXPENSE_TOO_LARGE
} ErrorCode;

float ProcessExpenseItem(ifstream& infile, ErrorCode& rc) {
	Expense NewExpense;
	//initializarea codului care va fi returnat
	rc = EXP_NO_ERROR;
	//citeste o inregistrare de cheltuieli din fisier
	infile >> NewExpense;
	//verifica aparitia eventualelor probleme
	if (NewExpense.GetExpenseAmount() < MIN_ALLOWABLE_EXPENSE) {
		cout << "Eroare! Cheltuielile sunt mai mici decit suma minima admisa pentru decontare.\n\n";
		rc = EXP_ERR_EXPENSE_TOO_SMALL;
		return 0.0F;
	}
	if (NewExpense.GetExpenseAmount() > MAX_ALLOWABLE_EXPENSE) {
		cout << "Eroare! Cheltuielile sunt mai mari decit suma maxima admisa pentru decontare.\n\n";
		rc = EXP_ERR_EXPENSE_TOO_LARGE;
		return 0.0F;
	}
	//afiseaza cheltuielile
	cout << "    " << setw(10) << NewExpense.GetDate();
	cout << setw(35) << NewExpense.GetDescription();
	cout.unsetf(ios::left);
	cout << setw(12) << NewExpense.GetExpenseAmount() << endl << setw(0);
	cout.setf(ios::left);
	return NewExpense.GetExpenseAmount();
}

float ProcessEmployee(ifstream& infile, ErrorCode& rc) {
	Employee NewEmployee;
	float EmployeeTotal = 0.0F;
	unsigned loop;
	//initializarea codului care va fi returnat
	rc = EXP_NO_ERROR;
	//citeste inregistrarea unui angajat din fisier
	infile >> NewEmployee;
	//verifica aparitia eventualelor probleme
	if (NewEmployee.GetNumExpenses() < MIN_NUM_EXPENSES) {
		cout << "Eroare ! Nu exista cheltuieli pentru acest angajat.\n\n";
		rc = EXP_ERR_NO_EXPENSE_ITEMS;
		return 0.0F;
	}
	if (NewEmployee.GetNumExpenses() > MAX_NUM_EXPENSES) {
		cout << "Eroare ! Prea multe inregistrari de cheltuieli pentru acest angajat.\n\n";
		rc = EXP_ERR_TOO_MANY_EXPENSE_ITEMS;
		return 0.0F;
	}
	//afiseaza inregistrarea angajatului
	cout << "Employee #" << NewEmployee.GetID() << endl;
	cout << NewEmployee.GetFirstName() << " ";
	cout << NewEmployee.GetMiddleInitial() << " ";
	cout << NewEmployee.GetLastName() << " ";
	cout << NewEmployee.GetAddress() << " ";
	cout << NewEmployee.GetCity() << " ";
	cout << NewEmployee.GetState() << " ";
	cout << NewEmployee.GetZip() << endl << endl;
	//citeste inregistrarile de cheltuieli
	cout << "    Cheltuieli\n";
	cout << "    __________\n";
	for (loop = 0; loop < NewEmployee.GetNumExpenses(); loop++) {
		EmployeeTotal += ProcessExpenseItem(infile, rc);
		if (rc != EXP_NO_ERROR)
			return 0.0F;
	}
	//verifica aparitia eentualelor probleme
	if (EmployeeTotal > MAX_ALLOWABLE_REIMBURSEMENT) {
		cout << "Eroare! Cheltuielile totale sunt mai mari decit suma maxima admisa pentru decontare.\n\n";
		rc = EXP_ERR_TOTAL_EXPENSE_TOO_LARGE;
		return 0.0F;
	}
	//afiseaza totalul de cheltuieli ale angajatului
	cout << "=======================================\n";
	cout << " Cheltuieli totale:";
	cout.unsetf(ios::left);
	cout << setw(42) << EmployeeTotal << endl << endl << endl;
	cout.setf(ios::left);
	return EmployeeTotal;
}

int main(int argc, char *argv[]) {
	//verifica numarul de argumente din lina de comanda
	if (argc != 2) {
		cout << "USAGE: " << argv[0] << " fileName\n\n";
		return EXIT_FAILURE;
	}
	//deschide fisierul de intrare
	ifstream infile(argv[1], ios::_Nocreate);
	if (!infile) {
		cout << "Expense file\"" << argv[1] << "\" not found.\n\n";
		return EXIT_FAILURE;
	}
	//citeste numarul de angajati
	unsigned EmployeeCount;
	float FileTotal = 0.0F;
	infile >> EmployeeCount;
	if (EmployeeCount < MIN_ALLOWABLE_EMPLOYEES || EmployeeCount > MAX_ALLOWABLE_EMPLOYEES) {
		cout << "Numar invalid de angajati specificat in fisierul de cheltuieli.\n\n";
		infile.close();
	}
	//stabileste smafoarele fluxului de afisare
	cout.setf(ios::left | ios::showpoint | ios::fixed);
	cout.precision(2);
	//afiseaza titlul principal
	cout << "+=============================================+\n";
	cout << "| PROGRAM DE PRELUCRARE A CHELTUIELILOR|\n";
	cout << "|+=============================================+\n\n\n";
	//ciclul principal pentru angajati
	ErrorCode rc;
	do {
		FileTotal += ProcessEmployee(infile, rc);
		if (rc != EXP_NO_ERROR) {
			infile.close();
			return EXIT_FAILURE;
		}
	} while (--EmployeeCount);
	//afiseaza totalul cheltuielilor din fisier
	cout << "+=================================================+\n";
	cout << "|| CHELTUIELI TOTALE: ";
	cout.unsetf(ios::left);
	cout << setw(43) << FileTotal << " |\n";
	cout.setf(ios::left);
	cout << "+=================================================+\n";
	infile.close();
	return EXIT_SUCCESS;
}