// Spinner.h: interface for the CSpinner class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPINNER_H__010DDE2C_CAAA_4025_9EAF_E40F1FE94490__INCLUDED_)
#define AFX_SPINNER_H__010DDE2C_CAAA_4025_9EAF_E40F1FE94490__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpinner  :public CObject
{
public:
	BOOL *GetContinue(){return m_bContinue;}
	void SetContinue(BOOL *bContinue){m_bContinue=bContinue;}
	CWnd * GetViewWnd(){ return m_pViewWnd;}
	void SetLength(int iLength) {m_iRadius=iLength;}
	void SetViewWnd(CWnd* pWnd) {m_pViewWnd=pWnd;}
	void SetPoint(CPoint pPoint){m_pCenter=pPoint;}
	void Draw();
	CSpinner();
	virtual ~CSpinner();
private:
	BOOL* m_bContinue;
	CWnd* m_pViewWnd;
	static COLORREF m_crColors[8];
	CPoint m_pCenter;
	int m_iRadius;
	int m_nMinute;
	int m_crColor;

};

#endif // !defined(AFX_SPINNER_H__010DDE2C_CAAA_4025_9EAF_E40F1FE94490__INCLUDED_)
