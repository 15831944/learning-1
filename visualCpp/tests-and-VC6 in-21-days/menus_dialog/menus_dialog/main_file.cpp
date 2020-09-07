//normal include for windows
#include<afxwin.h>
#include "PaintMouse.h"
#include "Buttons.h"
#include "resource.h"

//class for application
class CMainFileApp : public CWinApp
{
public:
	virtual BOOL InitInstance(void);
};

//class for frame window
class CMainFileFrame : public CFrameWnd
{
private:
	BOOL m_bMenuFlag;
	CMenu *m_pMenu;
	CPaintMouse m_cPaintMouse;
	CButtons m_cButtons;
public:
	CMainFileFrame();
protected:
	afx_msg void OnRButtonDown(UINT nflags,CPoint point);
	afx_msg void OnButtons(void);
	afx_msg void OnPaintMouse(void);
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CMainFileFrame,CFrameWnd)
  ON_WM_RBUTTONDOWN()
  ON_COMMAND(ID_PAINTMOUSE,OnPaintMouse)
  ON_COMMAND(ID_BUTTONS,OnButtons)
END_MESSAGE_MAP();

BOOL CMainFileApp::InitInstance(void)
{
	m_pMainWnd=new CMainFileFrame;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMainFileApp myApp;

CMainFileFrame::CMainFileFrame()
{
	Create(NULL,"Menus and dialogs",WS_OVERLAPPEDWINDOW,CRect(0,0,400,400));
}


void CMainFileFrame::OnRButtonDown(UINT nFlags,CPoint point)
{
	ClientToScreen(&point);
	CMenu SelectMenu;
	//load the menu
	if(SelectMenu.LoadMenuA(IDR_SELECT)!=TRUE)
	{
		m_bMenuFlag=FALSE;
		return;
	}
	///get the submenu for popup
	m_pMenu=SelectMenu.GetSubMenu(0);
	//track the menu
	m_bMenuFlag=m_pMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
}

void CMainFileFrame::OnButtons(void)
{
	m_cButtons.DoModal();
}

void CMainFileFrame::OnPaintMouse(void)
{
	m_cPaintMouse.DoModal();
}