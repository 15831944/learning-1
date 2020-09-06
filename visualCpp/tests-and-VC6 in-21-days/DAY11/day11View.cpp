// day11View.cpp : implementation of the CDay11View class
//

#include "stdafx.h"
#include "day11.h"

#include "day11Doc.h"
#include "day11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDay11View

IMPLEMENT_DYNCREATE(CDay11View, CView)

BEGIN_MESSAGE_MAP(CDay11View, CView)
	//{{AFX_MSG_MAP(CDay11View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay11View construction/destruction

CDay11View::CDay11View()
{
	// TODO: add construction code here

}

CDay11View::~CDay11View()
{
}

BOOL CDay11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDay11View drawing

void CDay11View::OnDraw(CDC* pDC)
{
	CDay11Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int liCount=pDoc->GetLineCount();
	if(liCount) //we have line
	{
		int liPos;
		CLine *lptLine;
		for(liPos=0;liPos<liCount;liPos++)
		{
			lptLine=pDoc->GetLine(liPos);
			lptLine->Draw(pDC);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDay11View printing

BOOL CDay11View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDay11View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDay11View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDay11View diagnostics

#ifdef _DEBUG
void CDay11View::AssertValid() const
{
	CView::AssertValid();
}

void CDay11View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDay11Doc* CDay11View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDay11Doc)));
	return (CDay11Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDay11View message handlers

void CDay11View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
	m_ptPrevPos=point;
	CView::OnLButtonDown(nFlags, point);
}

void CDay11View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//verify if we capture the button
	if(GetCapture()==this)
		//is so release it for other application
		ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CDay11View::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//check if left button is down
	if((nFlags & MK_LBUTTON)==MK_LBUTTON)
	{
		if(GetCapture()==this)
		{
			CClientDC dc(this); //get device context
			//add line
			CLine *pLine=GetDocument()->AddLine(m_ptPrevPos,point);
			//draw the current line
			pLine->Draw(&dc);
			//save current point
			m_ptPrevPos=point;
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CDay11View::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;
	// Load the context menu
	menu.LoadMenu(IDR_CONTEXTMENU);
	// Get the first sub menu (the real menu)
	CMenu *pContextMenu = menu.GetSubMenu(0);

	// Display the context menu for the user
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RIGHTBUTTON,
		point.x, point.y, AfxGetMainWnd());
}
