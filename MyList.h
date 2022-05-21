#include "UserData.h"

#define DATA_FILE_NAME "Address.dat"

class CMyList
{
protected:
	CUserData m_Head;

public:
	CMyList();
	~CMyList();

	int AddNewNode(const char* pszName, const char* pszPhone);
	void PrintAll();
	CUserData* FindNode(const char* pszName);
	int RemoveNode(const char* pszName);

protected:
	int LoadList(const char* pszFileName);
	int SaveList(const char* pszFileName);
	void ReleaseList();
};

