
// SrvrItem.h : interface of the COServerSrvrItem class
//

#pragma once

class COServerSrvrItem : public COleServerItem
{
	DECLARE_DYNAMIC(COServerSrvrItem)

// Constructors
public:
	COServerSrvrItem(COServerDoc* pContainerDoc);

// Attributes
	COServerDoc* GetDocument() const
		{ return reinterpret_cast<COServerDoc*>(COleServerItem::GetDocument()); }

// Overrides
	public:
	virtual BOOL OnDraw(CDC* pDC, CSize& rSize);
	virtual BOOL OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize);

// Implementation
public:
	~COServerSrvrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
};

