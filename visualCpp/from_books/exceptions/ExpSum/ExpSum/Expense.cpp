#include "Expense.h"

using namespace std;

Expense::Expense() :ExpenseAmount(0.0F) {

}

ostream& operator<<(ostream& ostr, const Expense& expense) {
	ostr << expense.Date << " ";
	ostr << expense.Description << endl;
	ostr << expense.ExpenseAmount << " ";
	return ostr;
}
istream& operator>>(istream& istr, Expense& expense) {
	char TempBuffer[256];
	istr >> TempBuffer;
	expense.Date = TempBuffer;
	istr.getline(TempBuffer, 256);
	expense.Description = TempBuffer;
	istr >> expense.ExpenseAmount;
	return istr;
}