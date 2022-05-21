#include "pch.h"
#include "MyList.h"

CMyList::CMyList()
{
	m_Head.pNext = NULL;
	LoadList(DATA_FILE_NAME);
}

CMyList::~CMyList()
{
	SaveList(DATA_FILE_NAME);
	ReleaseList();
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone)
{
	if (FindNode(pszName) != NULL)
		return 0;

	CUserData* pNewUser = new CUserData();
	strcpy_s(pNewUser->szName, sizeof(pNewUser->szName), pszName);
	strcpy_s(pNewUser->szPhone, sizeof(pNewUser->szPhone), pszPhone);

	pNewUser->pNext = m_Head.pNext;
	m_Head.pNext = pNewUser;

	return 1;
}

void CMyList::PrintAll()
{
	int n = 1;
	CUserData* pTmp = m_Head.pNext;

	while (pTmp != NULL)
	{
		cout << "[" << n << "] " << pTmp->szName << "\t" << pTmp->szPhone << endl;
		
		pTmp = pTmp->pNext;
		n++;
	}

	cout << "CUserData Counter : " << CUserData::GetUserDataCounter() << endl;
}

CUserData* CMyList::FindNode(const char* pszName)
{
	CUserData* pTmp = m_Head.pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szName, pszName) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

int CMyList::RemoveNode(const char* pszName)
{
	CUserData* pPrevNode = &m_Head;
	CUserData* pDelete = NULL;

	while (pPrevNode->pNext != NULL)
	{
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->szName, pszName) == 0)
		{
			pPrevNode->pNext = pDelete->pNext;
			delete pDelete;

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}

int CMyList::LoadList(const char* pszFileName)
{
	FILE* fp = NULL;
	CUserData user;

	fopen_s(&fp, pszFileName, "rb");

	if (fp == NULL)
		return 0;

	ReleaseList();

	while (fread(&user, sizeof(CUserData), 1, fp))
		AddNewNode(user.szName, user.szPhone);

	fclose(fp);

	return 0;
}

int CMyList::SaveList(const char* pszFileName)
{
	FILE* fp = NULL;
	CUserData* pTmp = m_Head.pNext;

	fopen_s(&fp, pszFileName, "wb");

	if (fp == NULL)
	{
		cout << "ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;

		return 0;
	}

	while (pTmp != NULL)
	{
		if (fwrite(pTmp, sizeof(CUserData), 1, fp) != 1)
			cout << "ERROR: " << pTmp->szName << "에 대한 정보를 저장하는 데 실패했습니다." << endl;

		pTmp = pTmp->pNext;
	}

	fclose(fp);

	return 1;
}

void CMyList::ReleaseList()
{
	CUserData* pTmp = m_Head.pNext;
	CUserData* pDelete = NULL;
	
	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		delete pDelete;
	}

	m_Head.pNext = NULL;
}

