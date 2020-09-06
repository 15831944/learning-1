// TaskingDoc.h : interface of the CTaskingDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKINGDOC_H__D9252375_91F7_4ED0_879C_BC9DD44F2A59__INCLUDED_)
#define AFX_TASKINGDOC_H__D9252375_91F7_4ED0_879C_BC9DD44F2A59__INCLUDED_

#include "Spinner.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTaskingDoc : public CDocument
{
protected: // create from serialization only
	CTaskingDoc();
	DECLARE_DYNCREATE(CTaskingDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskingDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	void SuspendSpinner(int nIndex,BOOL bSuspend);
	void DoSpin(int nIndex);
	virtual ~CTaskingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTaskingDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CWinThread *m_pSpinThread[2];
	static UINT ThreadFunc(LPVOID pParam);
	void InitSpinners();
	void CalcPoint(int nID,CSpinner *pSpin);
	CSpinner m_cSpin[4];
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKINGDOC_H__D9252375_91F7_4ED0_879C_BC9DD44F2A59__INCLUDED_)
