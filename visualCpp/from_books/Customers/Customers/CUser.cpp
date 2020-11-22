#include "pch.h"
#include "CUser.h"

IMPLEMENT_SERIAL(CUser, CObject, 1);

CUser::CUser() {

}

CUser::CUser(const CString& szName, const CString& szAddr) {
	Set(szName, szAddr);
}

void CUser::Set(const CString& szName, const CString& szAddr) {
	m_szAddr = szAddr;
	m_szName = szName;
}

CString CUser::GetAddr() const {
	return m_szAddr;
}

CString CUser::GetName() const {
	return m_szName;
}

void CUser::Serialize(CArchive& ar) {
	if (ar.IsLoading()) {
		ar >> m_szName >> m_szAddr;
	}
	else {
		ar << m_szName << m_szAddr;
	}
}