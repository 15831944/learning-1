
// CntrItem.h : interface of the CRichTextCntrItem class
//

#pragma once

class CRichTextDoc;
class CRichTextView;

class CRichTextCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CRichTextCntrItem)

// Constructors
public:
	CRichTextCntrItem(REOBJECT* preo = nullptr, CRichTextDoc* pContainer = nullptr);
		// Note: pContainer is allowed to be null to enable IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-null document pointer

// Attributes
public:
	CRichTextDoc* GetDocument()
		{ return reinterpret_cast<CRichTextDoc*>(CRichEditCntrItem::GetDocument()); }
	CRichTextView* GetActiveView()
		{ return reinterpret_cast<CRichTextView*>(CRichEditCntrItem::GetActiveView()); }

// Implementation
public:
	~CRichTextCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

