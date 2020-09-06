#pragma once
#include "resource.h"
#include <afxwin.h>
#include <list>

using std::list;

// CPaintMouse dialog

class CPaintMouse : public CDialog
{
	DECLARE_DYNAMIC(CPaintMouse)
private:
    list<list<CPoint> *> m_lpPointList;
	list<CPoint> * m_plPointList;
	void FreeListCPoint(list<CPoint> *lpoint)
	{
		lpoint->clear();
		delete lpoint;
	}
	CMenu *m_pMenuOperations;
public:
	CPaintMouse(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPaintMouse();

// Dialog Data
	enum { IDD = IDD_PAINTMOUSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg void OnMouseMove(UINT nFlags,CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags,CPoint point);
	afx_msg void OnReset();
	afx_msg void OnRepaint();
	afx_msg void OnLButtonDown(UINT nFlags,CPoint point);

	DECLARE_MESSAGE_MAP()
};
