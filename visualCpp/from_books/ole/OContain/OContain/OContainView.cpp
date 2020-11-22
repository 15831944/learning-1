
// OContainView.cpp : implementation of the COContainView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OContain.h"
#endif

#include "OContainDoc.h"
#include "CntrItem.h"
#include "resource.h"
#include "OContainView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COContainView

IMPLEMENT_DYNCREATE(COContainView, CView)

BEGIN_MESSAGE_MAP(COContainView, CView)
	ON_WM_DESTROY()
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, &COContainView::OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, &COContainView::OnCancelEditCntr)
	ON_COMMAND(ID_FILE_PRINT, &COContainView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_EDIT_COPY, &COContainView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &COContainView::OnEditPaste)
	ON_COMMAND(ID_EDIT_CLEAR, &COContainView::OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, &COContainView::OnUpdateEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, &COContainView::OnUpdateEditCopy)
END_MESSAGE_MAP()

// COContainView construction/destruction

COContainView::COContainView() noexcept
{
	m_pSelection = nullptr;
	// TODO: add construction code here

}

COContainView::~COContainView()
{
}

BOOL COContainView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// COContainView drawing

void COContainView::OnDraw(CDC* pDC)
{
	if (!pDC)
		return;

	COContainDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	POSITION pos = pDoc->GetStartPosition();
	while (pos != NULL)
	{
		m_pSelection = (COContainCntrItem *)pDoc->GetNextItem(pos);
		m_pSelection->Draw(pDC, m_pSelection->m_rect);
		CRectTracker tracker;
		SetupTracker(m_pSelection, &tracker);
		tracker.Draw(pDC);
	}
	// TODO: add draw code for native data here
	// TODO: also draw all OLE items in the document

	// Draw the selection at an arbitrary position.  This code should be
	//  removed once your real drawing code is implemented.  This position
	//  corresponds exactly to the rectangle returned by COContainCntrItem,
	//  to give the effect of in-place editing.

	// TODO: remove this code when final draw code is complete.
	if (m_pSelection != nullptr)
	{
		CSize size;
		CRect rect(10, 10, 210, 210);

		if (m_pSelection->GetExtent(&size, m_pSelection->m_nDrawAspect))
		{
			pDC->HIMETRICtoLP(&size);
			rect.right = size.cx + 10;
			rect.bottom = size.cy + 10;
		}
		m_pSelection->Draw(pDC, rect);
	}
}

void COContainView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


	// TODO: remove this code when final selection model code is written
	m_pSelection = nullptr;    // initialize selection

}


// COContainView printing

BOOL COContainView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COContainView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COContainView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void COContainView::OnDestroy()
{
	// Deactivate the item on destruction; this is important
	// when a splitter view is being used
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CView::OnDestroy();
}



// OLE Client support and commands

BOOL COContainView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only COContainCntrItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void COContainView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new COContainCntrItem object
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	COContainCntrItem* pItem = nullptr;
	TRY
	{
		// Create new item connected to this document
		COContainDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new COContainCntrItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);

        if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);
		// As an arbitrary user interface design, this sets the selection
		//  to the last item inserted

		// TODO: reimplement selection as appropriate for your application
		m_pSelection = pItem;   // set selection to last inserted item
		pDoc->UpdateAllViews(nullptr);
	}
	CATCH(CException, e)
	{
		if (pItem != nullptr)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation
void COContainView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place
void COContainView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != nullptr)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void COContainView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != nullptr)
		pActiveItem->SetItemRects();
}

void COContainView::OnFilePrint()
{
	//By default, we ask the Active document to print itself
	//using IOleCommandTarget. If you don't want this behavior
	//remove the call to COleDocObjectItem::DoDefaultPrinting.
	//If the call fails for some reason, we will try printing
	//the docobject using the IPrint interface.
	CPrintInfo printInfo;
	ASSERT(printInfo.m_pPD != nullptr);
	if (S_OK == COleDocObjectItem::DoDefaultPrinting(this, &printInfo))
		return;

	CView::OnFilePrint();

}



// COContainView diagnostics

#ifdef _DEBUG
void COContainView::AssertValid() const
{
	CView::AssertValid();
}

