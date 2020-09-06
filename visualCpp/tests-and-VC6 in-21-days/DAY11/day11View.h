// day11View.h : interface of the CDay11View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAY11VIEW_H__1BDBE104_377D_40AD_A32A_0193A61990C2__INCLUDED_)
#define AFX_DAY11VIEW_H__1BDBE104_377D_40AD_A32A_0193A61990C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDay11View : public CView
{
protected: // create from serialization only
	CDay11View();
	DECLARE_DYNCREATE(CDay11View)

// Attributes
public:
	CDay11Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay11View)
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
	virtual ~CDay11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

private:
	CPoint m_ptPrevPos;
// Generated message map functions
protected:
	//{{AFX_MSG(CDay11View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in day11View.cpp
inline CDay11Doc* CDay11View::GetDocument()
   { return (CDay11Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY11VIEW_H__1BDBE104_377D_40AD_A32A_0193A61990C2__INCLUDED_)
