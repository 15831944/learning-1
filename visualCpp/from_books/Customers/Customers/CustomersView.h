
// CustomersView.h : interface of the CCustomersView class
//

#pragma once


class CCustomersView : public CView
{
protected: // create from serialization only
	CCustomersView() noexcept;
	DECLARE_DYNCREATE(CCustomersView)

// Attributes
public:
	CCustomersDoc* GetDocument() const;

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
	virtual ~CCustomersView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // debug version in CustomersView.cpp
inline CCustomersDoc* CCustomersView::GetDocument() const
   { return reinterpret_cast<CCustomersDoc*>(m_pDocument); }
#endif

