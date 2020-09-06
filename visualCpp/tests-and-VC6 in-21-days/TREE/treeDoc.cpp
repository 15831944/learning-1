// treeDoc.cpp : implementation of the CTreeDoc class
//

#include "stdafx.h"
#include "tree.h"

#include "treeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc

IMPLEMENT_DYNCREATE(CTreeDoc, CDocument)

BEGIN_MESSAGE_MAP(CTreeDoc, CDocument)
	//{{AFX_MSG_MAP(CTreeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc construction/destruction

CTreeDoc::CTreeDoc()
{
	// TODO: add one-time construction code here

}

CTreeDoc::~CTreeDoc()
{
}

BOOL CTreeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTreeDoc serialization

void CTreeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc diagnostics

#ifdef _DEBUG
void CTreeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTreeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTreeDoc commands
