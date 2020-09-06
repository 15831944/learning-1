//windows include
#include<afxwin.h>
#include <sstream>
#include <string>

#define IDC_BUTTON 200
#define IDC_EDITRO 201
#define IDC_RADIO1 202
#define IDC_RADIO2 203
#define IDC_RADIO3 204

//class for windows application
class CControls2App : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

//class for window
class CControls2Windows : public CFrameWnd
{
public:
	CControls2Windows();
	afx_msg void OnButtonClicked(void);
	afx_msg void OnRadio1Clicked(void);
	afx_msg void OnRadio2Clicked(void);
	afx_msg void OnRadio3Clicked(void);
protected:
	CString m_sDisplay;
	CEdit m_cEditRO;
	CButton m_cButton;
	CButton m_cRadio1;
	CButton m_cRadio2;
	CButton m_cRadio3;
	int m_iRadio1;
	int m_iRadio2;
	void DoDataExchange(CDataExchange *pDX);
	DECLARE_MESSAGE_MAP();
};

BOOL CControls2App::InitInstance()
{
	m_pMainWnd=new CControls2Windows;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CControls2App myApp;

BEGIN_MESSAGE_MAP(CControls2Windows,CFrameWnd)
	ON_BN_CLICKED(IDC_BUTTON,OnButtonClicked)
	ON_BN_CLICKED(IDC_RADIO1,OnRadio1Clicked)
	ON_BN_CLICKED(IDC_RADIO2,OnRadio2Clicked)
	ON_BN_CLICKED(IDC_RADIO3,OnRadio3Clicked)
END_MESSAGE_MAP();

void CControls2Windows::DoDataExchange(CDataExchange *pDX)
{
	DDX_Text(pDX,IDC_EDITRO,m_sDisplay);
	DDX_Radio(pDX,IDC_RADIO1,m_iRadio1);
}

CControls2Windows::CControls2Windows()
{
	//Create the windows
	Create(NULL,"Controls2",WS_OVERLAPPEDWINDOW,CRect(0,0,400,400));
	//rectangle
	CRect rect;
	//compute the rectangle for the button
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,-20,0,0);
	m_cButton.Create("Hit me!!",WS_CHILD|WS_VISIBLE|SS_CENTER|BS_PUSHBUTTON,rect,this,IDC_BUTTON);
	//compute the rectangle for the ro edit view
	GetClientRect(&rect);
	rect.top=rect.top+rect.Height()/2+10;
	rect.right=rect.left+rect.Width()/2-10;
	rect.InflateRect(-20,0,0,-20);
	m_cEditRO.Create(WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_READONLY,rect,this,IDC_EDITRO);
	//compute the rectangle for the groupbox
	GetClientRect(&rect);
	rect.bottom=rect.top+rect.Height()/2-10;
	rect.left=rect.left+rect.Width()/2+10;
	rect.InflateRect(0,-20,-20,0);
	CRect rect_radio;
	rect_radio=rect;
	rect_radio.bottom=rect_radio.top+rect_radio.Height()/3;
	m_cRadio1.Create("one",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON|WS_GROUP,rect_radio,this,IDC_RADIO1);
	rect_radio=rect;
	rect_radio.top=rect_radio.top+rect_radio.Height()/3;
	rect_radio.bottom=rect_radio.top+2*rect_radio.Height()/3;
	m_cRadio2.Create("two",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,rect_radio,this,IDC_RADIO2);
	rect_radio=rect;
	rect_radio.top=rect_radio.top+2*rect_radio.Height()/3;
	m_cRadio3.Create("three",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,rect_radio,this,IDC_RADIO3);
}

void CControls2Windows::OnButtonClicked(void)
{
	std::ostringstream oss;
	UpdateData(TRUE);
	m_sDisplay="you have hit ";
	oss<<m_iRadio1;
	m_sDisplay+=(oss.str()).c_str();
	UpdateData(FALSE);
}

void CControls2Windows::OnRadio1Clicked(void)
{
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
}

void CControls2Windows::OnRadio2Clicked(void)
{
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO2);
}

void CControls2Windows::OnRadio3Clicked(void)
{
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO3);
}