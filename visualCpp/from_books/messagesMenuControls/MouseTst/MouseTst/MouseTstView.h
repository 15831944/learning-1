
// MouseTstView.h : interface of the CMouseTstView class
//

#pragma once


class CMouseTstView : public CView
{
protected: // create from serialization only
	CMouseTstView() noexcept;
	DECLARE_DYNCREATE(CMouseTstView)

// Attributes
public:
	CMouseTstDoc* GetDocument() const;

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
	virtual ~CMouseTstView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_ptMouse;
	CString m_szDescriere;
public:
	afx_msg void OnNewmenuTest();
};

#ifndef _DEBUG  // debug version in MouseTstView.cpp
inline CMouseTstDoc* CMouseTstView::GetDocument() const
   { return reinterpret_cast<CMouseTstDoc*>(m_pDocument); }
#endif

