// TaskingDoc.cpp : implementation of the CTaskingDoc class
//

#include "stdafx.h"
#include "Tasking.h"

#include "Spinner.h"
#include "TaskingDoc.h"
#include "TaskingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskingDoc

IMPLEMENT_DYNCREATE(CTaskingDoc, CDocument)

BEGIN_MESSAGE_MAP(CTaskingDoc, CDocument)
	//{{AFX_MSG_MAP(CTaskingDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskingDoc construction/destruction

CTaskingDoc::CTaskingDoc()
{
	// TODO: add one-time construction code here

}

CTaskingDoc::~CTaskingDoc()
{
}

BOOL CTaskingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	InitSpinners();
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTaskingDoc serialization

void CTaskingDoc::Serialize(CArchive& ar)
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
// CTaskingDoc diagnostics

#ifdef _DEBUG
void CTaskingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTaskingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskingDoc commands

void CTaskingDoc::CalcPoint(int nID, CSpinner *pSpin)
{
	RECT lWndRect;
	CPoint pPos;
	int iLength;
	CTaskingView *pWnd;
	pWnd=(CTaskingView*)pSpin->GetViewWnd();
	pWnd->GetClientRect(&lWndRect);
	iLength=lWndRect.right/6;
	switch(nID)
	{
	case 0:
		pPos.x=(lWndRect.right/4)-iLength;
		pPos.y=(lWndRect.bottom/4)-iLength;
		break;
	case 1:
		pPos.x=((lWndRect.right/4)*3)-iLength;
		pPos.y=(lWndRect.bottom/4)-iLength;
		break;
	case 2:
		pPos.x=(lWndRect.right/4)-iLength;
		pPos.y=((lWndRect.bottom/4)*3)-(iLength*1.25);
		break;
	case 3:
		pPos.x=((lWndRect.right/4)*3)-iLength;
		pPos.y=((lWndRect.bottom/4)*3)-(iLength*1.25);
		break;
	}
	pSpin->SetLength(iLength);
	pSpin->SetPoint(pPos);
}

void CTaskingDoc::InitSpinners()
{
	int i;
	POSITION pos=GetFirstViewPosition();
	if(pos!=NULL)
	{
		CView* pView=GetNextView(pos);
		for(i=0;i<4;i++)
		{
			m_cSpin[i].SetViewWnd(pView);
			m_cSpin[i].SetContinue(NULL);
			switch(i)
			{
			case 1:
				m_cSpin[i].SetContinue(&((CTaskingView*)pView)->m_bThread1);
				break;
			case 3:
				m_cSpin[i].SetContinue(&((CTaskingView*)pView)->m_bThread2);
				break;
			}
			CalcPoint(i,&m_cSpin[i]);
		}
	}
}

void CTaskingDoc::DoSpin(int nIndex)
{
	m_cSpin[nIndex].Draw();
}

UINT CTaskingDoc::ThreadFunc(LPVOID pParam)
{
	CSpinner *lpSpin=(CSpinner *)pParam;
	BOOL* pbContinue=lpSpin->GetContinue();
	while(*pbContinue) lpSpin->Draw();
	return 0;
}

void CTaskingDoc::SuspendSpinner(int nIndex, BOOL bSuspend)
{
	if(!bSuspend)
	{
		if(m_pSpinThread[nIndex])
		{
			HANDLE hThread=m_pSpinThread[nIndex]->m_hThread;
			//join
			::WaitForSingleObject(hThread,INFINITE);
		}
	}
	else
	{
		int iSpnr;
		switch(nIndex)
		{
		case 0:
			iSpnr=1;
			break;
		case 1:
			iSpnr=3;
			break;
		}
		m_pSpinThread[nIndex]=AfxBeginThread(ThreadFunc,(LPVOID)&(m_cSpin[iSpnr]));
	}
}
