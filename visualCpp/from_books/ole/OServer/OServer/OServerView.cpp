
// OServerView.cpp : implementation of the COServerView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OServer.h"
#endif

#include "OServerDoc.h"
#include "OServerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COServerView

IMPLEMENT_DYNCREATE(COServerView, CView)

BEGIN_MESSAGE_MAP(COServerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_CANCEL_EDIT_SRVR, &COServerView::OnCancelEditSrvr)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// COServerView construction/destruction

COServerView::COServerView() noexcept
{
	// TODO: add construction code here

}

COServerView::~COServerView()
{
}

BOOL COServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// COServerView drawing

void COServerView::OnDraw(CDC* pDC)
{
	COServerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect r;
	GetClientRect(&r);
	pDC->DrawText(_T("Ole Server!!!"), &r, DT_CENTER | DT_WORDBREAK);
}


// COServerView printing

BOOL COServerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COServerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COServerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

// OLE Server support

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the server (not the container) causes the deactivation
void COServerView::OnCancelEditSrvr()
{
	GetDocument()->OnDeactivateUI(FALSE);
}


// COServerView diagnostics

#ifdef _DEBUG
void COServerView::AssertValid() const
{
	CView::AssertValid();
}

void COServerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COServerDoc* COServerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COServerDoc)));
	return (COServerDoc*)m_pDocument;
}
#endif //_DEBUG


// COServerView message handlers
