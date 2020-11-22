
// RichTextView.h : interface of the CRichTextView class
//

#pragma once

class CRichTextCntrItem;

class CRichTextView : public CRichEditView
{
protected: // create from serialization only
	CRichTextView() noexcept;
	DECLARE_DYNCREATE(CRichTextView)

// Attributes
public:
	CRichTextDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CRichTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in RichTextView.cpp
inline CRichTextDoc* CRichTextView::GetDocument() const
   { return reinterpret_cast<CRichTextDoc*>(m_pDocument); }
#endif