void COContainView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COContainDoc* COContainView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COContainDoc)));
	return (COContainDoc*)m_pDocument;
}
#endif //_DEBUG


// COContainView message handlers


void COContainView::OnLButtonDown(UINT nFlags, CPoint point)
{
	COContainCntrItem *pItemHit = HitTestItems(point);
	SetSelection(pItemHit);
	if (pItemHit != NULL) {
		CRectTracker tracker;
		SetupTracker(pItemHit, &tracker);
		UpdateWindow();
		if (tracker.Track(this, point)) {
			pItemHit->InvalidateItem();
			pItemHit->m_rect = tracker.m_rect;
			pItemHit->InvalidateItem();
			GetDocument()->SetModifiedFlag();
		}

	}

	CView::OnLButtonDown(nFlags, point);
}


BOOL COContainView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default

	return CView::OnSetCursor(pWnd, nHitTest, message);
}


COContainCntrItem * COContainView::HitTestItems(CPoint point)
{
	COContainDoc* pDoc = GetDocument();
	COContainCntrItem * pItemHit = NULL;
	POSITION pos = pDoc->GetStartPosition();
	while (pos != NULL) {
		COContainCntrItem *pItem = (COContainCntrItem *)pDoc->GetNextItem(pos);
		if (pItem->m_rect.PtInRect(point))
			pItemHit = pItem;
	}
	return pItemHit;
}

void COContainView::SetSelection(COContainCntrItem * pItem)
{
	//close in-place active item
	if (pItem == NULL || m_pSelection != pItem) {
		COleClientItem *pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
		if (pActiveItem != NULL && pActiveItem != pItem)
			pActiveItem->Close();
	}
	//update view to new selection
	if (m_pSelection != pItem) {
		if (m_pSelection != NULL)
			OnUpdate(NULL, HINT_UPDATE_ITEM, m_pSelection);
		m_pSelection = pItem;
		if (m_pSelection != NULL)
			OnUpdate(NULL, HINT_UPDATE_ITEM, m_pSelection);
	}
}


void COContainView::SetupTracker(COContainCntrItem* pItem, CRectTracker* pTracker)
{
	pTracker->m_rect = pItem->m_rect;
	if (pItem == m_pSelection)
		pTracker->m_nStyle |= CRectTracker::resizeInside;
	if (pItem->GetType() == OT_LINK)
		pTracker->m_nStyle |= CRectTracker::dottedLine;
	else
		pTracker->m_nStyle |= CRectTracker::solidLine;
	if (pItem->GetItemState() == COleClientItem::openState || pItem->GetItemState() == COleClientItem::activeState)
		pTracker->m_nStyle |= CRectTracker::hatchInside;
}


void COContainView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	OnLButtonDown(nFlags, point);
	if (m_pSelection != NULL) {
		m_pSelection->DoVerb(GetKeyState(VK_CONTROL) < 0 ? OLEIVERB_OPEN : OLEIVERB_PRIMARY, this);
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void COContainView::OnEditCopy()
{
	//implement the copy command on the edit menu
	if (m_pSelection != NULL)
		m_pSelection->CopyToClipboard();
}


void COContainView::OnEditPaste()
{
	COContainCntrItem *pItem = NULL;
	TRY {
		//create new item connected to this document
		COContainDoc *pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new COContainCntrItem(pDoc);
		ASSERT_VALID(pItem);
		//Initialize the item from clipboard data
		if (!pItem->CreateFromClipboard())
			AfxThrowMemoryException();
		ASSERT_VALID(pItem);
		//Update the size before displaying
		pItem->UpdateFromServerExtent();
		//set selection to newly pasted item
		SetSelection(pItem);
		pItem->InvalidateItem();
	}
	CATCH(CException, e)
	{
		if (pItem != NULL) {
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH
}


void COContainView::OnEditClear()
{
	if (m_pSelection != NULL) {
		m_pSelection->Delete();
		m_pSelection = NULL;
		GetDocument()->UpdateAllViews(NULL);
	}
}



void COContainView::OnUpdateEditClear(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(m_pSelection != NULL);
}


void COContainView::OnUpdateEditCopy(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(m_pSelection != NULL);
}
