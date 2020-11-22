
// PrintView.cpp : implementation of the CPrintView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Print.h"
#endif

#include "PrintDoc.h"
#include "PrintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintView

IMPLEMENT_DYNCREATE(CPrintView, CView)

BEGIN_MESSAGE_MAP(CPrintView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPrintView construction/destruction

CPrintView::CPrintView() noexcept
{
	m_pFntBanner = NULL;
	m_pFntNormal = NULL;

}

CPrintView::~CPrintView()
{
}

BOOL CPrintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPrintView drawing

void CPrintView::OnDraw(CDC* /*pDC*/)
{
	CPrintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPrintView printing

BOOL CPrintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPrintView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	m_pFntNormal = new CFont;
	m_pFntBanner = new CFont;
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lstrcpy(lf.lfFaceName, _T("Arial"));
	m_pFntNormal->CreateFontIndirectW(&lf);
	lf.lfItalic = TRUE;
	lf.lfWeight = FW_BOLD;
	m_pFntBanner->CreateFontIndirectW(&lf);
}

void CPrintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	delete m_pFntBanner;
	delete m_pFntNormal;
}


// CPrintView diagnostics

#ifdef _DEBUG
void CPrintView::AssertValid() const
{
	CView::AssertValid();
}

void CPrintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPrintDoc* CPrintView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintDoc)));
	return (CPrintDoc*)m_pDocument;
}
#endif //_DEBUG


// CPrintView message handlers


void CPrintView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CString szHeader = _T("Exemplu de program in Visual C++");
	CString szMsg = _T("Exemplu de tiparire");
	CPoint pt(0, 0);
	int nOldMode = pDC->SetMapMode(MM_TWIPS);
	//tipreste antetul
	CFont* pOldFont = pDC->SelectObject(m_pFntBanner);
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int cyText = tm.tmHeight + tm.tmExternalLeading;
	pDC->TextOutW(pt.x,pt.y, szHeader);
	//delasare in jos cu o linie si trasarea unei linii de subliniere folosind un creion negru din stoc.
	CPen* pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
	pt.y -= cyText;
	pDC->MoveTo(pt);
	pDC->LineTo(10000, pt.y);
	pt.y -= cyText;
	//recalculeaza dimensiunile textului folosind noul font si tipareste textul principal pina la sfirsitul paginii
	pDC->SelectObject(m_pFntNormal);
	pDC->GetTextMetrics(&tm);
	cyText = tm.tmHeight + tm.tmExternalLeading;
	int nLung = (int)(pDC->GetDeviceCaps(VERTSIZE) / 25.4) * -1440;
	nLung += 1440;
	for (pt.y -= cyText; pt.y > nLung; pt.y -= cyText) {
		pDC->TextOutW(pt.x, pt.y, szMsg);
	}
	pt.y -= cyText;
	pDC->MoveTo(pt);
	pDC->LineTo(10000, pt.y);
	//restabileste vechile obiecte GDI pentru a preveni pierderile de resource
	pDC->SelectObject(pOldFont);
	pDC->SelectObject(pOldPen);
	pDC->SetMapMode(nOldMode);
}


void CPrintView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	CView::OnPrepareDC(pDC, pInfo);
	if (pInfo) {
		if (pInfo->m_nCurPage < 3)
			pInfo->m_bContinuePrinting = TRUE;
		else
			pInfo->m_bContinuePrinting = FALSE;
	}
}
