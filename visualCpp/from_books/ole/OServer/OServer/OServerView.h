
// OServerView.h : interface of the COServerView class
//

#pragma once


class COServerView : public CView
{
protected: // create from serialization only
	COServerView() noexcept;
	DECLARE_DYNCREATE(COServerView)

// Attributes
public:
	COServerDoc* GetDocument() const;

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
	virtual ~COServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnCancelEditSrvr();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OServerView.cpp
inline COServerDoc* COServerView::GetDocument() const
   { return reinterpret_cast<COServerDoc*>(m_pDocument); }
#endif

