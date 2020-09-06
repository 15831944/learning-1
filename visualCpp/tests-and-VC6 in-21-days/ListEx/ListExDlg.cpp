// ListExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListEx.h"
#include "ListExDlg.h"

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
// CListExDlg dialog

CListExDlg::CListExDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListExDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListExDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListExDlg)
	DDX_Control(pDX, IDC_lista, m_listctrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListExDlg, CDialog)
	//{{AFX_MSG_MAP(CListExDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_ICON, OnRadioIcon)
	ON_BN_CLICKED(IDC_RADIO_REPORT, OnRadioReport)
	ON_BN_CLICKED(IDC_RADIO_LIST, OnRadioList)
	ON_BN_CLICKED(IDC_RADIO_SMALL, OnRadioSmall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListExDlg message handlers

BOOL CListExDlg::OnInitDialog()
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
	m_imageLarge.Create(IDB_BALLS,32,1,RGB(255,255,255));
	m_imageSmall.Create(IDB_SM_BALLS,16,1,RGB(255,255,255));
	m_listctrl.SetImageList(&m_imageLarge,LVSIL_NORMAL);
	m_listctrl.SetImageList(&m_imageSmall,LVSIL_SMALL);

	LV_COLUMN listColumn;
	LV_ITEM listItem;
	char* arColumns[3]={"Oras","Fotbal","Baseball"};
	listColumn.mask=LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	listColumn.fmt=LVCFMT_LEFT;
	listColumn.cx=60;
	for(int nColumn=0;nColumn<3;nColumn++)
	{
		listColumn.iSubItem=nColumn;
		listColumn.pszText=arColumns[nColumn];
		m_listctrl.InsertColumn(nColumn,&listColumn);
	}
	listItem.mask=LVIF_TEXT|LVIF_IMAGE;
	listItem.iSubItem=0;
	char* arOras[3]={"Oakland","San Diego","Seattle"};
	char* arFotbal[3]={"Raiders","Chargers","Seahawks"};
	char* arBaseball[3]={"Athletics","Padres","Mariners"};
	for(int nItem=0;nItem<3;nItem++)
	{
		listItem.iItem=nItem;
		listItem.pszText=arOras[nItem];
		listItem.iImage=nItem%2;
		m_listctrl.InsertItem(&listItem);
		m_listctrl.SetItemText(nItem,1,arFotbal[nItem]);
		m_listctrl.SetItemText(nItem,2,arBaseball[nItem]);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListExDlg::OnPaint() 
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
HCURSOR CListExDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CListExDlg::OnRadioIcon() 
{
	SetListView(LVS_ICON);	
}

void CListExDlg::OnRadioReport() 
{
	SetListView(LVS_REPORT);	
}

void CListExDlg::OnRadioList() 
{
	SetListView(LVS_LIST);
}

void CListExDlg::OnRadioSmall() 
{
	SetListView(LVS_SMALLICON);
}

void CListExDlg::SetListView(DWORD dbView)
{
	DWORD dwOldStyle;
	HWND hWndList;
	hWndList=m_listctrl.GetSafeHwnd();
	dwOldStyle=GetWindowLong(hWndList,GWL_STYLE);
	if((dwOldStyle&LVS_TYPEMASK)!=dbView)
	{
		dwOldStyle&=~LVS_TYPEMASK;
		dbView|=dwOldStyle;
		SetWindowLong(hWndList,GWL_STYLE,dbView);
	}
}
