// MDIView.h : interface of the CMDIView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MDIVIEW_H__056A2087_A231_11DB_B910_D50B31D6A328__INCLUDED_)
#define AFX_MDIVIEW_H__056A2087_A231_11DB_B910_D50B31D6A328__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMDIView : public CView
{
protected: // create from serialization only
	CMDIView();
	DECLARE_DYNCREATE(CMDIView)

// Attributes
public:
	CMDIDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMDIView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MDIView.cpp
inline CMDIDoc* CMDIView::GetDocument()
   { return (CMDIDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDIVIEW_H__056A2087_A231_11DB_B910_D50B31D6A328__INCLUDED_)
