// clientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "client.h"
#include "clientDlg.h"

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
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_port = 0;
	m_recv = _T("");
	m_send = _T("");
	m_error = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Control(pDX, IDC_addr, m_addrctl);
	DDX_Text(pDX, IDC_port, m_port);
	DDX_Text(pDX, IDC_recv, m_recv);
	DDX_Text(pDX, IDC_send, m_send);
	DDX_Text(pDX, IDC_error, m_error);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_connect, Onconnect)
	ON_BN_CLICKED(IDC_end, Onend)
	ON_BN_CLICKED(IDC_request, Onrequest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
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
	m_port=27;
	m_addrctl.SetAddress(127,0,0,1);
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClientDlg::OnPaint() 
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::Onconnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	BYTE field0,field1,field2,field3;
	m_addrctl.GetAddress(field0,field1,field2,field3);
	CString addr;
//	LPCSTR addr_l;
	addr.Format("%d.%d.%d.%d",field0,field1,field2,field3);
//	addr_l=addr.GetBuffer(1000);
	if(m_socket.Create()==0)//m_port,SOCK_STREAM,FD_CLOSE,addr)==0)
	{
		m_error.Empty();
		m_error.Format("Create code=%d",GetLastError());
		UpdateData(FALSE);
		return;
	}
	if(m_socket.Connect(addr,m_port)==0)
	{
		m_error.Empty();
		m_error.Format("Connect Code=%d",GetLastError());
		UpdateData(FALSE);
		return;
	}
	m_error.Empty();
	m_error.Format("Connected to server");
	UpdateData(FALSE);
}
void CClientDlg::Onend() 
{
	// TODO: Add your control notification handler code here
	
}

void CClientDlg::Onrequest() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	LPTSTR buff=m_send.GetBuffer(100);
	m_socket.Send(buff,100);
	m_send.ReleaseBuffer(100);
	LPTSTR inbuff=m_recv.GetBuffer(100);
	m_socket.Receive(inbuff,100);
	m_recv.ReleaseBuffer(100);
	UpdateData(FALSE);
}
