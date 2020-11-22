
// CustomersView.cpp : implementation of the CCustomersView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Customers.h"
#endif

#include "CustomersDoc.h"
#include "CustomersView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCustomersView

IMPLEMENT_DYNCREATE(CCustomersView, CView)

BEGIN_MESSAGE_MAP(CCustomersView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCustomersView construction/destruction

CCustomersView::CCustomersView() noexcept
{
	// TODO: add construction code here

}

CCustomersView::~CCustomersView()
{
}

BOOL CCustomersView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCustomersView drawing

void CCustomersView::OnDraw(CDC* pDC)
{
	CCustomersDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//calculeaza spatiul necesar unei singure linii de text, inclusiv spatiul dintre linii
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int nLineHeight = tm.tmHeight + tm.tmExternalLeading;
	CPoint ptText(0, 0);
	for (int nIndex = 0; nIndex < pDoc->GetCount(); nIndex++) {
		CString szOut;
		CUser* pUser = pDoc->GetUser(nIndex);
		szOut.Format(_T("User = %s, email = %s"), pUser->GetName(), pUser->GetAddr());
		pDC->TextOutW(ptText.x, ptText.y, szOut);
		ptText.y += nLineHeight;
	}
}


// CCustomersView printing

BOOL CCustomersView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCustomersView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCustomersView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCustomersView diagnostics

#ifdef _DEBUG
void CCustomersView::AssertValid() const
{
	CView::AssertValid();
}

void CCustomersView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCustomersDoc* CCustomersView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCustomersDoc)));
	return (CCustomersDoc*)m_pDocument;
}
#endif //_DEBUG


// CCustomersView message handlers


void CCustomersView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	InvalidateRect(NULL);
}
