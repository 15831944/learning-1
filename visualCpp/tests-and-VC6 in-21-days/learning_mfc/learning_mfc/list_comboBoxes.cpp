#include <afxwin.h>

#define IDC_LIST 1000
#define IDC_COMBO 1001
#define IDC_OK 1002
#define IDC_RESULT 1003

class CListsComboBoxesApp : public CWinApp
{
public:
	virtual BOOL InitInstance(void);
};

class CListsComboBoxesWindow : public CFrameWnd
{
private:
	CListBox m_cListBox;
	CComboBox m_cComboBox;
	CButton m_cOK;
	CStatic m_cResult;
	CString m_szResult;
public:
	CListsComboBoxesWindow();
	afx_msg void OnListDblClk(void);
	afx_msg void OnComboCloseUp(void);
	afx_msg void OnOK(void);
protected:
	virtual void DoDataExchange(CDataExchange *pDX);	
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CListsComboBoxesWindow,CFrameWnd)
	ON_LBN_DBLCLK(IDC_LIST,OnListDblClk)
	ON_CBN_CLOSEUP(IDC_COMBO,OnComboCloseUp)
	ON_BN_CLICKED(IDC_OK,OnOK)
END_MESSAGE_MAP();


BOOL CListsComboBoxesApp::InitInstance(void)
{
	m_pMainWnd=new CListsComboBoxesWindow;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CListsComboBoxesApp myApp;

CListsComboBoxesWindow::CListsComboBoxesWindow()
{
	Create(NULL,"List and Combo Boxes",WS_OVERLAPPEDWINDOW,CRect(0,0,300,300));
	//create the rectagle for controls
	CRect rect;
	GetClientRect(&rect);
	rect.InflateRect(-20,-20,-20,-20);
	CRect rectList(rect);
	rectList.bottom=rectList.bottom-100;
	rectList.right=rectList.right-rectList.Width()/2-10;
	CRect rectCombo(rect);
	rectCombo.bottom=rectCombo.bottom-100;
	rectCombo.left=rectList.right +20;
	CRect rectButton(rect);
	rectButton.left=rectCombo.left;
	rectButton.top=rectCombo.bottom+10;
	CRect rectStatic(rect);
	rectStatic.right=rectList.right;
	rectStatic.top=rectCombo.bottom+10;
	//create the controls
	m_cListBox.Create(WS_VISIBLE|WS_CHILD|LBS_NOTIFY,rectList,this,IDC_LIST);
	m_cComboBox.Create(WS_VISIBLE|WS_CHILD|CBS_DROPDOWNLIST|LBS_NOTIFY,rectCombo,this,IDC_COMBO);
	m_cOK.Create("Ok",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,rectButton,this,IDC_OK);
	m_cResult.Create("",WS_CHILD|WS_VISIBLE|ES_READONLY,rectStatic,this,IDC_RESULT);
	m_cListBox.AddString("first");
	m_cListBox.AddString("second");
	m_cComboBox.AddString("fist combo");
	m_cComboBox.AddString("second combo");
}

void CListsComboBoxesWindow::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX,IDC_COMBO,CListsComboBoxesWindow::m_cComboBox);
	DDX_Control(pDX,IDC_LIST,CListsComboBoxesWindow::m_cListBox);
	DDX_Text(pDX,IDC_RESULT,m_szResult);
}

void CListsComboBoxesWindow::OnListDblClk(void)
{
	int nSelectie=m_cListBox.GetCurSel();
	if(nSelectie!=LB_ERR)
	{
		m_cListBox.GetText(nSelectie,m_szResult);
		UpdateData(FALSE);
	}
}

void CListsComboBoxesWindow::OnComboCloseUp(void)
{
	m_cComboBox.GetWindowText(m_szResult);
	UpdateData(FALSE);
}

void CListsComboBoxesWindow::OnOK(void)
{
	CString szTemporar;
	m_cComboBox.GetWindowTextA(m_szResult);
	int nSel=m_cListBox.GetCurSel();
	m_cListBox.GetText(nSel,szTemporar);
	m_szResult+=_T(" list =") + szTemporar;
	UpdateData(FALSE);
}