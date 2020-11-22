
// CntrItem.h : interface of the COContainCntrItem class
//

#pragma once

class COContainDoc;
class COContainView;

class COContainCntrItem : public COleClientItem
{
	DECLARE_SERIAL(COContainCntrItem)

// Constructors
public:
	COContainCntrItem(COContainDoc* pContainer = nullptr);
		// Note: pContainer is allowed to be null to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-null document pointer

// Attributes
public:
	COContainDoc* GetDocument()
		{ return reinterpret_cast<COContainDoc*>(COleClientItem::GetDocument()); }
	COContainView* GetActiveView()
		{ return reinterpret_cast<COContainView*>(COleClientItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	CRect m_rect;
	void InvalidateItem();
	void UpdateFromServerExtent();

protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);	

// Implementation
public:
	~COContainCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

