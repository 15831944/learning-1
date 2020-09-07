// Person.cpp: implementation of the CPerson class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "serialize.h"
#include "Person.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_SERIAL(CPerson,CObject,1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPerson::CPerson()
{
	//initialize the class variable
	m_iMaritalStatus=0;
	m_iAge=0;
	m_bEmployed=FALSE;
	m_sName="";
}

CPerson::~CPerson()
{

}

void CPerson::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if(ar.IsStoring())
		ar<<m_sName<<m_iAge<<m_iMaritalStatus<<m_bEmployed;
	else
		ar>>m_sName>>m_iAge>>m_iMaritalStatus>>m_bEmployed;
}
