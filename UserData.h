
class CUserData
{
	friend class CMyList;

protected:
	char szName[32];	// �̸�
	char szPhone[32];	// ��ȭ��ȣ

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