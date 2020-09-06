// day10View.h : interface of the CDay10View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAY10VIEW_H__00E80140_7AB0_4417_860B_44837B3C9AFA__INCLUDED_)
#define AFX_DAY10VIEW_H__00E80140_7AB0_4417_860B_44837B3C9AFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"

class CDay10View : public CView
{
protected: // create from serialization only
	CDay10View();
	DECLARE_DYNCREATE(CDay10View)

// Attributes
public:
	CDay10Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay10View)
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
	virtual ~CDay10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDay10View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_ptPrevPos;
};

#ifndef _DEBUG  // debug version in day10View.cpp
inline CDay10Doc* CDay10View::GetDocument()
   { return (CDay10Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY10VIEW_H__00E80140_7AB0_4417_860B_44837B3C9AFA__INCLUDED_)
