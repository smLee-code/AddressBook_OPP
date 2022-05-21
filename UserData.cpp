#include "pch.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData() : pNext(NULL)
{
	memset(szName, 0, sizeof(szName));		// szName[0] = {0,};
	memset(szPhone, 0, sizeof(szPhone));	// szPhone[0] = {0,};
	nUserDataCounter++;
}

CUserData::~CUserData()
{
	nUserDataCounter--;
}
