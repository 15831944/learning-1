
// SubclassView.cpp : implementation of the CSubclassView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Subclass.h"
#endif

#include "SubclassDoc.h"
#include "SubclassView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSubclassView

IMPLEMENT_DYNCREATE(CSubclassView, CView)

BEGIN_MESSAGE_MAP(CSubclassView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSubclassView construction/destruction

CSubclassView::CSubclassView() noexcept
{
	// TODO: add construction code here

}

CSubclassView::~CSubclassView()
{
}

BOOL CSubclassView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSubclassView drawing

void CSubclassView::OnDraw(CDC* /*pDC*/)
{
	CSubclassDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSubclassView printing

BOOL CSubclassView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSubclassView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSubclassView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSubclassView diagnostics

#ifdef _DEBUG
void CSubclassView::AssertValid() const
{
	CView::AssertValid();
}

void CSubclassView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSubclassDoc* CSubclassView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSubclassDoc)));
	return (CSubclassDoc*)m_pDocument;
}
#endif //_DEBUG


// CSubclassView message handlers
