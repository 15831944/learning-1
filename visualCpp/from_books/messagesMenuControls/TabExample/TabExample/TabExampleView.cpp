
// TabExampleView.cpp : implementation of the CTabExampleView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TabExample.h"
#endif

#include "TabExampleDoc.h"
#include "TabExampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabExampleView

IMPLEMENT_DYNCREATE(CTabExampleView, CView)

BEGIN_MESSAGE_MAP(CTabExampleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTabExampleView construction/destruction

CTabExampleView::CTabExampleView() noexcept
{
	// TODO: add construction code here

}

CTabExampleView::~CTabExampleView()
{
}

BOOL CTabExampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTabExampleView drawing

void CTabExampleView::OnDraw(CDC* /*pDC*/)
{
	CTabExampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTabExampleView printing

BOOL CTabExampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTabExampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTabExampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTabExampleView diagnostics

#ifdef _DEBUG
void CTabExampleView::AssertValid() const
{
	CView::AssertValid();
}

void CTabExampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabExampleDoc* CTabExampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabExampleDoc)));
	return (CTabExampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CTabExampleView message handlers
