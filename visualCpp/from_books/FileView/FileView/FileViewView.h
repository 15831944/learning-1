
// FileViewView.h : interface of the CFileViewView class
//

#pragma once


class CFileViewView : public CView
{
protected: // create from serialization only
	CFileViewView() noexcept;
	DECLARE_DYNCREATE(CFileViewView)
	int currentLine;
	int margin;
	CFont *ourFont;
	int lHeight;
	int cWidth;
	int saveLHeight;
	int saveCWidth;
	int saveCurrentLine;
	CRect printerRect;

// Attributes
public:
	CFileViewDoc* GetDocument() const;

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
	virtual ~CFileViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
};

#ifndef _DEBUG  // debug version in FileViewView.cpp
inline CFileViewDoc* CFileViewView::GetDocument() const
   { return reinterpret_cast<CFileViewDoc*>(m_pDocument); }
#endif

