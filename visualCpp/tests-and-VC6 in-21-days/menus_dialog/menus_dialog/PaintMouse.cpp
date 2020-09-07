// PaintMouse.cpp : implementation file
//

#include "stdafx.h"
#include "PaintMouse.h"
#include "afxdialogex.h"
#include <iterator>
#include <algorithm>
#include <functional>
#include "resource.h"


// CPaintMouse dialog

IMPLEMENT_DYNAMIC(CPaintMouse, CDialog)

CPaintMouse::CPaintMouse(CWnd* pParent /*=NULL*/)
	: CDialog(CPaintMouse::IDD, pParent)
{

}

CPaintMouse::~CPaintMouse()
{
	//free the pointer to the lists of CPoint
	std::for_each(m_lpPointList.begin(),m_lpPointList.end(),std::bind1st(std::mem_fun<void,CPaintMouse,list<CPoint>*>(&CPaintMouse::FreeListCPoint),this));
	m_lpPointList.clear();
}

void CPaintMouse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPaintMouse, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_OPERATIONS_RESET,OnReset)
	ON_COMMAND(ID_OPERATIONS_REPAINT,OnRepaint)
END_MESSAGE_MAP()


// CPaintMouse message handlers

void CPaintMouse::OnMouseMove(UINT nFlags,CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		CRect rect,rectClient;
		CPoint offset;
		GetWindowRect(&rect);
		GetClientRect(&rectClient);
		offset=rect.TopLeft();
		offset.x=offset.x+(rect.Width()-rectClient.Width())/2;
		CDC *pDC=GetWindowDC();
		pDC->MoveTo(m_plPointList->back()+offset);
		pDC->LineTo(point+offset);
		ReleaseDC(pDC);
		m_plPointList->push_back(point);
	}
}

void CPaintMouse::OnLButtonDown(UINT nFlags,CPoint point)
{
	m_plPointList=new list<CPoint>;
	m_lpPointList.push_back(m_plPointList);
	m_plPointList->push_back(point);
}

void CPaintMouse::OnPaint(void)
{
	PAINTSTRUCT pPS;
	CDC* pDC=BeginPaint(&pPS);
	for(list<list<CPoint>*>::iterator it=m_lpPointList.begin();it!=m_lpPointList.end();++it)
	{
		if((*it)->empty()==false)
		{
			pDC->MoveTo(*((*it)->begin()));
			std::for_each((*it)->begin(),(*it)->end(),std::bind1st(std::mem_fun(&(CDC::LineTo)),pDC));
		}
	}
	EndPaint(&pPS); 
}

void CPaintMouse::OnRButtonDown(UINT nFlags,CPoint point)
{
	ClientToScreen(&point);
	CMenu opMenu;
	if(opMenu.LoadMenuA(IDR_OPERATIONS)!=TRUE)
	{
		return;
	}
	//get the submenu for popup
	m_pMenuOperations=opMenu.GetSubMenu(0);
	//track the menu
	m_pMenuOperations->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
}

void CPaintMouse::OnReset(void)
{
	std::for_each(m_lpPointList.begin(),m_lpPointList.end(),std::bind1st(std::mem_fun<void,CPaintMouse,list<CPoint>*>(&CPaintMouse::FreeListCPoint),this));
	m_lpPointList.clear();
	InvalidateRect(NULL);
}

void CPaintMouse::OnRepaint(void)
{
	InvalidateRect(NULL);
}