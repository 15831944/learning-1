// FormTest.cpp : implementation file
//

#include "stdafx.h"
#include "MDI.h"
#include "FormTest.h"
#include "MDIDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormTest

IMPLEMENT_DYNCREATE(CFormTest, CFormView)

CFormTest::CFormTest()
	: CFormView(CFormTest::IDD)
{
	//{{AFX_DATA_INIT(CFormTest)
	m_rez = _T("");
	//}}AFX_DATA_INIT
}

CFormTest::~CFormTest()
{
}

void CFormTest::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormTest)
	DDX_Text(pDX, IDC_rez, m_rez);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormTest, CFormView)
	//{{AFX_MSG_MAP(CFormTest)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormTest diagnostics

#ifdef _DEBUG
void CFormTest::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormTest::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormTest message handlers

void CFormTest::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	InvalidateRect(NULL);
}

void CFormTest::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	InvalidateRect(NULL);
	
}

void CFormTest::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CMDIDoc *pDoc;
	pDoc=(CMDIDoc *)GetDocument();
	ASSERT_VALID(pDoc);
}
