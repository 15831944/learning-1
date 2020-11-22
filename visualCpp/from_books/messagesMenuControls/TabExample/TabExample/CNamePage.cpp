// CNamePage.cpp : implementation file
//

#include "pch.h"
#include "TabExample.h"
#include "CNamePage.h"


// CNamePage

IMPLEMENT_DYNAMIC(CNamePage, CPropertyPage)

CNamePage::CNamePage() : CPropertyPage(IDD_NAME_PAGE)
, m_szAddress(_T(""))
, m_szCity(_T(""))
, m_szName(_T(""))
{

}

CNamePage::~CNamePage()
{
}


BEGIN_MESSAGE_MAP(CNamePage, CPropertyPage)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CNamePage::OnChangeEditName)
END_MESSAGE_MAP()



// CNamePage message handlers




void CNamePage::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class

	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_szAddress);
	DDX_Text(pDX, IDC_EDIT_CITY, m_szCity);
	DDX_Text(pDX, IDC_EDIT_NAME, m_szName);
}


void CNamePage::OnChangeEditName()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CPropertyPage::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	SetModified();
}
