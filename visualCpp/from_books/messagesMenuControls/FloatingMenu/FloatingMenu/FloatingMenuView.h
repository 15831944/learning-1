
// FloatingMenuView.h : interface of the CFloatingMenuView class
//

#pragma once


class CFloatingMenuView : public CView
{
protected: // create from serialization only
	CFloatingMenuView() noexcept;
	DECLARE_DYNCREATE(CFloatingMenuView)

// Attributes
public:
	CFloatingMenuDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CFloatingMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CPoint m_ptMsg;
	CString m_szMsg;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLei();
	afx_msg void OnTigri();
	afx_msg void OnHello();
};

#ifndef _DEBUG  // debug version in FloatingMenuView.cpp
inline CFloatingMenuDoc* CFloatingMenuView::GetDocument() const
   { return reinterpret_cast<CFloatingMenuDoc*>(m_pDocument); }
#endif

