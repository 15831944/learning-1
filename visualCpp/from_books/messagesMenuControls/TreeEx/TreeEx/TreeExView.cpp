
// TreeExView.cpp : implementation of the CTreeExView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TreeEx.h"
#endif

#include "TreeExDoc.h"
#include "TreeExView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeExView

IMPLEMENT_DYNCREATE(CTreeExView, CTreeView)

BEGIN_MESSAGE_MAP(CTreeExView, CTreeView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTreeExView construction/destruction

CTreeExView::CTreeExView() noexcept
{
	// TODO: add construction code here

}

CTreeExView::~CTreeExView()
{
}

BOOL CTreeExView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= (TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);
	return CTreeView::PreCreateWindow(cs);
}


void CTreeExView::OnDraw(CDC* /*pDC*/)
{
	CTreeExDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


void CTreeExView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& tree = GetTreeCtrl();
	HTREEITEM hCapitol = tree.InsertItem(_T("Capitolul 1"));
	tree.InsertItem(_T("Ce"), hCapitol);
	tree.InsertItem(_T("De ce"), hCapitol);
	tree.InsertItem(_T("Cum"), hCapitol);
	hCapitol = tree.InsertItem(_T("Capitolul 2"));
	tree.InsertItem(_T("Ce"), hCapitol);
	tree.InsertItem(_T("De ce"), hCapitol);
	tree.InsertItem(_T("Cum"), hCapitol);
}


// CTreeExView printing

BOOL CTreeExView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTreeExView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTreeExView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTreeExView diagnostics

#ifdef _DEBUG
void CTreeExView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CTreeExView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeExDoc* CTreeExView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeExDoc)));
	return (CTreeExDoc*)m_pDocument;
}
#endif //_DEBUG


// CTreeExView message handlers
