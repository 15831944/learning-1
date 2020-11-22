#include <afxwin.h>
class CHelloApp : public CWinApp {
public:
	BOOL InitInstance();
};

class CHelloWnd : public CFrameWnd {
public:
	CHelloWnd();
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

BOOL CHelloApp::InitInstance() {
	m_pMainWnd = new CHelloWnd;
	if (m_pMainWnd != 0) {
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}
	return FALSE;
}

//create map of messages for WM_PAINT
BEGIN_MESSAGE_MAP(CHelloWnd, CFrameWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()

CHelloWnd::CHelloWnd() {
	Create(NULL, _T("Hello!!"));
}

void CHelloWnd::OnPaint() {
	CRect rcClient;
	CPaintDC dc(this);
	GetClientRect(rcClient);
	dc.DrawText(_T("We salute you planet Earth!!"), -1, rcClient, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}

CHelloApp theApplication;