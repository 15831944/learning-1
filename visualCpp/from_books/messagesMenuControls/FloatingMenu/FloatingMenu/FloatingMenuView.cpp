
// FloatingMenuView.cpp : implementation of the CFloatingMenuView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FloatingMenu.h"
#endif

#include "FloatingMenuDoc.h"
#include "FloatingMenuView.h"
#include "CHelloDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFloatingMenuView

IMPLEMENT_DYNCREATE(CFloatingMenuView, CView)

BEGIN_MESSAGE_MAP(CFloatingMenuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID__LEI, &CFloatingMenuView::OnLei)
	ON_COMMAND(ID__TIGRI, &CFloatingMenuView::OnTigri)
	ON_COMMAND(ID_HELLO, &CFloatingMenuView::OnHello)
END_MESSAGE_MAP()

// CFloatingMenuView construction/destruction

CFloatingMenuView::CFloatingMenuView() noexcept
{
	// TODO: add construction code here

}

CFloatingMenuView::~CFloatingMenuView()
{
}

BOOL CFloatingMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFloatingMenuView drawing

void CFloatingMenuView::OnDraw(CDC* pDC)
{
	CFloatingMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOut(m_ptMsg.x, m_ptMsg.y, m_szMsg);
}


// CFloatingMenuView printing

BOOL CFloatingMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFloatingMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFloatingMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFloatingMenuView diagnostics

#ifdef _DEBUG
void CFloatingMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CFloatingMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFloatingMenuDoc* CFloatingMenuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFloatingMenuDoc)));
	return (CFloatingMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CFloatingMenuView message handlers


void CFloatingMenuView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CMenu zooMenu;
	//stocheaza punctul de aparitie si il converteste in coordante de ecran pentru frunctiile de meniu
	m_ptMsg = point;
	ClientToScreen(&point);
	zooMenu.LoadMenuW(ID_POPUP);
	CMenu *pPopup = zooMenu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	CView::OnRButtonDown(nFlags, point);
}


void CFloatingMenuView::OnLei()
{
	m_szMsg = "Au scapat leii";
	InvalidateRect(NULL);
}


void CFloatingMenuView::OnTigri()
{
	m_szMsg = "Tigrii au iesit din cusca";
	InvalidateRect(NULL);
}


void CFloatingMenuView::OnHello()
{
	CHelloDlg dlgHello;
	if (dlgHello.DoModal() == IDOK)
		AfxMessageBox(_T("s-a apasat butonul OK"));
	else
		AfxMessageBox(_T("s-a apasat butonul Cancel"));
}
