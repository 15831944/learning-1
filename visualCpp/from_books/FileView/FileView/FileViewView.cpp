
// FileViewView.cpp : implementation of the CFileViewView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileView.h"
#endif

#include "FileViewDoc.h"
#include "FileViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileViewView

IMPLEMENT_DYNCREATE(CFileViewView, CView)

BEGIN_MESSAGE_MAP(CFileViewView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

// CFileViewView construction/destruction

CFileViewView::CFileViewView() noexcept
{
	// TODO: add construction code here
	currentLine = 0;
	margin = 0;
}

CFileViewView::~CFileViewView()
{
	delete ourFont;
}

BOOL CFileViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFileViewView drawing

void CFileViewView::OnDraw(CDC* pDC)
{
	CFileViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont *oldFont;
	CRect clientRect;
	oldFont = pDC->SelectObject(ourFont);
	CPtrArray *l = pDoc->GetLines();
	int y = 0;
	if(pDC->IsPrinting()) {
		clientRect = printerRect;
	}
	else {
		GetClientRect(&clientRect);
	}
	for (int i = currentLine; i < l->GetSize(); i++) {
		CString *line = (CString *)l->GetAt(i);
		if (line->GetLength() - 2 > margin) {
			pDC->TextOut(0, y, line->Mid(margin), line->GetLength() - margin - 2);
			y += lHeight;
		}
		if (y > clientRect.Height())
			break;
	}
	pDC->SelectObject(oldFont);
}


// CFileViewView printing

BOOL CFileViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileViewView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	CFont *oldFont = pDC->SelectObject(ourFont);
	saveLHeight = lHeight;
	saveCWidth = cWidth;
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	lHeight = tm.tmHeight + tm.tmExternalLeading;
	cWidth = tm.tmAveCharWidth;
	saveCurrentLine = currentLine;
	currentLine = 0;
	pDC->SelectObject(oldFont);
}

void CFileViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	lHeight = saveLHeight;
	cWidth = saveCWidth;
	currentLine = saveCurrentLine;
}


// CFileViewView diagnostics

#ifdef _DEBUG
void CFileViewView::AssertValid() const
{
	CView::AssertValid();
}

void CFileViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileViewDoc* CFileViewView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileViewDoc)));
	return (CFileViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileViewView message handlers


void CFileViewView::OnInitialUpdate()
{
	CFileViewDoc *pDoc = GetDocument();
	CPtrArray *l = pDoc->GetLines();
	// create scroll bars
	SetScrollRange(SB_VERT, 0, l->GetSize());
	SetScrollPos(SB_VERT, 0);
	SetScrollRange(SB_HORZ, 0, pDoc->getMaxLineLength());
	SetScrollPos(SB_HORZ, 0);
	//create the font to not create each time into OnDraw
	CDC *pDC = GetDC();
	ourFont = new CFont();
	ourFont->CreateFont(0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_TT_ALWAYS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Courier New"));
	CFont *oldFont = pDC->SelectObject(ourFont);
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	lHeight = tm.tmHeight + tm.tmExternalLeading;
	cWidth = tm.tmAveCharWidth;

	CView::OnInitialUpdate();
}


void CFileViewView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CFileViewDoc *pDoc = GetDocument();
	CPtrArray *l = pDoc->GetLines();
	switch (nSBCode) {
	case SB_LINEUP: // move just one line up from bar
		if (currentLine > 0)
			currentLine--;
		break;
	case SB_LINEDOWN: //move just one line down from bar
		if (currentLine < l->GetSize())
			currentLine++;
		break;
	case SB_BOTTOM: //move the cursor to the bottom
		currentLine = l->GetSize();
		break;
	case SB_TOP: //move the cursor to top
		currentLine = 0;
		break;
	case SB_PAGEUP: //move one one pageup
	{	CRect clientRectangle;
		GetClientRect(&clientRectangle);
		currentLine -= clientRectangle.Height() / lHeight;
		if (currentLine < 0)
			currentLine = 0;
	}
		break;
	case SB_PAGEDOWN: //move one page down
	{
		CRect clientRectangle;
		GetClientRect(&clientRectangle);
		currentLine += clientRectangle.Height() / lHeight;
		if (currentLine > l->GetSize())
			currentLine = l->GetSize();
	}
		break;
	case SB_THUMBPOSITION: //user has hocked the mouse to the bar and moved to a new position
	case SB_THUMBTRACK: // move the cursor
		currentLine = nPos;
		if (currentLine < 0)
			currentLine = 0;
		if (currentLine > l->GetSize())
			currentLine = l->GetSize();
		break;
	}
	SetScrollPos(SB_VERT, currentLine);
	Invalidate(TRUE);
	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CFileViewView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CFileViewDoc *pDoc = GetDocument();
	CPtrArray *l = pDoc->GetLines();
	switch (nSBCode)
	{
	case SB_LINELEFT:
		if (margin > 0)
			margin--;
		break;
	case SB_LINERIGHT:
		if (margin < pDoc->getMaxLineLength())
			margin++;
		break;
	case SB_RIGHT:
		margin = pDoc->getMaxLineLength();
		break;
	case SB_LEFT:
		margin = 0;
		break;
	case SB_PAGELEFT:
	{
		CRect clientRect;
		GetClientRect(&clientRect);
		margin -= clientRect.Width() / cWidth;
		if (margin < 0)
			margin = 0;
	}
	break;
	case SB_PAGERIGHT:
	{
		CRect clientRect;
		GetClientRect(&clientRect);
		margin += clientRect.Width() / cWidth;
		if (margin > pDoc->getMaxLineLength())
			margin = pDoc->getMaxLineLength();
	}
	break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		margin = nPos;
		if (margin < 0)
			margin = 0;
		if (margin > pDoc->getMaxLineLength())
			margin = pDoc->getMaxLineLength();
		break;
	}
	SetScrollPos(SB_HORZ, margin);
	Invalidate(TRUE);
	CView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CFileViewView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	pInfo->m_rectDraw.InflateRect(0, -lHeight);
	printerRect = pInfo->m_rectDraw;
	int linesPerPage = (printerRect.Height() / lHeight) - 1;
	currentLine = linesPerPage * (pInfo->m_nCurPage - 1);
	TRACE2("Printing page %d, starting with line %d\n", pInfo->m_nCurPage, currentLine);
	CView::OnPrint(pDC, pInfo);
	CString footer;
	CFont *oldFont;
	footer.Format(_T("*** File %s ***"), GetDocument()->GetPathName());
	oldFont = pDC->SelectObject(ourFont);
	pDC->TextOut(0, pInfo->m_rectDraw.Height()+ lHeight, footer);
	pDC->SelectObject(oldFont);
}


void CFileViewView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	CView::OnPrepareDC(pDC, pInfo);
	if (pInfo != NULL) {
		if (currentLine < GetDocument()->GetLines()->GetSize()) {
			TRACE1("currentLine = %d continuing printing\n", currentLine);
			pInfo->m_bContinuePrinting = TRUE;
		}
		else {
			TRACE1("currentLine = %%d, terminating printing\n", currentLine);
			pInfo->m_bContinuePrinting = FALSE;
		}
	}
}
