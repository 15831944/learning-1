#pragma once
#include <iostream>
#include <afx.h>

class Expense
{
public:
	Expense();
	void SetDate(const char * NewDate) {
		Date = NewDate;
	}
	void SetDescription(const char *NewDescription) {
		Description = NewDescription;
	}
	void SetExpenseAmount(float NewExpenseAmount) {
		ExpenseAmount = NewExpenseAmount;
	}
	CString GetDate() const {
		return Date;
	}
	CString GetDescription() const {
		return Description;
	}
	float GetExpenseAmount() const {
		return ExpenseAmount;
	}
private:
	CString Date;
	CString Description;
	float ExpenseAmount;
	friend std::ostream& operator<<(std::ostream& ostr, const Expense& expense);
	friend std::istream& operator>>(std::istream& istr, Expense& expense);
};

