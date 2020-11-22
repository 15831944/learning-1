// CHelloDlg.cpp : implementation file
//

#include "pch.h"
#include "FloatingMenu.h"
#include "CHelloDlg.h"
#include "afxdialogex.h"


// CHelloDlg dialog

IMPLEMENT_DYNAMIC(CHelloDlg, CDialogEx)

CHelloDlg::CHelloDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HELLO, pParent)
{

}

CHelloDlg::~CHelloDlg()
{
}

void CHelloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHelloDlg, CDialogEx)
END_MESSAGE_MAP()


// CHelloDlg message handlers


BOOL CHelloDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	AfxMessageBox(_T("WM_INITDIALOG receptionat (de fapt virtual method)"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
