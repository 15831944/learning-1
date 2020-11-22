
// EditTestView.h : interface of the CEditTestView class
//

#pragma once


class CEditTestView : public CView
{
protected: // create from serialization only
	CEditTestView() noexcept;
	DECLARE_DYNCREATE(CEditTestView)

// Attributes
public:
	CEditTestDoc* GetDocument() const;

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
	virtual ~CEditTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in EditTestView.cpp
inline CEditTestDoc* CEditTestView::GetDocument() const
   { return reinterpret_cast<CEditTestDoc*>(m_pDocument); }
#endif

