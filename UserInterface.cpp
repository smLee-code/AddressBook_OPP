#include "pch.h"
#include "UserInterface.h"
#include "MyList.h"

CUserInterface::CUserInterface(CMyList &rList) : m_List(rList)
{

}


CUserInterface::~CUserInterface()
{

}

void CUserInterface::Add()
{
	char szName[32] = { 0, };
	char szPhone[32] = { 0, };

	cout << "Input name : ";
	cin >> szName;

	cout << "Input phone number : ";
	cin >> szPhone;

	m_List.AddNewNode(szName, szPhone);
}

void CUserInterface::Search()
{
	char szName[32];
	CUserData* pNode = NULL;

	cout << "Input name : ";
	cin >> szName;

	pNode = m_List.FindNode(szName);
	if (pNode != NULL)
	{
		printf("[%p] %s\t%s [%p]\n",
			pNode,
			pNode->GetName(), 
			pNode->GetPhone(),
			pNode->GetNext());
	}
	else
	{
		cout << "ERROR: 데이터를 찾을 수 없습니다." << endl;
	}
}

void CUserInterface::Remove()
{
	char szName[32];

	cout << "Input name : ";
	cin >> szName;

	m_List.RemoveNode(szName);
}

int CUserInterface::PrintUI()
{
	int nInput = 0;

	system("cls");
	cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:";
	cin >> nInput;

	return nInput;
}

int CUserInterface::Run()
{
	int nMenu = 0;

	while ((nMenu = PrintUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:
			Add();
			break;
		case 2:
			Search();
		case 3:
			m_List.PrintAll();
			break;
		case 4:
			break;
			Remove();
			break;
		}
	}

	return nMenu;
}