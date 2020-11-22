
// TabExampleView.h : interface of the CTabExampleView class
//

#pragma once


class CTabExampleView : public CView
{
protected: // create from serialization only
	CTabExampleView() noexcept;
	DECLARE_DYNCREATE(CTabExampleView)

// Attributes
public:
	CTabExampleDoc* GetDocument() const;

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
	virtual ~CTabExampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TabExampleView.cpp
inline CTabExampleDoc* CTabExampleView::GetDocument() const
   { return reinterpret_cast<CTabExampleDoc*>(m_pDocument); }
#endif

