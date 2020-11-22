
// OwnDrawDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OwnDraw.h"
#include "OwnDrawDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct CListItem
{
	CListItem(const CString& szItem, BOOL bChecked) {
		m_szItem = szItem;
		m_bChecked = bChecked;
	}
	CString m_szItem;
	BOOL m_bChecked;
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COwnDrawDlg dialog



COwnDrawDlg::COwnDrawDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OWNDRAW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COwnDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_lbOwnDraw);
}

BEGIN_MESSAGE_MAP(COwnDrawDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_COMPAREITEM()
	ON_WM_DELETEITEM()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
END_MESSAGE_MAP()


// COwnDrawDlg message handlers

BOOL COwnDrawDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	CListItem* pMoe = new CListItem(_T("Moe"), TRUE);
	CListItem* pShep = new CListItem(_T("Shep"), TRUE);
	CListItem* pZaphod = new CListItem(_T("Zaphod"), TRUE);
	m_lbOwnDraw.AddString((LPCWSTR)pMoe);
	m_lbOwnDraw.AddString((LPCWSTR)pShep);
	m_lbOwnDraw.AddString((LPCWSTR)pZaphod);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COwnDrawDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COwnDrawDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COwnDrawDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int COwnDrawDlg::OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct)
{
	// TODO: Add your message handler code here and/or call default
	return 1;
//	return CDialogEx::OnCompareItem(nIDCtl, lpCompareItemStruct); it will crash
}


void COwnDrawDlg::OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpdis)
{
	if ((nIDCtl != -1) && (lpdis != 0)) {
		CListItem* pItem = (CListItem*)lpdis->itemData;
		delete pItem;
	}
}


void COwnDrawDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpdis)
{
	CRect rc = lpdis->rcItem;
	CDC* pdcTmp = CDC::FromHandle(lpdis->hDC);
	if (nIDCtl != -1) {
		COLORREF clrBkgrnd;
		COLORREF clrTxt;
		if (lpdis->itemAction & (ODA_DRAWENTIRE | ODA_SELECT)) {
			//daca se cistiga sau se pierde starea de selectare, selectati culoarea potrivita pentru fundal
			if (lpdis->itemState & ODS_SELECTED) {
				clrBkgrnd = GetSysColor(COLOR_HIGHLIGHT);
				clrTxt = GetSysColor(COLOR_HIGHLIGHTTEXT);
			}
			else {
				clrBkgrnd = GetSysColor(COLOR_WINDOW);
				clrTxt = GetSysColor(COLOR_WINDOWTEXT);
			}
			//deseneaza caseta de validare pentru articol si deplaseaza dreptunghiul la dreapta pentru a nu acoperi caseta
			CListItem* pItem = (CListItem*) lpdis->itemData;
			DrawCheckBox(rc, pdcTmp, pItem->m_bChecked);
			rc.left += rc.Height();
			//coloreaza dreptunghiul articolului  in culoarea selectata
			CBrush brHighlight(clrBkgrnd);
			CBrush* pbrOld = pdcTmp->SelectObject(&brHighlight);
			COLORREF clrOldBk = pdcTmp->SetBkColor(clrBkgrnd);
			COLORREF clrOldTxt = pdcTmp->SetTextColor(clrTxt);
			pdcTmp->FillRect(rc, &brHighlight);
			//deseneaza textul in partea de sus a dreptunghiului
			pdcTmp->TextOutW(rc.left, rc.top, pItem->m_szItem);
			pdcTmp->SetBkColor(clrOldBk);
			pdcTmp->SetTextColor(clrOldTxt);
			pdcTmp->SelectObject(pbrOld);
		}
	}

	if ((lpdis->itemAction & ODA_FOCUS)) {
		pdcTmp->DrawFocusRect(rc);
	}
}


void COwnDrawDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void COwnDrawDlg::DrawCheckBox(CRect& rc, CDC* pdc, BOOL bChecked) {
	CDC dcMEm;
	CRect rcBox(rc.TopLeft(), CSize(rc.Height(), rc.Height()));
	rcBox.DeflateRect(2, 2);
	pdc->SelectStockObject(BLACK_PEN);
	pdc->MoveTo(rcBox.TopLeft());
	pdc->LineTo(rcBox.right, rcBox.top);
	pdc->LineTo(rcBox.BottomRight());
	pdc->LineTo(rcBox.left, rcBox.bottom);
	pdc->LineTo(rcBox.TopLeft());
	if (bChecked) {
		pdc->LineTo(rcBox.BottomRight());
		pdc->MoveTo(rcBox.left, rcBox.bottom);
		pdc->LineTo(rcBox.right, rcBox.top);
	}
}