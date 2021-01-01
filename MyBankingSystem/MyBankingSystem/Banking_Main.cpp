/**
*@mainpage
*@brief ����������
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
		cout << "���� : ";
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
			cout << "�ùٸ��� ���� �Է��Դϴ�" << endl;
			break;
		}
		cout << endl;
	}

	return 0;
}
