
// ImageListView.h : interface of the CImageListView class
//

#pragma once


class CImageListView : public CView
{
protected: // create from serialization only
	CImageListView() noexcept;
	DECLARE_DYNCREATE(CImageListView)

// Attributes
public:
	CImageListDoc* GetDocument() const;

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
	virtual ~CImageListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL AddBitmapToImageList(UINT nResourceID);
	CImageList m_imageList;

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageListView.cpp
inline CImageListDoc* CImageListView::GetDocument() const
   { return reinterpret_cast<CImageListDoc*>(m_pDocument); }
#endif

