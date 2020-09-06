
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_TIGRI, &CMFCApplication1View::OnTigri)
	ON_COMMAND(ID_URSI, &CMFCApplication1View::OnUrsi)
	ON_COMMAND(ID_LEI, &CMFCApplication1View::OnLei)

END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: add construction code here
	m_ptMouse=CPoint(0,0);
	m_sMessage.Empty();
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View drawing

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(m_ptMouse.x,m_ptMouse.y,m_sMessage);
	// TODO: add draw code for native data here
}


// CMFCApplication1View printing

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View message handlers


void CMFCApplication1View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_ptMouse=point;
	m_sMessage="Left button double click";
	InvalidateRect(NULL);
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_ptMouse=point;
	m_sMessage="Left button down";
	InvalidateRect(NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_ptMouse=point;
	CMenu zooMenu;
	ClientToScreen(&point);
	zooMenu.LoadMenuW(IDR_POPUP);
	CMenu* pPopup=zooMenu.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,point.x,point.y,this);
//	InvalidateRect(NULL);
//	CView::OnRButtonDown(nFlags, point);
}



void CMFCApplication1View::OnTigri()
{
	// TODO: Add your command handler code here
	m_sMessage="There are tigres";
	InvalidateRect(NULL);
}


void CMFCApplication1View::OnUrsi()
{
	// TODO: Add your command handler code here
	m_sMessage="There are bears";
	InvalidateRect(NULL);
}


void CMFCApplication1View::OnLei()
{
	// TODO: Add your command handler code here
	m_sMessage="There are lions";
	InvalidateRect(NULL);
}
