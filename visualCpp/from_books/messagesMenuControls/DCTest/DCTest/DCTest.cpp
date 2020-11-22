
// DCTest.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "DCTest.h"
#include "MainFrm.h"

#include "DCTestDoc.h"
#include "DCTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDCTestApp

BEGIN_MESSAGE_MAP(CDCTestApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CDCTestApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CDCTestApp construction

CDCTestApp::CDCTestApp() noexcept
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("DCTest.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CDCTestApp object

CDCTestApp theApp;


// CDCTestApp initialization

BOOL CDCTestApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDCTestDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CDCTestView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int CDCTestApp::ExitInstance()
{
	//TODO: handle additional resources you may have added
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CDCTestApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;
	virtual ~CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIconOkay;
	HICON m_hIconCancel;
// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	CButton m_btnOkay;
	CButton m_btnCancel;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnDestroy();
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

CAboutDlg::~CAboutDlg() {
	DestroyIcon(m_hIconOkay);
	DestroyIcon(m_hIconCancel);
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_btnOkay);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	ON_WM_MOVE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// App command to run the dialog
void CDCTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CDCTestApp message handlers





BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetCapture();
	BeginWaitCursor();
	SetTimer(1, 1500, NULL);
	/* move to OnTimer
	CWinApp* pApp = AfxGetApp();
	if (pApp != 0) {
		m_hIconOkay = pApp->LoadIconW(IDI_GREEN);
		m_hIconCancel = pApp->LoadIconW(IDI_RED);
		m_btnOkay.SetIcon(m_hIconOkay);
		m_btnCancel.SetIcon(m_hIconCancel);
	}
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	//cursoare windows standard
	/*
	IDC_ARROW cursor sageata
	IDC_IBEAM cursor bara
	IDC_WAIT cursor clepsidra
	IDC_CROSS cursor cruce
	IDC_UPARROW cursor sageata orientata in sus
	IDC_SIZENWSE cursor de dimensionare orientat nord-vest si sud-est
	IDC_SIZENESW cursor de dimensionare orientat nord - est si sud - vest
	IDC_SIZEWE cursor de dimensionare orientat vest - est
	IDC_SIZENS cursor de dimensionare orientat nord - sud
	IDC_SIZEALL cursor de dimensionare orientat in cele patru directii
	IDC_NO cursor NU
	IDC_APPSTARTING cursor de lansare a aplicatiei
	IDC_HELP cursor de help
	IDI_APPLICATION pictograma de aplicatie
	IDI_HAND prictograma stop
	IDI_QUESTION pictograma de inbtrebare
	IDI_EXCLAMATION pictograma de exclamare
	IDI_ASTERISK asterisc sau pictograma de informare
	IDI_WINLOG pictograma sigla windows
	*/
	//incarca si seteaza noul cursor for all 
	/*
	CWinApp* pApp = AfxGetApp();
	HICON hIconBang = pApp->LoadCursorW(IDC_BANG);
	SetCursor(hIconBang);
	return TRUE;
	*/
	BOOL bReturn;
	CRect rcBtn;
	CPoint ptCursor;
	//calculeaza pozitia curenta a cursorului si-i modifica forma daca nu se afla deasupra butonului OK
	CWnd* pBtn = GetDlgItem(IDOK);
	pBtn->GetWindowRect(rcBtn);
	GetCursorPos(&ptCursor);
	if (rcBtn.PtInRect(ptCursor) == FALSE) {
		//incarca si seteaza noul cursor. return true pt a opri procesarea acestui mesaj
		CWinApp* pApp = AfxGetApp();
		HICON hIconBang = pApp->LoadCursorW(IDC_BANG);
		SetCursor(hIconBang);
		bReturn = TRUE;
	}
	else {
		//ne aflam deasupra butonului Ok vom folosi cursoul prestabilit.
		bReturn = CDialogEx::OnSetCursor(pWnd, nHitTest, message);
	}
	return bReturn;
}


void CAboutDlg::OnTimer(UINT_PTR nIDEvent)
{
	ReleaseCapture();
	EndWaitCursor();
	KillTimer(1);
	CWinApp* pApp = AfxGetApp();
	if (pApp != 0) {
		m_hIconOkay = pApp->LoadIconW(IDI_GREEN);
		m_hIconCancel = pApp->LoadIconW(IDI_RED);
		m_btnOkay.SetIcon(m_hIconOkay);
		m_btnCancel.SetIcon(m_hIconCancel);
	}
}


void CAboutDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);
	CRect rcCursor;
	GetWindowRect(&rcCursor);
	ClipCursor(&rcCursor);
}


void CAboutDlg::OnDestroy()
{
	ClipCursor(NULL);
	CDialogEx::OnDestroy();

}
