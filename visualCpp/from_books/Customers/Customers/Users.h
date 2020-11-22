#pragma once
#include "CUser.h"
void AFXAPI SerializeElements(CArchive& ar, CUser** pUser, int nCount) {
	for (int i = 0; i < nCount; i++, pUser++) {
		if (ar.IsStoring()) {
			(*pUser)->Serialize(ar);
		}
		else {
			CUser* pNewUser = new CUser;
			pNewUser->Serialize(ar);
			*pUser = pNewUser;
		}
	}
}