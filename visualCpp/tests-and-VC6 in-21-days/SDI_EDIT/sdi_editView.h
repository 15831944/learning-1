// sdi_editView.h : interface of the CSdi_editView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDI_EDITVIEW_H__A2BEF54B_A7E3_11DB_B910_C96105C64945__INCLUDED_)
#define AFX_SDI_EDITVIEW_H__A2BEF54B_A7E3_11DB_B910_C96105C64945__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSdi_editView : public CEditView
{
protected: // create from serialization only
	CSdi_editView();
	DECLARE_DYNCREATE(CSdi_editView)

// Attributes
public:
	CSdi_editDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSdi_editView)
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
	CFont* cfont;
	virtual ~CSdi_editView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CSdi_editView)
	afx_msg void OnSetFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sdi_editView.cpp
inline CSdi_editDoc* CSdi_editView::GetDocument()
   { return (CSdi_editDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDI_EDITVIEW_H__A2BEF54B_A7E3_11DB_B910_C96105C64945__INCLUDED_)
