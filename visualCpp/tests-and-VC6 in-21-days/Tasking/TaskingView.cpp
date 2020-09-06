// TaskingView.cpp : implementation of the CTaskingView class
//

#include "stdafx.h"
#include "Tasking.h"

#include "TaskingDoc.h"
#include "TaskingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskingView

IMPLEMENT_DYNCREATE(CTaskingView, CFormView)

BEGIN_MESSAGE_MAP(CTaskingView, CFormView)
	//{{AFX_MSG_MAP(CTaskingView)
	ON_BN_CLICKED(IDC_CBONIDLE1, OnCbonidle)
	ON_BN_CLICKED(IDC_CBTHREAD1, OnCbthread1)
	ON_BN_CLICKED(IDC_CBTHREAD2, OnCbthread2)
	ON_BN_CLICKED(IDC_CBONIDLE2, OnCbonidle)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskingView construction/destruction

CTaskingView::CTaskingView()
	: CFormView(CTaskingView::IDD)
{
	//{{AFX_DATA_INIT(CTaskingView)
	m_bOnIdle1 = FALSE;
	m_bOnIdle2 = FALSE;
	m_bThread1 = FALSE;
	m_bThread2 = FALSE;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CTaskingView::~CTaskingView()
{
}

void CTaskingView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTaskingView)
	DDX_Check(pDX, IDC_CBONIDLE1, m_bOnIdle1);
	DDX_Check(pDX, IDC_CBONIDLE2, m_bOnIdle2);
	DDX_Check(pDX, IDC_CBTHREAD1, m_bThread1);
	DDX_Check(pDX, IDC_CBTHREAD2, m_bThread2);
	//}}AFX_DATA_MAP
}

BOOL CTaskingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTaskingView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CTaskingView printing

BOOL CTaskingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTaskingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTaskingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTaskingView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CTaskingView diagnostics

#ifdef _DEBUG
void CTaskingView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTaskingView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTaskingDoc* CTaskingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTaskingDoc)));
	return (CTaskingDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskingView message handlers

void CTaskingView::OnCbonidle() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

}

void CTaskingView::OnCbthread1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CTaskingDoc* pDocWnd=(CTaskingDoc*)GetDocument();
	ASSERT_VALID(pDocWnd);
	pDocWnd->SuspendSpinner(0,m_bThread1);
}

void CTaskingView::OnCbthread2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CTaskingDoc* pDocWnd=(CTaskingDoc*)GetDocument();
	ASSERT_VALID(pDocWnd);
	pDocWnd->SuspendSpinner(1,m_bThread2);
}

void CTaskingView::OnDestroy() 
{
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	if(m_bThread1)
	{
		m_bThread1=FALSE;
		CTaskingDoc* pDocWnd=(CTaskingDoc *)GetDocument();
		ASSERT_VALID(pDocWnd);
		pDocWnd->SuspendSpinner(0,m_bThread1);
	}
	if(m_bThread2)
	{
		m_bThread2=FALSE;
		CTaskingDoc* pDocWnd=(CTaskingDoc *)GetDocument();
		ASSERT_VALID(pDocWnd);
		pDocWnd->SuspendSpinner(1,m_bThread2);
	}
}
