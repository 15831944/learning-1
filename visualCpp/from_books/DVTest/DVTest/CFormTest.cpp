// CFormTest.cpp : implementation file
//

#include "pch.h"
#include "DVTest.h"
#include "CFormTest.h"
#include "DVTestDoc.h"


// CFormTest

IMPLEMENT_DYNCREATE(CFormTest, CFormView)

CFormTest::CFormTest()
	: CFormView(IDD_FORM_VIEW)
{

}

CFormTest::~CFormTest()
{
}

void CFormTest::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT, m_edNames);
	DDX_Control(pDX, IDC_LIST, m_lbNames);
}

BEGIN_MESSAGE_MAP(CFormTest, CFormView)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_APPLY, &CFormTest::OnApply)
	ON_BN_CLICKED(IDC_CLOSE, &CFormTest::OnClose)
END_MESSAGE_MAP()


// CFormTest diagnostics

#ifdef _DEBUG
void CFormTest::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormTest::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormTest message handlers


int CFormTest::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}


void CFormTest::OnApply()
{
	CDVTestDoc* pDoc;
	pDoc = (CDVTestDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	CString szNume;
	m_edNames.GetWindowTextW(szNume);
	m_edNames.SetWindowTextW(_T(""));
	m_edNames.SetFocus();
/*	new version after OnUpdate
	if (szNume.GetLength() > 0) {
		int nIndex = pDoc->AddName(szNume);
		m_lbNames.InsertString(nIndex, szNume);
		m_lbNames.SetCurSel(nIndex);
	} */
	if (szNume.GetLength() > 0) {
		pDoc->AddName(szNume);
	}
	m_lbNames.ResetContent();
	for (int nIndex = 0; nIndex < pDoc->GetCount(); nIndex++) {
		CString szNume = pDoc->GetName(nIndex);
		m_lbNames.InsertString(nIndex, szNume);
	}
}


void CFormTest::OnClose()
{
	PostMessage(WM_COMMAND, ID_FILE_CLOSE);
}


void CFormTest::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	/* nu mai e nevoie dupa adaugarea lor in OnUpdate
	CDVTestDoc* pDoc = (CDVTestDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	for (int nIndex = 0; nIndex < pDoc->GetCount(); nIndex++) {
		CString szNume = pDoc->GetName(nIndex);
		m_lbNames.AddString(szNume);
	} */
	ResizeParentToFit(FALSE); //permite extinderea vzualizarii
	ResizeParentToFit(); //restringe vizualizarea
}


void CFormTest::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CDVTestDoc* pDoc = (CDVTestDoc*)GetDocument();
	ASSERT_VALID(pDoc);
	m_lbNames.ResetContent();
	for (int nIndex = 0; nIndex < pDoc->GetCount(); nIndex++) {
		CString szNume = pDoc->GetName(nIndex);
		m_lbNames.InsertString(nIndex, szNume);
	}
}
