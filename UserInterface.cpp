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

}

void CUserInterface::Search()
{

}

void CUserInterface::Remove()
{

}

int CUserInterface::PrintUI()
{

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
			m_List.PrintAll();	// 원문 : PrintAll(); - 컴파일 오류로 수정
			break;
		case 4:
			break;
			Remove();
			break;
		}
	}

	return nMenu;
}