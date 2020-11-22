
// DVTestView.cpp : implementation of the CDVTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DVTest.h"
#endif

#include "DVTestDoc.h"
#include "DVTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDVTestView

IMPLEMENT_DYNCREATE(CDVTestView, CView)

BEGIN_MESSAGE_MAP(CDVTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDVTestView construction/destruction

CDVTestView::CDVTestView() noexcept
{
	// TODO: add construction code here

}

CDVTestView::~CDVTestView()
{
}

BOOL CDVTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDVTestView drawing

void CDVTestView::OnDraw(CDC* pDC)
{
	CDVTestDoc* pDoc = (CDVTestDoc *)GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//calculeaza spatiul necesar pentru o singura linie de text, inclusiv zona dintre linii
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int nLineHeight = tm.tmHeight + tm.tmExternalLeading;
	CPoint ptText(0, 0);
	for (int nIndex = 0; nIndex < pDoc->GetCount(); nIndex++) {
		CString szName = pDoc->GetName(nIndex);
		pDC->TextOutW(ptText.x, ptText.y, szName);
		ptText.y += nLineHeight;
	}
}


// CDVTestView printing

BOOL CDVTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDVTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDVTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDVTestView diagnostics

#ifdef _DEBUG
void CDVTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDVTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDVTestDoc* CDVTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDVTestDoc)));
	return (CDVTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDVTestView message handlers
