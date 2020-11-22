
// EditTestView.cpp : implementation of the CEditTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EditTest.h"
#endif

#include "EditTestDoc.h"
#include "EditTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditTestView

IMPLEMENT_DYNCREATE(CEditTestView, CView)

BEGIN_MESSAGE_MAP(CEditTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CEditTestView construction/destruction

CEditTestView::CEditTestView() noexcept
{
	// TODO: add construction code here

}

CEditTestView::~CEditTestView()
{
}

BOOL CEditTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CEditTestView drawing

void CEditTestView::OnDraw(CDC* /*pDC*/)
{
	CEditTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CEditTestView printing

BOOL CEditTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEditTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CEditTestView diagnostics

#ifdef _DEBUG
void CEditTestView::AssertValid() const
{
	CView::AssertValid();
}

void CEditTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditTestDoc* CEditTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditTestDoc)));
	return (CEditTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditTestView message handlers
