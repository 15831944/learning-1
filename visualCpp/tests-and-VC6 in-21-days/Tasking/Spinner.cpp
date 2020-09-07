// Spinner.cpp: implementation of the CSpinner class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <math.h>
#include "Tasking.h"
#include "Spinner.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

COLORREF CSpinner::m_crColors[8]={
	RGB(0,0,0),
	RGB(0,0,255),
	RGB(0,255,0),
	RGB(0,255,255),
	RGB(255,0,0),
	RGB(255,0,255),
	RGB(255,255,0),
	RGB(255,255,255)
};

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpinner::CSpinner()
{
	m_iRadius=0;
	m_nMinute=0;
	m_crColor=0;
	m_pViewWnd=NULL;
	m_bContinue=NULL;
}

CSpinner::~CSpinner()
{

}

void CSpinner::Draw()
{
	CDC *pDC=m_pViewWnd->GetDC();
	pDC->SetMapMode(MM_LOENGLISH);
	CPoint org=m_pCenter;
	CPoint pStartPoint;
	pStartPoint.x=(m_iRadius/2);
	pStartPoint.y=(m_iRadius/2);
	org.x=m_pCenter.x+(m_iRadius/2);
	org.y=m_pCenter.y+m_iRadius;
	pDC->SetViewportOrg(org.x,org.y);
	CPoint pEndPoint;
	double nRadians=(double )(m_nMinute*6)*0.017453292;
	pEndPoint.x=(int)(m_iRadius*sin(nRadians));
	pEndPoint.y=(int)(m_iRadius*cos(nRadians));
	CPen pen(PS_SOLID,0,m_crColors[m_crColor]);
	CPen* pOldPen=pDC->SelectObject(&pen);
	pDC->MoveTo(pEndPoint);
	pDC->LineTo(pStartPoint);
	pDC->SelectObject(&pOldPen);
	m_pViewWnd->ReleaseDC(pDC);
	if(++m_nMinute==60)
	{
		m_nMinute=0;
		if(++m_crColor==8) m_crColor=0;
	}
}
