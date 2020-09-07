// MDI_ReditView.cpp : implementation of the CMDI_ReditView class
//

#include "stdafx.h"
#include "MDI_Redit.h"

#include "MDI_ReditDoc.h"
#include "CntrItem.h"
#include "MDI_ReditView.h"
#include <afxdlgs.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditView

IMPLEMENT_DYNCREATE(CMDI_ReditView, CRichEditView)

BEGIN_MESSAGE_MAP(CMDI_ReditView, CRichEditView)
	//{{AFX_MSG_MAP(CMDI_ReditView)
	ON_WM_DESTROY()
	ON_COMMAND(ID_SELECT_FONT, OnSelectFont)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRichEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditView construction/destruction

CMDI_ReditView::CMDI_ReditView()
{
	// TODO: add construction code here

}

CMDI_ReditView::~CMDI_ReditView()
{
}

BOOL CMDI_ReditView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CMDI_ReditView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch).
	SetMargins(CRect(720, 720, 720, 720));
}

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditView printing

BOOL CMDI_ReditView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CMDI_ReditView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used.
   CRichEditView::OnDestroy();
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
}


/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditView diagnostics

#ifdef _DEBUG
void CMDI_ReditView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CMDI_ReditView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CMDI_ReditDoc* CMDI_ReditView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDI_ReditDoc)));
	return (CMDI_ReditDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditView message handlers

void CMDI_ReditView::OnSelectFont() 
{
	// TODO: Add your command handler code here
	CFont cfont;
	CFontDialog fntdial;
	LOGFONT font;
	if(fntdial.DoModal()==IDOK)
	{
		fntdial.GetCurrentFont(&font);
		cfont.CreateFontIndirect(&font);
		this->SetFont(&cfont,TRUE);
	}
}
