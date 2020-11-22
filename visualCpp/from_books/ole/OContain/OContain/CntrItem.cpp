
// CntrItem.cpp : implementation of the COContainCntrItem class
//

#include "pch.h"
#include "framework.h"
#include "OContain.h"

#include "OContainDoc.h"
#include "OContainView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COContainCntrItem implementation

IMPLEMENT_SERIAL(COContainCntrItem, COleClientItem, 0)

COContainCntrItem::COContainCntrItem(COContainDoc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: add one-time construction code here
}

COContainCntrItem::~COContainCntrItem()
{
	// TODO: add cleanup code here
}

void COContainCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	switch (nCode)
	{
	case OLE_CHANGED:
		InvalidateItem();
		UpdateFromServerExtent();
		break;
	case OLE_CHANGED_STATE:
	case OLE_CHANGED_ASPECT:
		InvalidateItem();
		break;
	}
	GetDocument()->UpdateAllViews(nullptr);
		// for now just update ALL views/no hints
}

BOOL COContainCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// During in-place activation COContainCntrItem::OnChangeItemPosition
	//  is called by the server to change the position of the in-place
	//  window.  Usually, this is a result of the data in the server
	//  document changing such that the extent has changed or as a result
	//  of in-place resizing.
	//
	// The default here is to call the base class, which will call
	//  COleClientItem::SetItemRects to move the item
	//  to the new position.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	InvalidateItem();
	m_rect = rectPos;
	InvalidateItem();
	//mark document as dirty
	GetDocument()->SetModifiedFlag();
	return TRUE;
}

BOOL COContainCntrItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CFrameWndEx, pFrameWnd);

	if (pMainFrame != nullptr)
	{
		ASSERT_VALID(pMainFrame);
		return pMainFrame->OnShowPanes(bShow);
	}

	return FALSE;
}

void COContainCntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// During in-place activation, COContainCntrItem::OnGetItemPosition
	//  will be called to determine the location of this item.  Usually, this 
	//  rectangle would reflect the current position of the item relative to the 
	//  view used for activation.  You can obtain the view by calling 
	//  COContainCntrItem::GetActiveView.

	// TODO: return correct rectangle (in pixels) in rPosition

	CSize size;
	rPosition.SetRectEmpty();
	if (GetExtent(&size, m_nDrawAspect))
	{
		COContainView* pView = GetActiveView();
		ASSERT_VALID(pView);
		if (!pView)
			return;
		CDC *pDC = pView->GetDC();
		ASSERT(pDC);
		if (!pDC)
			return;
		pDC->HIMETRICtoLP(&size);
		rPosition.SetRect(10, 10, size.cx + 10, size.cy + 10);
	}
	else
		rPosition.SetRect(10, 10, 210, 210);
}

void COContainCntrItem::OnActivate()
{
	// Allow only one inplace activate item per frame
	COContainView* pView = GetActiveView();
	ASSERT_VALID(pView);
	if (!pView)
		return;
	COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
	if (pItem != nullptr && pItem != this)
		pItem->Close();
	
	COleClientItem::OnActivate();
}

void COContainCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

	DWORD dwMisc = 0;
	m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
	if (dwMisc & OLEMISC_INSIDEOUT)
		DoVerb(OLEIVERB_HIDE, nullptr);
}

void COContainCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleClientItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  COContainCntrItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleClientItem::Serialize(ar);

	// now store/retrieve data specific to COContainCntrItem
	if (ar.IsStoring())
	{
		ar << m_rect;
	}
	else
	{
		ar >> m_rect;
	}
}


// COContainCntrItem diagnostics

#ifdef _DEBUG
void COContainCntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void COContainCntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

void COContainCntrItem::InvalidateItem() {
	GetDocument()->UpdateAllViews(NULL, HINT_UPDATE_ITEM, this);
}

void COContainCntrItem::UpdateFromServerExtent() {
	CSize size;
	if (GetExtent(&size)) {
		//OLE return the extent in HIMETRIC units however , we need pixels
		CClientDC dc(NULL);
		dc.HIMETRICtoDP(&size);
		//invalidate only if it has actually changed
		if (size != m_rect.Size()) {
			//invalidate old, update, invalidate new
			InvalidateItem();
			m_rect.bottom = m_rect.top + size.cy;
			m_rect.right = m_rect.left + size.cx;
			InvalidateItem();
			//mark document as modified
			GetDocument()->SetModifiedFlag();
		}
	}
}
