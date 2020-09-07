// day2_controlsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "day2_controls.h"
#include "day2_controlsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay2_controlsDlg dialog

CDay2_controlsDlg::CDay2_controlsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDay2_controlsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDay2_controlsDlg)
	m_strMessage = _T("");
	m_strProgToRun = _T("");
	m_bEnableMsg = FALSE;
	m_bEnablePrg = FALSE;
	m_bShowMsg = FALSE;
	m_bShowPrg = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDay2_controlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDay2_controlsDlg)
	DDX_Text(pDX, IDC_MSG, m_strMessage);
	DDX_CBString(pDX, IDC_PRGTORUN, m_strProgToRun);
	DDX_Check(pDX, IDC_CKENBLMSG, m_bEnableMsg);
	DDX_Check(pDX, IDC_CKENBLPRG, m_bEnablePrg);
	DDX_Check(pDX, IDC_CKSHWMSG, m_bShowMsg);
	DDX_Check(pDX, IDC_CKSHWPRG, m_bShowPrg);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDay2_controlsDlg, CDialog)
	//{{AFX_MSG_MAP(CDay2_controlsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_CLRMSG, OnClrmsg)
	ON_BN_CLICKED(IDC_DFLTMSG, OnDfltmsg)
	ON_BN_CLICKED(IDC_CKENBLMSG, OnCkenblmsg)
	ON_BN_CLICKED(IDC_SHOWMSG, OnShowmsg)
	ON_BN_CLICKED(IDC_CKSHWMSG, OnCkshwmsg)
	ON_BN_CLICKED(IDC_RUNPGM, OnRunpgm)
	ON_BN_CLICKED(IDC_CKENBLPRG, OnCkenblprg)
	ON_BN_CLICKED(IDC_CKSHWPRG, OnCkshwprg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay2_controlsDlg message handlers

BOOL CDay2_controlsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//MY CODE
	m_strMessage="Enter a message here";
	m_bShowMsg=TRUE;
	m_bShowPrg=TRUE;
	m_bEnableMsg=TRUE;
	m_bEnablePrg=TRUE;
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDay2_controlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDay2_controlsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDay2_controlsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDay2_controlsDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
	
}

void CDay2_controlsDlg::OnClrmsg() 
{
	// TODO: Add your control notification handler code here
	m_strMessage="";
	UpdateData(FALSE);
}

void CDay2_controlsDlg::OnDfltmsg() 
{
	// TODO: Add your control notification handler code here
	m_strMessage="Enter a message here";
	UpdateData(FALSE);
}

void CDay2_controlsDlg::OnCkenblmsg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_bEnableMsg==TRUE)
	{
		GetDlgItem(IDC_MSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_SHOWMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_DFLTMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_CLRMSG)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATICMSG)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_MSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_SHOWMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_DFLTMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_CLRMSG)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATICMSG)->EnableWindow(FALSE);
	}
}

void CDay2_controlsDlg::OnShowmsg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	MessageBox(m_strMessage);
}

void CDay2_controlsDlg::OnCkshwmsg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_bShowMsg==TRUE)
	{
		GetDlgItem(IDC_MSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_SHOWMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_DFLTMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_CLRMSG)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATICMSG)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_MSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_SHOWMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_DFLTMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_CLRMSG)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATICMSG)->ShowWindow(FALSE);
	}
}

void CDay2_controlsDlg::OnRunpgm() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString strPrgName;
	strPrgName=m_strProgToRun;
	strPrgName.MakeUpper();
	if(strPrgName=="PAINT")
		WinExec("pbrush.exe",SW_SHOW);
	if(strPrgName=="SOLITAIRE")
		WinExec("sol.exe",SW_SHOW);
	if(strPrgName=="NOTEPAD")
		WinExec("notepad.exe",SW_SHOW);
	if(strPrgName=="SPIDER")
		WinExec("spider.exe",SW_SHOW);
}


void CDay2_controlsDlg::OnCkenblprg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_bEnablePrg==TRUE)
	{
		GetDlgItem(IDC_PRGTORUN)->EnableWindow(TRUE);
		GetDlgItem(IDC_STATICPGM)->EnableWindow(TRUE);
		GetDlgItem(IDC_RUNPGM)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_PRGTORUN)->EnableWindow(FALSE);
		GetDlgItem(IDC_STATICPGM)->EnableWindow(FALSE);
		GetDlgItem(IDC_RUNPGM)->EnableWindow(FALSE);
	}
}

void CDay2_controlsDlg::OnCkshwprg() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_bShowPrg==TRUE)
	{
		GetDlgItem(IDC_PRGTORUN)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATICPGM)->ShowWindow(TRUE);
		GetDlgItem(IDC_RUNPGM)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_PRGTORUN)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATICPGM)->ShowWindow(FALSE);
		GetDlgItem(IDC_RUNPGM)->ShowWindow(FALSE);
	}	
}
