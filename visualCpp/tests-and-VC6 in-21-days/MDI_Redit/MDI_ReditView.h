// MDI_ReditView.h : interface of the CMDI_ReditView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDI_REDITVIEW_H__417932EF_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_)
#define AFX_MDI_REDITVIEW_H__417932EF_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMDI_ReditCntrItem;

class CMDI_ReditView : public CRichEditView
{
protected: // create from serialization only
	CMDI_ReditView();
	DECLARE_DYNCREATE(CMDI_ReditView)

// Attributes
public:
	CMDI_ReditDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDI_ReditView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDI_ReditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDI_ReditView)
	afx_msg void OnDestroy();
	afx_msg void OnSelectFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDI_ReditView.cpp
inline CMDI_ReditDoc* CMDI_ReditView::GetDocument()
   { return (CMDI_ReditDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDI_REDITVIEW_H__417932EF_A87A_11DB_B910_94EE0AD82B6E__INCLUDED_)
