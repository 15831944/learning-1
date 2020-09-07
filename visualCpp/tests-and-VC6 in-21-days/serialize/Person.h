// Person.h: interface for the CPerson class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSON_H__2696B9A5_2338_4E1E_81DC_65370A4E84AA__INCLUDED_)
#define AFX_PERSON_H__2696B9A5_2338_4E1E_81DC_65370A4E84AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPerson : public CObject  
{
	DECLARE_SERIAL(CPerson)
public:
	virtual void Serialize(CArchive &ar);
	//functions for setting the variables
	void SetEmployed(BOOL bEmployed) {m_bEmployed=bEmployed;}
	void SetMaritalStatus(int iStat) {m_iMaritalStatus=iStat;}
	void SetAge(int iAge) {m_iAge=iAge;}
	void SetName(CString sName) {m_sName=sName;}
	//functions for getting the current settings of the variables
	BOOL GetEmployed(){return m_bEmployed;}
	int GetMaritalStatus(){return m_iMaritalStatus;}
	int GetAge(){return m_iAge;}
	CString GetName(){return m_sName;}
	CPerson();
	virtual ~CPerson();

private:
	int m_iAge;
	BOOL m_bEmployed;
	CString m_sName;
	int m_iMaritalStatus;
};

#endif // !defined(AFX_PERSON_H__2696B9A5_2338_4E1E_81DC_65370A4E84AA__INCLUDED_)
