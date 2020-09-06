// serializeDoc.cpp : implementation of the CSerializeDoc class
//

#include "stdafx.h"
#include "serialize.h"

#include "Person.h"
#include "serializeDoc.h"
#include "SerializeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerializeDoc

IMPLEMENT_DYNCREATE(CSerializeDoc, CDocument)

BEGIN_MESSAGE_MAP(CSerializeDoc, CDocument)
	//{{AFX_MSG_MAP(CSerializeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerializeDoc construction/destruction

CSerializeDoc::CSerializeDoc()
{
	// TODO: add one-time construction code here

}

CSerializeDoc::~CSerializeDoc()
{
}

BOOL CSerializeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	//if unable to add a new record, return FALSE
	if(!AddNewRecord())
		return FALSE;
	//get a pointer to the view
	POSITION pos=GetFirstViewPosition();
	CSerializeView *pView=(CSerializeView*)GetNextView(pos);
	//tell the view that it's got a new data set
	if(pView)
		pView->NewDataSet();
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSerializeDoc serialization

void CSerializeDoc::Serialize(CArchive& ar)
{
		m_oaPeople.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CSerializeDoc diagnostics

#ifdef _DEBUG
void CSerializeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSerializeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerializeDoc commands

CPerson* CSerializeDoc::AddNewRecord()
{
	CPerson *pPerson=new CPerson();
	try
	{
		//add a new record to the object array
		m_oaPeople.Add(pPerson);
		//mar the document as dirty
		SetModifiedFlag();
		//set the enw position mark
		m_iCurPosition=(m_oaPeople.GetSize()-1);
	}
	catch(CMemoryException *perr)
	{
		AfxMessageBox("Out of memory",MB_ICONSTOP|MB_OK);
		if(pPerson)
		{
			delete pPerson;
			pPerson=NULL;
		}
		perr->Delete();
	}
	return pPerson;
}

int CSerializeDoc::GetTotalRecords()
{
	return m_oaPeople.GetSize();
}

int CSerializeDoc::GetCurRecordNbr()
{
	return (m_iCurPosition+1);
}

CPerson* CSerializeDoc::GetCurRecord()
{
	if(m_iCurPosition>=0)
		return (CPerson *)m_oaPeople[m_iCurPosition];
	else
		return NULL;
}

CPerson* CSerializeDoc::GetFirstRecord()
{
	if(m_oaPeople.GetSize()>0)
	{
		m_iCurPosition=0;
		return (CPerson *)m_oaPeople[0];
	}
	else
		return NULL;
}

CPerson* CSerializeDoc::GetNextRecord()
{
	if(++m_iCurPosition<m_oaPeople.GetSize())
		return (CPerson*)m_oaPeople[m_iCurPosition];
	else //add a new record
		return AddNewRecord();
}

CPerson* CSerializeDoc::GetPrevRecord()
{
	if(m_oaPeople.GetSize()>0)
	{
		if(--m_iCurPosition<0)
			m_iCurPosition=0;
		return (CPerson *)m_oaPeople[m_iCurPosition];
	}
	else
		return NULL;
}

CPerson* CSerializeDoc::GetLastRecord()
{
	if(m_oaPeople.GetSize()>0)
	{
		m_iCurPosition=(m_oaPeople.GetSize()-1);
		return (CPerson *)m_oaPeople[m_iCurPosition];
	}
	else
		return NULL;
}

void CSerializeDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	//get the number of lines in the object array
	int liCount=m_oaPeople.GetSize();
	int liPos;
	if(liCount)
	{
		//lop through the array, deleting each object
		for(liPos=0;liPos<liCount;liPos++)
			delete m_oaPeople[liPos];
		m_oaPeople.RemoveAll();
	}
	CDocument::DeleteContents();
}

BOOL CSerializeDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	//get a pointer to the view
	POSITION pos=GetFirstViewPosition();
	CSerializeView* pView=(CSerializeView*)GetNextView(pos);
	//tell the view that it's got a new data set
	if(pView)
		pView->NewDataSet();
	return TRUE;
}
