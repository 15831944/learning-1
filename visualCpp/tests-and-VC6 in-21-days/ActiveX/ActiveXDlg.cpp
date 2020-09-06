// ActiveXDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ActiveX.h"
#include "ActiveXDlg.h"

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
// CActiveXDlg dialog

CActiveXDlg::CActiveXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CActiveXDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CActiveXDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CActiveXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CActiveXDlg)
	DDX_Control(pDX, IDC_MSFGRID, m_ctlFGrid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CActiveXDlg, CDialog)
	//{{AFX_MSG_MAP(CActiveXDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CActiveXDlg message handlers

BOOL CActiveXDlg::OnInitDialog()
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
	LoadData();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CActiveXDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CActiveXDlg::OnPaint() 
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
HCURSOR CActiveXDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CActiveXDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CActiveXDlg::LoadData()
{
	int liCount;
	CString lsAmount;
	srand((unsigned)time(NULL));
	for(liCount=m_ctlFGrid.GetFixedRows();liCount<m_ctlFGrid.GetRows();liCount++)
	{
		m_ctlFGrid.SetTextArray(GenID(liCount,0),RandomStringValue(0));
		m_ctlFGrid.SetTextArray(GenID(liCount,1),RandomStringValue(1));
		m_ctlFGrid.SetTextArray(GenID(liCount,2),RandomStringValue(2));
		lsAmount.Format("%5d.00",rand());
		m_ctlFGrid.SetTextArray(GenID(liCount,3),lsAmount);
	}
	m_ctlFGrid.SetMergeCol(0,TRUE);
	m_ctlFGrid.SetMergeCol(1,TRUE);
	m_ctlFGrid.SetMergeCol(2,TRUE);
	DoSort();
}

int CActiveXDlg::GenID(int m_iRow, int m_iCol)
{
	int liCols=m_ctlFGrid.GetCols();
	return (m_iCol+liCols*m_iRow);
}


CString CActiveXDlg::RandomStringValue(int m_iColumn)
{
	CString lsStr;
	int liCase;
	switch(m_iColumn)
	{
	case 0:
		liCase=(rand()%5);
		switch(liCase)
		{
		case 0:
			lsStr="Northwest";
			break;
		case 1:
			lsStr="Southwest";
			break;
		case 2:
			lsStr="Midwest";
			break;
		case 3:
			lsStr="Northeast";
			break;
		default:
			lsStr="Southeast";
			break;
		}
		break;
	case 1:
		liCase=(rand()%5);
		switch(liCase)
		{
		case 0:
			lsStr="Dodads";
			break;
		case 1:
			lsStr="Thingamajigs";
			break;
		case 2:
			lsStr="Whatchamacallits";
			break;
		case 3:
			lsStr="Round Tuits";
			break;
		default :
			lsStr="Widgets";
			break;
		}
		break;
	case 2:
		liCase=(rand()%4);
		switch(liCase)
		{
		case 0:
			lsStr="Dore";
			break;
		case 1:
			lsStr="Harvey";
			break;
		case 2:
			lsStr="Pogo";
			break;
		default:
			lsStr="Nyra";
			break;
		}
		break;
	}
	return lsStr;
}

void CActiveXDlg::DoSort()
{
	m_ctlFGrid.SetCol(0);
	m_ctlFGrid.SetColSel((m_ctlFGrid.GetCols()-1));
	m_ctlFGrid.SetSort(1);
}

BEGIN_EVENTSINK_MAP(CActiveXDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CActiveXDlg)
	ON_EVENT(CActiveXDlg, IDC_MSFGRID, -605 /* MouseDown */, OnMouseDownMsfgrid, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CActiveXDlg, IDC_MSFGRID, -607 /* MouseUp */, OnMouseUpMsfgrid, VTS_I2 VTS_I2 VTS_I4 VTS_I4)
	ON_EVENT(CActiveXDlg, IDC_MSFGRID, -601 /* DblClick */, OnDblClickMsfgrid, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CActiveXDlg::OnMouseDownMsfgrid(short Button, short Shift, long x, long y) 
{
	// TODO: Add your control notification handler code here
	if(m_ctlFGrid.GetMouseRow()!=0)
	{
		m_iMouseCol=0;
		return;
	}
	m_iMouseCol=m_ctlFGrid.GetMouseCol();
}

void CActiveXDlg::OnMouseUpMsfgrid(short Button, short Shift, long x, long y) 
{
	// TODO: Add your control notification handler code here
	if(m_iMouseCol==0)
		return;
	m_ctlFGrid.SetRedraw(FALSE);
	m_ctlFGrid.SetColPosition(m_iMouseCol,m_ctlFGrid.GetMouseCol());
	DoSort();
	m_ctlFGrid.SetRedraw(TRUE);
}

void CActiveXDlg::OnDblClickMsfgrid() 
{
	// TODO: Add your control notification handler code here
	m_ctlFGrid.SetRedraw(FALSE);
	m_ctlFGrid.SetTextArray(GenID(m_ctlFGrid.GetMouseRow(),m_ctlFGrid.GetMouseCol()),"remove");
	DoSort();
	m_ctlFGrid.SetRedraw(TRUE);
}
