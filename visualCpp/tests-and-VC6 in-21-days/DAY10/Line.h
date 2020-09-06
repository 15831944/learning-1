// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__54379CAE_1FB1_422B_B2DD_139364BB061A__INCLUDED_)
#define AFX_LINE_H__54379CAE_1FB1_422B_B2DD_139364BB061A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLine : public CObject  
{
	DECLARE_SERIAL(CLine)
public:
	CLine(CPoint ptFrom,CPoint ptTo,UINT nWidth,COLORREF crColor);
public:
	void Serialize(CArchive &ar);
	Draw(CDC *pDC);
	CLine(CPoint ptFrom,CPoint ptTo,COLORREF crColor);
	CLine();
	virtual ~CLine();

private:
	COLORREF m_crColor;
	CPoint m_ptTo;
	CPoint m_ptFrom;
};

#endif // !defined(AFX_LINE_H__54379CAE_1FB1_422B_B2DD_139364BB061A__INCLUDED_)
