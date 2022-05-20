#include "UserData.h"

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
	void ReleaseList();
	
};

