// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "day11.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
	
IMPLEMENT_SERIAL (CLine,CObject,1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{

}

CLine::~CLine()
{

}

CLine::CLine(CPoint ptFrom, CPoint ptTo,COLORREF crColor)
{
	//Initialize the from and to points
	m_ptFrom=ptFrom;
	m_ptTo=ptTo;
	m_crColor=crColor;
}

CLine::Draw(CDC *pDC)
{
	CPen lpen(PS_SOLID,1,m_crColor);
	CPen *pOldPen=pDC->SelectObject(&lpen);
	//Draw the line
	pDC->MoveTo(m_ptFrom);
	pDC->LineTo(m_ptTo);
	pDC->SelectObject(pOldPen);
}

void CLine::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
		ar<<m_ptFrom<<m_ptTo<<m_crColor;
	else
		ar>>m_ptFrom>>m_ptTo>>m_crColor;
}
