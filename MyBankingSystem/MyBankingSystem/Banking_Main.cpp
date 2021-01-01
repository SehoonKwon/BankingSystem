/**
*@mainpage
*@brief 메인페이지
*/
#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main()
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택 : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHRAW:
			manager.WitharwMoney();
			break;
		case INQUIRE:
			manager.ShowAllInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "올바르지 않은 입력입니다" << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}
