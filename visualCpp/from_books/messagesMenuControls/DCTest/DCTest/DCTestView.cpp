
// DCTestView.cpp : implementation of the CDCTestView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DCTest.h"
#endif

#include "DCTestDoc.h"
#include "DCTestView.h"
#include "CMapModelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDCTestView

IMPLEMENT_DYNCREATE(CDCTestView, CView)

BEGIN_MESSAGE_MAP(CDCTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_MAP_MODE, &CDCTestView::OnViewMapmode)
	ON_COMMAND(ID_VIEW_FONT, &CDCTestView::OnViewFont)
END_MESSAGE_MAP()

// CDCTestView construction/destruction

CDCTestView::CDCTestView() noexcept
{
	m_nMapMode = MM_TEXT;
	m_map.SetAt(MM_ANISOTROPIC, _T("MM_ANISOTROPIC"));
	m_map.SetAt(MM_HIENGLISH, _T("MM_HIENGLISH"));
	m_map.SetAt(MM_HIMETRIC, _T("MM_HIMETRIC"));
	m_map.SetAt(MM_ISOTROPIC, _T("MM_ISOTROPIC"));
	m_map.SetAt(MM_LOENGLISH, _T("MM_LOENGLISH"));
	m_map.SetAt(MM_LOMETRIC, _T("MM_LOMETRIC"));
	m_map.SetAt(MM_TEXT, _T("MM_TEXT"));
	m_map.SetAt(MM_TWIPS, _T("MM_TWIPS"));
	m_nPenWidth = 1;
	m_cxEllipse = 100;
	m_cyEllipse = 200;
	m_clrOptiune = RGB(0, 0, 0);
	memset(&m_logFont, 0, sizeof(LOGFONT));
	lstrcpy(m_logFont.lfFaceName, _T("Arial"));
}

CDCTestView::~CDCTestView()
{
}

BOOL CDCTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDCTestView drawing

