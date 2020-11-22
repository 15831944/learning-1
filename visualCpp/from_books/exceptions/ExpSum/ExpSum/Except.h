#pragma once
#include <eh.h>
#include <afx.h>

//coduri de eroare
typedef enum {
	EXP_NO_ERROR,
	EXP_ERR_EXPENSE_TOO_SMALL,
	EXP_ERR_EXPENSE_TOO_LARGE,
	EXP_ERR_NO_EXPENSE_ITEMS,
	EXP_ERR_TOO_MANY_EXPENSE_ITEMS,
	EXP_ERR_TOTAL_EXPENSE_TOO_LARGE,
	EXP_GENERIC_ERROR
} ErrorCode;

//clasa de baza a exceptiilor
class ExpException {
public:
	ExpException(ErrorCode NewErrorCode, const char *NewReason = NULL) : TheError(NewErrorCode), TheReason(NewReason) {};
	void SetErrorCode(ErrorCode NewErrorCode) {
		TheError = NewErrorCode;
	}
	void SetReason(const char *NewReason) {
		TheReason = NewReason;
	}
	CString Why() const {
		return TheReason;
	}
	ErrorCode GetErrorCode() const {
		return TheError;
	}
private:
	CString TheReason;
	ErrorCode TheError;
};

//clase de exceptii specifice
class ExpenseTooSmall : public ExpException {
public:
	ExpenseTooSmall() : ExpException(EXP_ERR_EXPENSE_TOO_SMALL, "Cheltuielile sunt mai mici decit suma minima admisa pentru decontare.") {}
};

class ExpenseTooLarge : public ExpException {
public:
	ExpenseTooLarge() : ExpException(EXP_ERR_EXPENSE_TOO_LARGE, "Cheltuielile sunt mai mari decit suma maxima admisa pentru decontare.") {}
};

class EmployeeException : public ExpException {
public:
	EmployeeException(ErrorCode NewErrorCode, unsigned NewEmployeeID, const char *NewReason = NULL) : ExpException(NewErrorCode, NewReason), EmployeeID(NewEmployeeID) {}
	unsigned GetEmployeeID() const {
		return EmployeeID;
	}
private:
	unsigned EmployeeID;
};

class NoExpenseItems : public EmployeeException {
public:
	NoExpenseItems(unsigned NewEmployeeID) : EmployeeException(EXP_ERR_NO_EXPENSE_ITEMS, NewEmployeeID, "Nu exista cheltuieli pentru acest angajat.") {}
};

class TooManyExpenseItems : public EmployeeException {
public:
	TooManyExpenseItems(unsigned NewEmployeeID) : EmployeeException(EXP_ERR_TOO_MANY_EXPENSE_ITEMS, NewEmployeeID, "Prea multe cheltuieli pentru acest angajat ") {}
};

class ExpenseTotalTooLarge : public ExpException {
public:
	ExpenseTotalTooLarge() : ExpException(EXP_ERR_TOTAL_EXPENSE_TOO_LARGE, "Cheltuielile totale sunt mai mari decit suma maxima admisa pentru decontare.") {}
};