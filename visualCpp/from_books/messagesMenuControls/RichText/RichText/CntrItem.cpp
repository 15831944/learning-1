
// CntrItem.cpp : implementation of the CRichTextCntrItem class
//

#include "pch.h"
#include "framework.h"
#include "RichText.h"

#include "RichTextDoc.h"
#include "RichTextView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRichTextCntrItem implementation

IMPLEMENT_SERIAL(CRichTextCntrItem, CRichEditCntrItem, 0)

CRichTextCntrItem::CRichTextCntrItem(REOBJECT* preo, CRichTextDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
}

CRichTextCntrItem::~CRichTextCntrItem()
{
	// TODO: add cleanup code here
}


// CRichTextCntrItem diagnostics

#ifdef _DEBUG
void CRichTextCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CRichTextCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

