#include "pch.h"
#include "UserData.h"

int CUserData::nUserDataCounter = 0;

CUserData::CUserData() : pNext(NULL)
{
	szName[0] = { 0, };		// ���� : memset(szName, 0, sizeof(szName));
	szPhone[0] = { 0, };	// ���� ����
	nUserDataCounter++;
}

CUserData::~CUserData()
{
	nUserDataCounter--;
}
