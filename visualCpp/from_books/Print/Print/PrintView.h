
// PrintView.h : interface of the CPrintView class
//

#pragma once


class CPrintView : public CView
{
protected: // create from serialization only
	CPrintView() noexcept;
	DECLARE_DYNCREATE(CPrintView)

// Attributes
public:
	CPrintDoc* GetDocument() const;

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
	virtual ~CPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CFont* m_pFntNormal;
	CFont* m_pFntBanner;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};

#ifndef _DEBUG  // debug version in PrintView.cpp
inline CPrintDoc* CPrintView::GetDocument() const
   { return reinterpret_cast<CPrintDoc*>(m_pDocument); }
#endif

