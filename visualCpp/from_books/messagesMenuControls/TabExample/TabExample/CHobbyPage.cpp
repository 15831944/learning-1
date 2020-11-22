// CHobbyPage.cpp : implementation file
//

#include "pch.h"
#include "TabExample.h"
#include "CHobbyPage.h"


// CHobbyPage

IMPLEMENT_DYNAMIC(CHobbyPage, CPropertyPage)

CHobbyPage::CHobbyPage():CPropertyPage(IDD_HOBBY_PAGE)
{

}

CHobbyPage::~CHobbyPage()
{
}


BEGIN_MESSAGE_MAP(CHobbyPage, CPropertyPage)
	ON_COMMAND(IDC_CHECK_POLO, &CHobbyPage::OnCheckPolo)
	ON_COMMAND(IDC_CHECK_SQUASH, &CHobbyPage::OnCheckSquash)
	ON_COMMAND(IDC_CHECK_CURLING, &CHobbyPage::OnCheckCurling)
END_MESSAGE_MAP()



// CHobbyPage message handlers




void CHobbyPage::DoDataExchange(CDataExchange* pDX)
{
	// TODO: Add your specialized code here and/or call the base class

	CPropertyPage::DoDataExchange(pDX);
}


void CHobbyPage::OnCheckPolo()
{
	SetModified();
}


void CHobbyPage::OnCheckSquash()
{
	SetModified();
}


void CHobbyPage::OnCheckCurling()
{
	SetModified();
}


BOOL CHobbyPage::OnApply()
{
	AfxMessageBox(_T("Hobby Page Applied"));

	return CPropertyPage::OnApply();
}
