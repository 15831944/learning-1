
// SubclassView.h : interface of the CSubclassView class
//

#pragma once


class CSubclassView : public CView
{
protected: // create from serialization only
	CSubclassView() noexcept;
	DECLARE_DYNCREATE(CSubclassView)

// Attributes
public:
	CSubclassDoc* GetDocument() const;

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
	virtual ~CSubclassView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SubclassView.cpp
inline CSubclassDoc* CSubclassView::GetDocument() const
   { return reinterpret_cast<CSubclassDoc*>(m_pDocument); }
#endif

