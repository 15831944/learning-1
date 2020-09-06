// sdi_editDoc.cpp : implementation of the CSdi_editDoc class
//

#include "stdafx.h"
#include "sdi_edit.h"

#include "sdi_editDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSdi_editDoc

IMPLEMENT_DYNCREATE(CSdi_editDoc, CDocument)

BEGIN_MESSAGE_MAP(CSdi_editDoc, CDocument)
	//{{AFX_MSG_MAP(CSdi_editDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSdi_editDoc construction/destruction

CSdi_editDoc::CSdi_editDoc()
{
	// TODO: add one-time construction code here

}

CSdi_editDoc::~CSdi_editDoc()
{
}

BOOL CSdi_editDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSdi_editDoc serialization

void CSdi_editDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CSdi_editDoc diagnostics

#ifdef _DEBUG
void CSdi_editDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSdi_editDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSdi_editDoc commands
