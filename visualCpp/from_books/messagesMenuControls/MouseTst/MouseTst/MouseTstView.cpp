
// MouseTstView.cpp : implementation of the CMouseTstView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MouseTst.h"
#endif

#include "MouseTstDoc.h"
#include "MouseTstView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseTstView

IMPLEMENT_DYNCREATE(CMouseTstView, CView)

BEGIN_MESSAGE_MAP(CMouseTstView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_NEWMENU_TEST, &CMouseTstView::OnNewmenuTest)
END_MESSAGE_MAP()

// CMouseTstView construction/destruction

CMouseTstView::CMouseTstView() noexcept
{
	m_ptMouse = CPoint(0, 0);
	m_szDescriere.Empty();
}

CMouseTstView::~CMouseTstView()
{
}

BOOL CMouseTstView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMouseTstView drawing

void CMouseTstView::OnDraw(CDC* pDC)
{
	CMouseTstDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOut(m_ptMouse.x, m_ptMouse.y, m_szDescriere);
}


// CMouseTstView printing

BOOL CMouseTstView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMouseTstView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMouseTstView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMouseTstView diagnostics

#ifdef _DEBUG
void CMouseTstView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseTstView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseTstDoc* CMouseTstView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseTstDoc)));
	return (CMouseTstDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseTstView message handlers


void CMouseTstView::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
	m_szDescriere = "Click buton stinga";
	InvalidateRect(NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMouseTstView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
	m_szDescriere = "Dublu click buton stinga";
	InvalidateRect(NULL);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMouseTstView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
	m_szDescriere = "Dublu click buton dreapta";
	InvalidateRect(NULL);
	CView::OnRButtonDblClk(nFlags, point);
}


void CMouseTstView::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_ptMouse = point;
	m_szDescriere = "Click buton dreapta";
	InvalidateRect(NULL);
	CView::OnRButtonDown(nFlags, point);
}


void CMouseTstView::OnNewmenuTest()
{
	m_szDescriere = "MenuTest";
	InvalidateRect(NULL);
}