void CDCTestView::OnDraw(CDC* pDC)
{
	CDCTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//grosimea fontului
	/*
	FW_DONTCARE 0
	FW_THIN 100
	FW_EXTRALIGHT 200
	FW_ULTRALIGHT 200
	FW_LIGHT 300
	FW_NORMAL 400
	FW_REGULAR 400
	FW_MEDIUM 500
	FW_SEMIBOLD 600
	FW_DEMIBOLD 600
	FW_BOLD 700
	FW_EXTRABOLD 800
	FW_ULTRABOLD 800
	FW_BLACK 900
	FW_HEAVY 900 */
	pDC->SetMapMode(m_nMapMode);
	CRect rcClient;
	GetClientRect(&rcClient);
	pDC->DPtoLP(rcClient);
	COLORREF clrOld = pDC->SetTextColor(m_clrOptiune);
	int nOldMode = pDC->SetBkMode(TRANSPARENT);
	CFont fntArial, fntBoldSwiss;
	fntArial.CreateFontW(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Arial"));
	fntBoldSwiss.CreateFontW(rcClient.Height() / 20, 0, 0, 0, FW_BOLD, TRUE, FALSE, 0, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, NULL);
	CFont* pOldFont = pDC->SelectObject(&fntArial);

	int x = 0;
	int y = rcClient.bottom / 2;
	CString szOut;
	m_map.Lookup(m_nMapMode, szOut);
	pDC->SelectObject(&fntBoldSwiss);
	pDC->TextOutW(x, y, szOut);
	
	pDC->SelectObject(&fntArial);
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int nCyInterval = tm.tmHeight + tm.tmExternalLeading;

	y += nCyInterval;
	szOut.Format(_T("Inaltimea caracterului - %d unitati"), tm.tmHeight);
	pDC->TextOutW(x, y, szOut);

	y += nCyInterval;
	szOut.Format(_T("Latimea medie - %d unitati"), tm.tmAveCharWidth);
	pDC->TextOutW(x, y, szOut);

	y += nCyInterval;
	szOut.Format(_T("Descent space - %d unitati"), tm.tmDescent);
	pDC->TextOutW(x, y, szOut);

	y += nCyInterval;
	szOut.Format(_T("Ascent space - %d unitati"), tm.tmAscent);
	pDC->TextOutW(x, y, szOut);

	int cxLog = pDC->GetDeviceCaps(LOGPIXELSX);
	y += nCyInterval;
	szOut.Format(_T("%d pixeli pe inch logic orizontal"), cxLog);
	pDC->TextOutW(x, y, szOut);
	
	int cyLog = pDC->GetDeviceCaps(LOGPIXELSY);
	y += nCyInterval;
	szOut.Format(_T("%d pixeli pe inch logic vertical"), cyLog);
	pDC->TextOutW(x, y, szOut);
	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(clrOld);
	pDC->SetBkMode(nOldMode);

	//utilizarea structurii LOGFONT
	y += nCyInterval * 3;
	clrOld = pDC->SetTextColor(m_clrOptiune);
	nOldMode = pDC->SetBkMode(TRANSPARENT);
	CString szMsg1 = _T("Salve this is an Arial font");
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lstrcpy(lf.lfFaceName, _T("Arial"));
	CFont fntArial1;
	fntArial1.CreateFontIndirectW(&lf);
	pOldFont = pDC->SelectObject(&fntArial1);
	pDC->TextOutW(x, y, szMsg1);
	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(clrOld);
	pDC->SetBkMode(nOldMode);

	//printing geometry
	CPoint ptCenter(rcClient.Width() / 2, rcClient.Height() / 2);
	CRect rcEllipse = new CRect(ptCenter.x - (m_cxEllipse / 2), ptCenter.y - (m_cyEllipse / 2), ptCenter.x + (m_cxEllipse / 2), ptCenter.y + (m_cyEllipse / 2));
	CPen penRed(PS_SOLID, m_nPenWidth, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&penRed);
	pDC->Ellipse(rcEllipse);

	//traseaza o caseta neagra in jurul elipsei, folosind unul dintre creioanele stoc
	pDC->SelectStockObject(BLACK_PEN);
	pDC->MoveTo(rcEllipse.TopLeft());
	pDC->LineTo(rcEllipse.right, rcEllipse.top);
	pDC->LineTo(rcEllipse.BottomRight());
	pDC->LineTo(rcEllipse.left, rcEllipse.bottom);
	pDC->LineTo(rcEllipse.left, rcEllipse.top);
	//traseaza un arc folosind zona client ca dreptunghi de marginire
	//taie din arc astfel incit sa apara numai jumatatea din stinga
	CPen penDottedAndGren(PS_DOT, 1, RGB(0, 255, 0));
	pDC->SelectObject(&penDottedAndGren);
	CPoint ptMiddleBottom(ptCenter.x, rcClient.bottom);
	CPoint ptMiddleTop(ptCenter.x, rcClient.top);
	pDC->Arc(rcClient, ptMiddleTop, ptMiddleBottom);
	pDC->SelectObject(&pOldPen);

	//utilizare bush
	CBrush brRosu(RGB(255, 0, 0));
	ptCenter.SetPoint(rcClient.Width() / 4, rcClient.Height() / 4);
	rcClient.DeflateRect(ptCenter.x , ptCenter.y);
	rcClient.OffsetRect(ptCenter.x, ptCenter.y);
	pDC->FillRect(rcClient, &brRosu);
	ptCenter = rcClient.CenterPoint();
	rcEllipse =  CRect(ptCenter.x - (m_cxEllipse / 2), ptCenter.y - (m_cyEllipse / 2), ptCenter.x + (m_cxEllipse / 2), ptCenter.y + (m_cyEllipse / 2));
	CBrush brElipsa(m_clrOptiune);
	CBrush* pOldBush = pDC->SelectObject(&brElipsa);
	pDC->Ellipse(rcEllipse);
	pDC->SelectObject(pOldBush);

	//mesaj rotitor	
	GetClientRect(&rcClient);
	ptCenter.SetPoint(rcClient.Width() / 4, rcClient.Height() / 4);
	clrOld = pDC->SetTextColor(m_clrOptiune);
	nOldMode = pDC->SetBkMode(TRANSPARENT);
	CString szMSg = _T("... Help !! am in rotating!");
	CFont fntRotate;
	for (int nGrade = 0; nGrade < 3600; nGrade += 200) {
		m_logFont.lfEscapement = nGrade;
		fntRotate.CreateFontIndirectW(&m_logFont);
		CFont* pOldFont = pDC->SelectObject(&fntRotate);
		pDC->TextOutW(ptCenter.x*3, ptCenter.y, szMSg);
		pDC->SelectObject(pOldFont);
		fntRotate.DeleteObject();
	}
	pDC->SetTextColor(clrOld);
	pDC->SetBkColor(nOldMode);
}


// CDCTestView printing

BOOL CDCTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDCTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDCTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDCTestView diagnostics

#ifdef _DEBUG
void CDCTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDCTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDCTestDoc* CDCTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDCTestDoc)));
	return (CDCTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDCTestView message handlers


void CDCTestView::OnViewMapmode()
{
	CMapModelDlg dlg;
	dlg.m_nPenWidth = m_nPenWidth;
	dlg.m_cxEllipse = m_cxEllipse;
	dlg.m_cyEllipse = m_cyEllipse;
	dlg.m_clrOptiune = m_clrOptiune;
	if (dlg.DoModal() == IDOK) {
		m_nPenWidth = dlg.m_nPenWidth;
		m_cxEllipse = dlg.m_cxEllipse;
		m_cyEllipse = dlg.m_cyEllipse;
		m_clrOptiune = dlg.m_clrOptiune;
		POSITION pos;
		pos = m_map.GetStartPosition();
		while (pos != NULL) {
			CString szMapMode;
			int nMapMode;
			m_map.GetNextAssoc(pos, nMapMode, szMapMode);
			if (szMapMode == dlg.m_szCombo) {
				m_nMapMode = nMapMode;
				break;
			}
		}
		InvalidateRect(NULL);
	}
}


void CDCTestView::OnViewFont()
{
	CFontDialog dlgFont(&m_logFont);
	dlgFont.DoModal();
	m_clrOptiune = dlgFont.GetColor();
	InvalidateRect(NULL);
}
