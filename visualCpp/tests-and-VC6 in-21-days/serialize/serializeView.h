// serializeView.h : interface of the CSerializeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERIALIZEVIEW_H__619A04D5_F76E_4CAF_A256_988A6EE1BABD__INCLUDED_)
#define AFX_SERIALIZEVIEW_H__619A04D5_F76E_4CAF_A256_988A6EE1BABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSerializeView : public CFormView
{
protected: // create from serialization only
	CSerializeView();
	DECLARE_DYNCREATE(CSerializeView)

public:
	//{{AFX_DATA(CSerializeView)
	enum { IDD = IDD_SERIALIZE_FORM };
	BOOL	m_bEmployed;
	int		m_iAge;
	CString	m_sName;
	CString	m_sPosition;
	int		m_iMaritalStatus;
	//}}AFX_DATA

// Attributes
public:
	CSerializeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSerializeView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void NewDataSet();
	virtual ~CSerializeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSerializeView)
	afx_msg void OnBfirst();
	afx_msg void OnBlast();
	afx_msg void OnBnext();
	afx_msg void OnBprev();
	afx_msg void OnCbemployed();
	afx_msg void OnChangeEage();
	afx_msg void OnChangeEname();
	afx_msg void OnRMaritalStat();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void PopulateView();
	CPerson * m_pCurPerson;
};

#ifndef _DEBUG  // debug version in serializeView.cpp
inline CSerializeDoc* CSerializeView::GetDocument()
   { return (CSerializeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERIALIZEVIEW_H__619A04D5_F76E_4CAF_A256_988A6EE1BABD__INCLUDED_)
