// day11Doc.cpp : implementation of the CDay11Doc class
//

#include "stdafx.h"
#include "day11.h"

#include "day11Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDay11Doc

IMPLEMENT_DYNCREATE(CDay11Doc, CDocument)

BEGIN_MESSAGE_MAP(CDay11Doc, CDocument)
	ON_COMMAND_RANGE(ID_COLOR_BLACK,ID_COLOR_WHITE,OnColorCommand)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLOR_BLACK,ID_COLOR_WHITE,OnUpdateColorUI)
	//{{AFX_MSG_MAP(CDay11Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

const COLORREF CDay11Doc::m_crColors[8]={
	RGB(0,0,0),
	RGB(0,0,255),
	RGB(0,255,0),
	RGB(0,255,255),
	RGB(255,0,0),
	RGB(255,0,255),
	RGB(255,255,0),
	RGB(255,255,255)
};
/////////////////////////////////////////////////////////////////////////////
// CDay11Doc construction/destruction

CDay11Doc::CDay11Doc()
{
	// TODO: add one-time construction code here

}

CDay11Doc::~CDay11Doc()
{
}

BOOL CDay11Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_nColor=0;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDay11Doc serialization

void CDay11Doc::Serialize(CArchive& ar)
{
	m_oaLines.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CDay11Doc diagnostics

#ifdef _DEBUG
void CDay11Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDay11Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDay11Doc commands
CLine* CDay11Doc::AddLine(CPoint ptFrom, CPoint ptTo)
{
	CLine *pLine=new CLine(ptFrom,ptTo,m_crColors[m_nColor]);
	try
	{
		m_oaLines.Add(pLine);
		//mark this document as dirty
		SetModifiedFlag();
	}
	//memory exception
	catch(CMemoryException* perr)
	{
		AfxMessageBox("Out of memory ",MB_ICONSTOP|MB_OK);
		if(pLine)
		{
			delete pLine;
			pLine=NULL;
		}
		perr->Delete();
	}
	return pLine;
}

int CDay11Doc::GetLineCount()
{
	return m_oaLines.GetSize();
}

CLine* CDay11Doc::GetLine(int nIndex)
{
	return (CLine *)m_oaLines[nIndex];
}

void CDay11Doc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	int liCount=m_oaLines.GetSize();
	int liPos;
	if(liCount)
	{
		for(liPos=0;liPos<liCount;liPos++)
			delete m_oaLines[liPos];
		m_oaLines.RemoveAll();
	}
	CDocument::DeleteContents();
}

UINT CDay11Doc::GetColor()
{
	return ID_COLOR_BLACK+m_nColor;
}

void CDay11Doc::OnColorCommand(UINT nID)
{
	m_nColor=nID-ID_COLOR_BLACK;
}

void CDay11Doc::OnUpdateColorUI(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(GetColor()==pCmdUI->m_nID ? 1 : 0);
}
