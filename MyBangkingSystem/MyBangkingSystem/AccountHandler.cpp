#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() : AccNum(0) {};
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < AccNum; i++)
		delete accArr[i];
}

void AccountHandler::ShowMenu() const
{
	cout << "---Menu---" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ���" << endl;
	cout << "5. ����" << endl;
}

void AccountHandler::MakeAccount()
{
	int sel;

	cout << "[�������� ����]" << endl;
	cout << "1. ���뿹�ݰ��� 2.�ſ뿹�ݰ���" << endl;
	cout << "���� : ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
	int id, bal, interRate;
	string name;

	cout << "[���뿹�ݰ��� ����]" << endl;
	
	cout << "���� ID : ";
	cin >> id;
	
	cout << "�̸� : ";
	cin >> name;

	cout << "�Աݾ� : ";
	cin >> bal;

	cout << "������ : ";
	cin >> interRate;
	cout << endl;
	accArr[AccNum++] = new NormalAccount(id, bal, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id, bal, interRate, creditLevel;
	string name;

	cout << "[�ſ���� ����]" << endl;

	cout << "���� ID : ";
	cin >> id;

	cout << "�̸� : ";
	cin >> name;

	cout << "�Աݾ� : ";
	cin >> bal;

	cout << "������ : ";
	cin >> interRate;

	cout << "�ſ��� (1toA, 2toB, 3toC) : ";
	cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[AccNum++] = new HighCreditAccount(id, bal, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[AccNum++] = new HighCreditAccount(id, bal, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[AccNum++] = new HighCreditAccount(id, bal, name, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;

	cout << "[�Ա�]" << endl;
	cout << "����ID : ";
	cin >> id;

	cout << "�Աݾ� : ";
	cin >> money;
	cout << endl;

	while (1)
	{
		try
		{
			for (int i = 0; i < AccNum; i++)
			{
				if (accArr[i]->GetAccID() == id)
				{
					accArr[i]->Deposit(money);
					cout << "�ԱݿϷ�" << endl;
					return;
				}
			}
			cout << "��ȿ���� ���� ID" << endl << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "�Աݾ׸� ���Է��ϼ���" << endl;
		}
	}
}

void AccountHandler::WitharwMoney()
{
	int money;
	int id;

	cout << "[���]" << endl;
	cout << "����ID : ";
	cin >> id;

	cout << "��ݾ� : ";
	cin >> money;
	cout << endl;

	while (1)
	{
		try
		{
			for (int i = 0; i < AccNum; i++)
			{
				if (accArr[i]->GetAccID() == id)
				{
					if (accArr[i]->Witdraw(money) == 0)
					{
						cout << "�ܾ׺���" << endl;
						return;
					}

					cout << "��ݿϷ�" << endl;
					return;
				}
			}

			cout << "��ȿ���� ���� ID" << endl << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "�Աݾ׸� ���Է��ϼ���" << endl;
		}
		catch (InsuffException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "��ݾ׸� ���Է��ϼ���" << endl;
		}
	}
}

void AccountHandler::ShowAllInfo() const
{
	for (int i = 0; i < AccNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}