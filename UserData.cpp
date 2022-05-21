#include "pch.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData() : pNext(NULL)
{
	szName[0] = { 0, };		// 권장 : memset(szName, 0, sizeof(szName));
	szPhone[0] = { 0, };	// 이하 동문
	nUserDataCounter++;
}

CUserData::~CUserData()
{
	nUserDataCounter--;
}
