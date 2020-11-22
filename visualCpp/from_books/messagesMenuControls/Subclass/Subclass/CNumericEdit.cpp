// CNumericEdit.cpp : implementation file
//

#include "pch.h"
#include "Subclass.h"
#include "CNumericEdit.h"


// CNumericEdit

IMPLEMENT_DYNAMIC(CNumericEdit, CEdit)

CNumericEdit::CNumericEdit()
{

}

CNumericEdit::~CNumericEdit()
{
}


BEGIN_MESSAGE_MAP(CNumericEdit, CEdit)
	ON_WM_CHAR()
END_MESSAGE_MAP()



// CNumericEdit message handlers




void CNumericEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//Permite numai numere si caracterul backspace
	if ((nChar >= '0' && nChar <= '9') || (nChar == VK_BACK))
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	else
		MessageBeep(MB_ICONASTERISK);
}
