
// CtrlBarView.h : interface of the CCtrlBarView class
//

#pragma once


class CCtrlBarView : public CView
{
protected: // create from serialization only
	CCtrlBarView() noexcept;
	DECLARE_DYNCREATE(CCtrlBarView)

// Attributes
public:
	CCtrlBarDoc* GetDocument() const;

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
	virtual ~CCtrlBarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CtrlBarView.cpp
inline CCtrlBarDoc* CCtrlBarView::GetDocument() const
   { return reinterpret_cast<CCtrlBarDoc*>(m_pDocument); }
#endif

