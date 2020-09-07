// day11Doc.h : interface of the CDay11Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAY11DOC_H__6414AA12_DB53_4F84_9071_21BE095C6EFA__INCLUDED_)
#define AFX_DAY11DOC_H__6414AA12_DB53_4F84_9071_21BE095C6EFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"

class CDay11Doc : public CDocument
{
protected: // create from serialization only
	CDay11Doc();
	DECLARE_DYNCREATE(CDay11Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay11Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	UINT GetColor();
	static const COLORREF m_crColors[8];
	CLine *GetLine(int nIndex);
	int GetLineCount();
	CLine* AddLine(CPoint ptFrom,CPoint ptTo);
	virtual ~CDay11Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnColorCommand(UINT nID);
	afx_msg void OnUpdateColorUI(CCmdUI *pCmdUI);
	//{{AFX_MSG(CDay11Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	UINT m_nColor;
	CObArray m_oaLines;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY11DOC_H__6414AA12_DB53_4F84_9071_21BE095C6EFA__INCLUDED_)
