
class CUserData
{
	friend class CMyList;

protected:
	char szName[32];	// 이름
	char szPhone[32];	// 전화번호

	CUserData* pNext;

	static int nUserDataCounter;

public:
	CUserData();
	~CUserData();

	const char* GetName() const { return szName;  }
	const char* GetPhone() const { return szPhone;  }
	const CUserData* GetNext() const { return pNext;  }

	static int GetUserDataCounter() { return nUserDataCounter;  }

};