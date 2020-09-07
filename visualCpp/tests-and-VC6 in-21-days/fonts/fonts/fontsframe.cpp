//implementation of the frame class
#include "fontsframe.h"

IMPLEMENT_DYNAMIC(CFontsFrame,CFrameWnd);
BEGIN_MESSAGE_MAP(CFontsFrame,CFrameWnd)
	//{{AFX_MSG_MAP(CFontsFrame)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP();

CFontsFrame::CFontsFrame()
{
	CRect rect;
	Create(NULL,_T("Fonts windows"),WS_OVERLAPPEDWINDOW|WS_VISIBLE,CRect(0,0,200,200));
	GetClientRect(&rect);
	rect-=LPCRECT(CRect(20,20,40,0));
	rect.bottom=+80;
	m_sb=new CStatic();
	m_sb->Create(_T("This is the static text for the font"),WS_CHILD|WS_VISIBLE,rect,this);
	LOGFONT strFont;
	strFont.lfHeight=16;
	strFont.lfWidth=0;
	strFont.lfEscapement=0;
	strFont.lfOrientation=0;
	strFont.lfWeight=FW_NORMAL;
	strFont.lfItalic=0;
	strFont.lfUnderline=0;
	strFont.lfStrikeOut=0;
	strFont.lfCharSet=ANSI_CHARSET;
	strFont.lfOutPrecision=OUT_DEFAULT_PRECIS;
	strFont.lfClipPrecision=CLIP_DEFAULT_PRECIS;
	strFont.lfQuality=PROOF_QUALITY;
	strFont.lfPitchAndFamily=VARIABLE_PITCH|FF_ROMAN;
	wcscpy(strFont.lfFaceName,_T("Times New Roman"));
	CFont *_font;
	_font=new CFont();
	_font->CreateFontIndirectW(&strFont);
	m_sb->SetFont(_font);
	CClientDC dc(this);
	dc.TextOut(20,100,_T("test de font big"));
	delete _font;
}
CFontsFrame::~CFontsFrame()
{
}

void CFontsFrame::OnPaint()
{
	CPaintDC pDC(this);
	UINT position=100;
	pDC.TextOutW(20,100,_T("test de font big"));
	LOGFONT strFont;
	strFont.lfHeight=8;
	strFont.lfWidth=0;
	strFont.lfEscapement=0;
	strFont.lfOrientation=0;
	strFont.lfWeight=FW_NORMAL;
	strFont.lfItalic=0;
	strFont.lfUnderline=0;
	strFont.lfStrikeOut=0;
	strFont.lfCharSet=ANSI_CHARSET;
	strFont.lfOutPrecision=OUT_DEFAULT_PRECIS;
	strFont.lfClipPrecision=CLIP_DEFAULT_PRECIS;
	strFont.lfQuality=PROOF_QUALITY;
	strFont.lfPitchAndFamily=VARIABLE_PITCH|FF_ROMAN;
	wcscpy(strFont.lfFaceName,_T("Times New Roman"));
	CFont *_font;
	_font=new CFont();
	_font->CreateFontIndirectW(&strFont);
	CFont *old_font;
	old_font=pDC.SelectObject(_font);
	old_font->GetLogFont(&strFont);
	position+=strFont.lfHeight;
	CPen *_pen;
	_pen=new CPen(PS_DOT,1,RGB(0,0,255));
	CPen *old_pen;
	old_pen=pDC.SelectObject(_pen);
	pDC.TextOutW(20,position,_T("test de font big 2"));
	pDC.SelectObject(old_font);
	position+=strFont.lfHeight+10;	
	CRect rect;
	GetClientRect(&rect);
	pDC.MoveTo(rect.left+20,position);
	pDC.LineTo(rect.right-20,position);
	pDC.SelectObject(old_pen);
	delete _font;
	delete _pen;
}