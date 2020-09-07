//fist_test.cpp
#include<afxwin.h>

//declare application class
class CHelloApp: public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//declare the main window class
class CHelloWindow: public CFrameWnd
{
	CStatic* cs;
public:
	CHelloWindow();
};

//the initinstance function is called each time the application first executes
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd=new CHelloWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

//constructor for the windows class
CHelloWindow::CHelloWindow()
{
	//create the window itself
	Create(NULL,"Hello World",WS_OVERLAPPEDWINDOW,CRect(0,0,200,200));
	//create the static label
	cs=new CStatic();
	cs->Create("Hello World",WS_CHILD|WS_VISIBLE|SS_CENTER,CRect(50,80,150,150),this);
}

//Create an instance of the application data
CHelloApp HelloApp;