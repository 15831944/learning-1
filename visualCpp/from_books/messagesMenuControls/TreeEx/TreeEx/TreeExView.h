
// TreeExView.h : interface of the CTreeExView class
//

#pragma once


class CTreeExView : public CTreeView
{
protected: // create from serialization only
	CTreeExView() noexcept;
	DECLARE_DYNCREATE(CTreeExView)

// Attributes
public:
	CTreeExDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTreeExView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TreeExView.cpp
inline CTreeExDoc* CTreeExView::GetDocument() const
   { return reinterpret_cast<CTreeExDoc*>(m_pDocument); }
#endif

