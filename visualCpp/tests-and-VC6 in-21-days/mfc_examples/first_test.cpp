//header include
#include<afxwin.h>

//declare the main app class
class CHelloApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CHelloWindows: public CFrameWnd
{
private:
	CStatic* cs;
public:
	CHelloWindows();
};

BOOL CHelloApp::InitInstance()
{
	m_pMainWnd=new CHelloWindows();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CHelloWindows::CHelloWindows()
{
	Create(NULL,"Hello world",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//create static label
	cs=new CStatic();
	cs->Create("Hello World",WS_CHILD|WS_VISIBLE|SS_CENTER,CRect(50,80,150,150),this);
}

CHelloApp myApp;