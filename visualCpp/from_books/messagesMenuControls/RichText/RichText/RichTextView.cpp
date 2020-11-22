
// RichTextView.cpp : implementation of the CRichTextView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "RichText.h"
#endif

#include "RichTextDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "RichTextView.h"
#include "CFormatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRichTextView

IMPLEMENT_DYNCREATE(CRichTextView, CRichEditView)

BEGIN_MESSAGE_MAP(CRichTextView, CRichEditView)
	ON_WM_DESTROY()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRichEditView::OnFilePrintPreview)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRichTextView construction/destruction

CRichTextView::CRichTextView() noexcept
{
	// TODO: add construction code here

}

CRichTextView::~CRichTextView()
{
}

BOOL CRichTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRichEditView::PreCreateWindow(cs);
}

void CRichTextView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// Set the printing margins (720 twips = 1/2 inch)
	SetMargins(CRect(720, 720, 720, 720));
}


// CRichTextView printing

BOOL CRichTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}


void CRichTextView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CRichEditView::OnDestroy();
}



// CRichTextView diagnostics

#ifdef _DEBUG
void CRichTextView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CRichTextView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CRichTextDoc* CRichTextView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRichTextDoc)));
	return (CRichTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CRichTextView message handlers


void CRichTextView::OnRButtonUp(UINT nFlags, CPoint point)
{
	CRichEditView::OnRButtonUp(nFlags, point);
	CRichEditCtrl& rtfEdit = GetRichEditCtrl();
	WORD wSelType = rtfEdit.GetSelectionType();
	if (wSelType & SEL_TEXT) {
		CFormatDlg dlg;
		CHARFORMAT chFormat;
		DWORD dwSel = rtfEdit.GetSelectionCharFormat(chFormat);
		if (dwSel & CFM_BOLD)
			dlg.m_bBold = chFormat.dwEffects & CFE_BOLD;
		if (dwSel & CFM_ITALIC)
			dlg.m_bItalic = chFormat.dwEffects & CFE_ITALIC;
		if (dwSel & CFM_UNDERLINE)
			dlg.m_bUnderline = chFormat.dwEffects & CFE_UNDERLINE;
		if (dwSel & CFM_COLOR)
			dlg.m_clrText = chFormat.crTextColor;
		if (dlg.DoModal() == IDOK) {
			if (dlg.m_bBold == TRUE)
				chFormat.dwEffects |= CFE_BOLD;
			else
				chFormat.dwEffects &= ~CFE_BOLD;
			if (dlg.m_bItalic == TRUE)
				chFormat.dwEffects |= CFE_ITALIC;
			else
				chFormat.dwEffects &= ~CFE_ITALIC;
			if (dlg.m_bUnderline == TRUE)
				chFormat.dwEffects |= CFE_UNDERLINE;
			else
				chFormat.dwEffects &= ~CFE_UNDERLINE;
			chFormat.crTextColor = dlg.m_clrText;
			rtfEdit.SetSelectionCharFormat(chFormat);
		}
	}
	else {
		AfxMessageBox(_T("Please select a text"));
	}
}
