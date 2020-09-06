// day10Doc.h : interface of the CDay10Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAY10DOC_H__41137708_9422_456B_ABDE_26EAA737993C__INCLUDED_)
#define AFX_DAY10DOC_H__41137708_9422_456B_ABDE_26EAA737993C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Line.h"

class CDay10Doc : public CDocument
{
protected: // create from serialization only
	CDay10Doc();
	DECLARE_DYNCREATE(CDay10Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDay10Doc)
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
	CObArray m_oaLines;
	virtual ~CDay10Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDay10Doc)
	afx_msg void OnColorBlack();
	afx_msg void OnUpdateColorBlack(CCmdUI* pCmdUI);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnColorCyan();
	afx_msg void OnUpdateColorCyan(CCmdUI* pCmdUI);
	afx_msg void OnColorGreen();
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnColorMagenta();
	afx_msg void OnUpdateColorMagenta(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnColorRed();
	afx_msg void OnColorWhite();
	afx_msg void OnUpdateColorWhite(CCmdUI* pCmdUI);
	afx_msg void OnColorYellow();
	afx_msg void OnUpdateColorYellow(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	UINT m_nColor;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAY10DOC_H__41137708_9422_456B_ABDE_26EAA737993C__INCLUDED_)
