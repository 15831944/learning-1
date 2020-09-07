// day10Doc.cpp : implementation of the CDay10Doc class
//

#include "stdafx.h"
#include "day10.h"

#include "day10Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDay10Doc

IMPLEMENT_DYNCREATE(CDay10Doc, CDocument)

BEGIN_MESSAGE_MAP(CDay10Doc, CDocument)
	//{{AFX_MSG_MAP(CDay10Doc)
	ON_COMMAND(ID_COLOR_BLACK, OnColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, OnUpdateColorBlack)
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_CYAN, OnColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN, OnUpdateColorCyan)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_MAGENTA, OnColorMagenta)
	ON_UPDATE_COMMAND_UI(ID_COLOR_MAGENTA, OnUpdateColorMagenta)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_COMMAND(ID_COLOR_WHITE, OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, OnUpdateColorWhite)
	ON_COMMAND(ID_COLOR_YELLOW, OnColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW, OnUpdateColorYellow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

const COLORREF CDay10Doc::m_crColors[8]={
	RGB(0,0,0),//Black
	RGB(0,0,255),//Blue
	RGB(0,255,0),//Green
	RGB(0,255,255),//Cyan
	RGB(255,0,0),//Red
	RGB(255,0,255),//Magenta
	RGB(255,255,0),//Yellow
	RGB(255,255,255)//White
};

/////////////////////////////////////////////////////////////////////////////
// CDay10Doc construction/destruction

CDay10Doc::CDay10Doc()
{
	// TODO: add one-time construction code here

}

CDay10Doc::~CDay10Doc()
{
}

BOOL CDay10Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_nColor=ID_COLOR_BLACK-ID_COLOR_BLACK;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDay10Doc serialization

void CDay10Doc::Serialize(CArchive& ar)
{
	m_oaLines.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CDay10Doc diagnostics

#ifdef _DEBUG
void CDay10Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDay10Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDay10Doc commands

CLine* CDay10Doc::AddLine(CPoint ptFrom, CPoint ptTo)
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

int CDay10Doc::GetLineCount()
{
	return m_oaLines.GetSize();
}

CLine* CDay10Doc::GetLine(int nIndex)
{
	return (CLine *)m_oaLines[nIndex];
}

void CDay10Doc::DeleteContents() 
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

UINT CDay10Doc::GetColor()
{
	return ID_COLOR_BLACK+m_nColor;
}

void CDay10Doc::OnColorBlack() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_BLACK-ID_COLOR_BLACK;
}

void CDay10Doc::OnUpdateColorBlack(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_BLACK ? 1:0);
}

void CDay10Doc::OnColorBlue() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_BLUE-ID_COLOR_BLACK;
}

void CDay10Doc::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_BLUE ? 1:0);
}

void CDay10Doc::OnColorCyan() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_CYAN-ID_COLOR_BLACK;
}

void CDay10Doc::OnUpdateColorCyan(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_CYAN ? 1:0);
}

void CDay10Doc::OnColorGreen() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_GREEN-ID_COLOR_BLACK;
}

void CDay10Doc::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_GREEN ? 1:0);
}

void CDay10Doc::OnColorMagenta() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_MAGENTA-ID_COLOR_BLACK;
}

void CDay10Doc::OnUpdateColorMagenta(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_MAGENTA ? 1:0);
}

void CDay10Doc::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_RED ? 1:0);
}

void CDay10Doc::OnColorRed() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_RED-ID_COLOR_BLACK;
}

void CDay10Doc::OnColorWhite() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_WHITE-ID_COLOR_BLACK;
}

void CDay10Doc::OnUpdateColorWhite(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_WHITE ? 1:0);
}

void CDay10Doc::OnColorYellow() 
{
	// TODO: Add your command handler code here
	m_nColor=ID_COLOR_YELLOW-ID_COLOR_BLACK;	
}

void CDay10Doc::OnUpdateColorYellow(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetColor()==ID_COLOR_YELLOW ? 1:0);	
}
