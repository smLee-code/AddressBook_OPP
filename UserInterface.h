#include "MyList.h"

// class CMyList;

class CUserInterface
{
protected:
	CMyList& m_List;

public:
	CUserInterface(CMyList &m_List);
	~CUserInterface();

	void Add();
	void Search();
	void Remove();
	int PrintUI();
	int Run();
};

