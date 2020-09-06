#include<afxwin.h>
#include"resource.h"
//class for main application
class CMenusApp : public CWinApp
{
public:
	virtual BOOL InitInstance(void);
};

class CMenuViews : public CFrameWnd
{
private:
	CString m_sMessage;
	CPoint m_ptLastMouse;
public:
	CMenuViews();
protected:
	afx_msg void OnRButtonDown(UINT nFlags,CPoint point);
	afx_msg void OnFirst(void);
	afx_msg void OnSecond(void);
	afx_msg void OnPaint(void);
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CMenuViews,CFrameWnd)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FIRST,OnFirst)
	ON_COMMAND(ID_SECOND,OnSecond)
	ON_WM_PAINT()
END_MESSAGE_MAP();

BOOL CMenusApp::InitInstance(void)
{
	m_pMainWnd=new CMenuViews;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMenusApp myApp;

CMenuViews::CMenuViews()
{
	m_sMessage.Empty();
	m_ptLastMouse=CPoint(0,0);
	Create(NULL,"floating menu",WS_OVERLAPPEDWINDOW,CRect(0,0,400,400),NULL);
}

void CMenuViews::OnRButtonDown(UINT nFlags,CPoint point)
{
	CMenu ElemMenu;
	m_ptLastMouse=point;
	ClientToScreen(&point);
	ElemMenu.LoadMenu(IDR_POPUP);	
	CMenu * pMenu=ElemMenu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON,point.x,point.y,this);
}

void CMenuViews::OnFirst()
{
	m_sMessage="On First pressed";
	InvalidateRect(NULL);
}

void CMenuViews::OnSecond()
{
	m_sMessage="On second pressed";
	InvalidateRect(NULL);
}

void CMenuViews::OnPaint(void)
{
	PAINTSTRUCT ps;
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20);
	CDC* pDC=BeginPaint(&ps);
	pDC->DrawText(m_sMessage,rect,DT_SINGLELINE);
	EndPaint(&ps);
}
