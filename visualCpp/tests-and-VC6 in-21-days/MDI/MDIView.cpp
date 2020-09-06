// MDIView.cpp : implementation of the CMDIView class
//

#include "stdafx.h"
#include "MDI.h"

#include "MDIDoc.h"
#include "MDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDIView

IMPLEMENT_DYNCREATE(CMDIView, CView)

BEGIN_MESSAGE_MAP(CMDIView, CView)
	//{{AFX_MSG_MAP(CMDIView)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDIView construction/destruction

CMDIView::CMDIView()
{
	// TODO: add construction code here

}

CMDIView::~CMDIView()
{
}

BOOL CMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMDIView drawing

void CMDIView::OnDraw(CDC* pDC)
{
	CMDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CClientDC dc(this);
	dc.Ellipse(10,10,100,100);
}

/////////////////////////////////////////////////////////////////////////////
// CMDIView printing

BOOL CMDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMDIView diagnostics

#ifdef _DEBUG
void CMDIView::AssertValid() const
{
	CView::AssertValid();
}

void CMDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDIDoc* CMDIView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDIDoc)));
	return (CMDIDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDIView message handlers

