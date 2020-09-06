//definition of class for frame window
#include <afxwin.h>
#ifndef CFONTSFRAME
#define CFONTSFRAME

class CFontsFrame : public CFrameWnd
{
	DECLARE_DYNAMIC(CFontsFrame);
	CStatic *m_sb;
public:
	CFontsFrame();
	~CFontsFrame();
	//{{AFX_MSG(CFontsFrame)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};

#endif
