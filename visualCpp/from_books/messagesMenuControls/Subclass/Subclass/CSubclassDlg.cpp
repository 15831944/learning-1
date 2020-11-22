// CSubclassDlg.cpp : implementation file
//

#include "pch.h"
#include "Subclass.h"
#include "CSubclassDlg.h"
#include "afxdialogex.h"


// CSubclassDlg dialog

IMPLEMENT_DYNAMIC(CSubclassDlg, CDialogEx)

CSubclassDlg::CSubclassDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUBCLASS_DLG, pParent)
{

}

CSubclassDlg::~CSubclassDlg()
{
}

void CSubclassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSubclassDlg, CDialogEx)
END_MESSAGE_MAP()


// CSubclassDlg message handlers


BOOL CSubclassDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_editNumeric.SubclassDlgItem(IDC_EDIT_NUMERIC, this);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
