// serializeView.cpp : implementation of the CSerializeView class
//

#include "stdafx.h"
#include "serialize.h"

#include "Person.h"
#include "serializeDoc.h"
#include "serializeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSerializeView

IMPLEMENT_DYNCREATE(CSerializeView, CFormView)

BEGIN_MESSAGE_MAP(CSerializeView, CFormView)
	//{{AFX_MSG_MAP(CSerializeView)
	ON_BN_CLICKED(IDC_BFIRST, OnBfirst)
	ON_BN_CLICKED(IDC_BLAST, OnBlast)
	ON_BN_CLICKED(IDC_BNEXT, OnBnext)
	ON_BN_CLICKED(IDC_BPREV, OnBprev)
	ON_BN_CLICKED(IDC_CBEMPLOYED, OnCbemployed)
	ON_EN_CHANGE(IDC_EAGE, OnChangeEage)
	ON_EN_CHANGE(IDC_ENAME, OnChangeEname)
	ON_BN_CLICKED(IDC_RDIVORCED, OnRMaritalStat)
	ON_BN_CLICKED(IDC_RMARRIED, OnRMaritalStat)
	ON_BN_CLICKED(IDC_RSINGLE, OnRMaritalStat)
	ON_BN_CLICKED(IDC_RWIDOW, OnRMaritalStat)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSerializeView construction/destruction

CSerializeView::CSerializeView()
	: CFormView(CSerializeView::IDD)
{
	//{{AFX_DATA_INIT(CSerializeView)
	m_bEmployed = FALSE;
	m_iAge = 0;
	m_sName = _T("");
	m_sPosition = _T("");
	m_iMaritalStatus = -1;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CSerializeView::~CSerializeView()
{
}

void CSerializeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSerializeView)
	DDX_Check(pDX, IDC_CBEMPLOYED, m_bEmployed);
	DDX_Text(pDX, IDC_EAGE, m_iAge);
	DDX_Text(pDX, IDC_ENAME, m_sName);
	DDX_Text(pDX, IDC_SPOSITION, m_sPosition);
	DDX_Radio(pDX, IDC_RSINGLE, m_iMaritalStatus);
	//}}AFX_DATA_MAP
}

BOOL CSerializeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CSerializeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CSerializeView printing

BOOL CSerializeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSerializeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSerializeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSerializeView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CSerializeView diagnostics

#ifdef _DEBUG
void CSerializeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSerializeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSerializeDoc* CSerializeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSerializeDoc)));
	return (CSerializeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSerializeView message handlers

void CSerializeView::PopulateView()
{
	//get a pointer to the current document
	CSerializeDoc* pDoc=GetDocument();
	if(pDoc)
	{
		//display the current record position in the set
		m_sPosition.Format("Record %d of %d",pDoc->GetCurRecordNbr(),pDoc->GetTotalRecords());
	}
	//do we have a valid record object
	if(m_pCurPerson)
	{
		//yes, get all the record values
		m_bEmployed=m_pCurPerson->GetEmployed();
		m_iAge=m_pCurPerson->GetAge();
		m_sName=m_pCurPerson->GetName();
		m_iMaritalStatus=m_pCurPerson->GetMaritalStatus();
	}
	//update the display
	UpdateData(FALSE);
}	

void CSerializeView::OnBfirst() 
{
	// TODO: Add your control notification handler code here
	//get a pointer to the current document
	CSerializeDoc *pDoc=GetDocument();
	if(pDoc)
	{
		//get the first record from the document
		m_pCurPerson=pDoc->GetFirstRecord();
		if(m_pCurPerson)
		{
			//display the current record
			PopulateView();
		}
	}
}

void CSerializeView::OnBlast() 
{
	// TODO: Add your control notification handler code here
	//get a pointer to the current document
	CSerializeDoc *pDoc=GetDocument();
	if(pDoc)
	{
		//get the last record from the document
		m_pCurPerson=pDoc->GetLastRecord();
		if(m_pCurPerson)
		{
			//display the current record
			PopulateView();
		}
	}
}

void CSerializeView::OnBnext() 
{
	// TODO: Add your control notification handler code here
	//get a pointer to the current document
	CSerializeDoc *pDoc=GetDocument();
	if(pDoc)
	{
		//get the last record from the document
		m_pCurPerson=pDoc->GetNextRecord();
		if(m_pCurPerson)
		{
			//display the current record
			PopulateView();
		}
	}
}

void CSerializeView::OnBprev() 
{
	// TODO: Add your control notification handler code here
	//get a pointer to the current document
	CSerializeDoc *pDoc=GetDocument();
	if(pDoc)
	{
		//get the last record from the document
		m_pCurPerson=pDoc->GetPrevRecord();
		if(m_pCurPerson)
		{
			//display the current record
			PopulateView();
		}
	}	
}

void CSerializeView::OnCbemployed() 
{
	// TODO: Add your control notification handler code here
	//sync the data in the form with the variables
	UpdateData(TRUE);
	//if we have a valid person object, pass the data changes to it
	if(m_pCurPerson)
		m_pCurPerson->SetEmployed(m_bEmployed);
}

void CSerializeView::OnChangeEage() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_pCurPerson)
		m_pCurPerson->SetAge(m_iAge);
	
}

void CSerializeView::OnChangeEname() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_pCurPerson)
		m_pCurPerson->SetName(m_sName);
}

void CSerializeView::OnRMaritalStat() 
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);
	if(m_pCurPerson)
		m_pCurPerson->SetMaritalStatus(m_iMaritalStatus);
	
}

void CSerializeView::NewDataSet()
{
	OnBfirst();
}
