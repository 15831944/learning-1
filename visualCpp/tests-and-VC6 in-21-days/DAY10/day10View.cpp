// day10View.cpp : implementation of the CDay10View class
//

#include "stdafx.h"
#include "day10.h"

#include "day10Doc.h"
#include "day10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDay10View

IMPLEMENT_DYNCREATE(CDay10View, CView)

BEGIN_MESSAGE_MAP(CDay10View, CView)
	//{{AFX_MSG_MAP(CDay10View)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDay10View construction/destruction

CDay10View::CDay10View()
{
	// TODO: add construction code here

}

CDay10View::~CDay10View()
{
}

BOOL CDay10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDay10View drawing

void CDay10View::OnDraw(CDC* pDC)
{
	CDay10Doc* pDoc = GetDocument();
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
// CDay10View printing

BOOL CDay10View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDay10View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDay10View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDay10View diagnostics

#ifdef _DEBUG
void CDay10View::AssertValid() const
{
	CView::AssertValid();
}

void CDay10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDay10Doc* CDay10View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDay10Doc)));
	return (CDay10Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDay10View message handlers

void CDay10View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();
	m_ptPrevPos=point;
	CView::OnLButtonDown(nFlags, point);
}

void CDay10View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//verify if we capture the button
	if(GetCapture()==this)
		//is so release it for other application
		ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CDay10View::OnMouseMove(UINT nFlags, CPoint point) 
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
