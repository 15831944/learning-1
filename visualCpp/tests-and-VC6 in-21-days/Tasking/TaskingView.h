// TaskingView.h : interface of the CTaskingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKINGVIEW_H__8C489BE4_79C1_4976_A166_9889837AAA44__INCLUDED_)
#define AFX_TASKINGVIEW_H__8C489BE4_79C1_4976_A166_9889837AAA44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTaskingView : public CFormView
{
protected: // create from serialization only
	CTaskingView();
	DECLARE_DYNCREATE(CTaskingView)

public:
	//{{AFX_DATA(CTaskingView)
	enum { IDD = IDD_TASKING_FORM };
	BOOL	m_bOnIdle1;
	BOOL	m_bOnIdle2;
	BOOL	m_bThread1;
	BOOL	m_bThread2;
	//}}AFX_DATA

// Attributes
public:
	CTaskingDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskingView)
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
	virtual ~CTaskingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTaskingView)
	afx_msg void OnCbonidle();
	afx_msg void OnCbthread1();
	afx_msg void OnCbthread2();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TaskingView.cpp
inline CTaskingDoc* CTaskingView::GetDocument()
   { return (CTaskingDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKINGVIEW_H__8C489BE4_79C1_4976_A166_9889837AAA44__INCLUDED_)
