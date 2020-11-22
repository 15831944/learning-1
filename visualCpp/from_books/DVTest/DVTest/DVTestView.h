
// DVTestView.h : interface of the CDVTestView class
//

#pragma once


class CDVTestView : public CView
{
protected: // create from serialization only
	CDVTestView() noexcept;
	DECLARE_DYNCREATE(CDVTestView)

// Attributes
public:
	CDVTestDoc* GetDocument() const;

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
	virtual ~CDVTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DVTestView.cpp
inline CDVTestDoc* CDVTestView::GetDocument() const
   { return reinterpret_cast<CDVTestDoc*>(m_pDocument); }
#endif

