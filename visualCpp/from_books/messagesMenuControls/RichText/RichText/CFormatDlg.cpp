// CFormatDlg.cpp : implementation file
//

#include "pch.h"
#include "RichText.h"
#include "CFormatDlg.h"
#include "afxdialogex.h"


// CFormatDlg dialog

IMPLEMENT_DYNAMIC(CFormatDlg, CDialogEx)

CFormatDlg::CFormatDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FORMAT, pParent)
	, m_bBold(FALSE)
	, m_bItalic(FALSE)
	, m_bUnderline(FALSE)
	, m_clrText(0)
{

}

CFormatDlg::~CFormatDlg()
{
}

void CFormatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_BOLD, m_bBold);
	DDX_Check(pDX, IDC_ITALIC, m_bItalic);
	DDX_Check(pDX, IDC_UNDERLINE, m_bUnderline);
}


BEGIN_MESSAGE_MAP(CFormatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_COLOR, &CFormatDlg::OnColor)
END_MESSAGE_MAP()


// CFormatDlg message handlers


void CFormatDlg::OnColor()
{
	CColorDialog dlg;
	dlg.m_cc.rgbResult = m_clrText;
	if (dlg.DoModal() == IDOK) {
		m_clrText = dlg.GetColor();
	}
}
