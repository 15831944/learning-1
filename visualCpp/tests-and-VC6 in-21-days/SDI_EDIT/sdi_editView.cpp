// sdi_editView.cpp : implementation of the CSdi_editView class
//

#include "stdafx.h"
#include "sdi_edit.h"

#include "sdi_editDoc.h"
#include "sdi_editView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSdi_editView

IMPLEMENT_DYNCREATE(CSdi_editView, CEditView)

BEGIN_MESSAGE_MAP(CSdi_editView, CEditView)
	//{{AFX_MSG_MAP(CSdi_editView)
		ON_COMMAND(ID_SetFont, OnSetFont)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSdi_editView construction/destruction

CSdi_editView::CSdi_editView()
{
	// TODO: add construction code here

}

CSdi_editView::~CSdi_editView()
{
}

BOOL CSdi_editView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CSdi_editView drawing

void CSdi_editView::OnDraw(CDC* pDC)
{
	CSdi_editDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSdi_editView printing

BOOL CSdi_editView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CSdi_editView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CSdi_editView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CSdi_editView diagnostics

#ifdef _DEBUG
void CSdi_editView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSdi_editView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSdi_editDoc* CSdi_editView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdi_editDoc)));
	return (CSdi_editDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSdi_editView message handlers
void CSdi_editView::OnSetFont() 
{
	CFontDialog fonts;
	cfont=new CFont();
	if(fonts.DoModal()==IDOK)
	{
		LOGFONT curfont;
		memset(&curfont,0,sizeof(LOGFONT));
		fonts.GetCurrentFont(&curfont);
		cfont->CreateFontIndirect(&curfont);
		this->SetFont(cfont,TRUE);
	}
}
