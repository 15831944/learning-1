// CntrItem.cpp : implementation of the CMDI_ReditCntrItem class
//

#include "stdafx.h"
#include "MDI_Redit.h"

#include "MDI_ReditDoc.h"
#include "MDI_ReditView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditCntrItem implementation

IMPLEMENT_SERIAL(CMDI_ReditCntrItem, CRichEditCntrItem, 0)

CMDI_ReditCntrItem::CMDI_ReditCntrItem(REOBJECT* preo, CMDI_ReditDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
	
}

CMDI_ReditCntrItem::~CMDI_ReditCntrItem()
{
	// TODO: add cleanup code here
	
}

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditCntrItem diagnostics

#ifdef _DEBUG
void CMDI_ReditCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CMDI_ReditCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
