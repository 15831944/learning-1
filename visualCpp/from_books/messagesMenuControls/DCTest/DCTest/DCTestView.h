
// DCTestView.h : interface of the CDCTestView class
//

#pragma once


class CDCTestView : public CView
{
protected: // create from serialization only
	CDCTestView() noexcept;
	DECLARE_DYNCREATE(CDCTestView)

// Attributes
public:
	CDCTestDoc* GetDocument() const;

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
	virtual ~CDCTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CMap <int, int, CString, CString> m_map;
	int m_nMapMode;
	int m_cxEllipse;
	int m_cyEllipse;
	int m_nPenWidth;
	COLORREF m_clrOptiune;
	LOGFONT m_logFont;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewMapmode();
	afx_msg void OnViewFont();
};

#ifndef _DEBUG  // debug version in DCTestView.cpp
inline CDCTestDoc* CDCTestView::GetDocument() const
   { return reinterpret_cast<CDCTestDoc*>(m_pDocument); }
#endif

