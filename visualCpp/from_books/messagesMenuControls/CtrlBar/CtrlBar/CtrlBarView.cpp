
// CtrlBarView.cpp : implementation of the CCtrlBarView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CtrlBar.h"
#endif

#include "CtrlBarDoc.h"
#include "CtrlBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCtrlBarView

IMPLEMENT_DYNCREATE(CCtrlBarView, CView)

BEGIN_MESSAGE_MAP(CCtrlBarView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCtrlBarView construction/destruction

CCtrlBarView::CCtrlBarView() noexcept
{
	// TODO: add construction code here

}

CCtrlBarView::~CCtrlBarView()
{
}

BOOL CCtrlBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCtrlBarView drawing

void CCtrlBarView::OnDraw(CDC* /*pDC*/)
{
	CCtrlBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCtrlBarView printing

BOOL CCtrlBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCtrlBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCtrlBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCtrlBarView diagnostics

#ifdef _DEBUG
void CCtrlBarView::AssertValid() const
{
	CView::AssertValid();
}

void CCtrlBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCtrlBarDoc* CCtrlBarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCtrlBarDoc)));
	return (CCtrlBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CCtrlBarView message handlers
