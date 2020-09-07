// MDI_ReditDoc.cpp : implementation of the CMDI_ReditDoc class
//

#include "stdafx.h"
#include "MDI_Redit.h"

#include "MDI_ReditDoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditDoc

IMPLEMENT_DYNCREATE(CMDI_ReditDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CMDI_ReditDoc, CRichEditDoc)
	//{{AFX_MSG_MAP(CMDI_ReditDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, CRichEditDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditDoc construction/destruction

CMDI_ReditDoc::CMDI_ReditDoc()
{
	// TODO: add one-time construction code here

}

CMDI_ReditDoc::~CMDI_ReditDoc()
{
}

BOOL CMDI_ReditDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

CRichEditCntrItem* CMDI_ReditDoc::CreateClientItem(REOBJECT* preo) const
{
	// cast away constness of this
	return new CMDI_ReditCntrItem(preo, (CMDI_ReditDoc*) this);
}



/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditDoc serialization

void CMDI_ReditDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class CRichEditDoc enables serialization
	//  of the container document's COleClientItem objects.
	// TODO: set CRichEditDoc::m_bRTF = FALSE if you are serializing as text
	CRichEditDoc::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditDoc diagnostics

#ifdef _DEBUG
void CMDI_ReditDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CMDI_ReditDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMDI_ReditDoc commands
