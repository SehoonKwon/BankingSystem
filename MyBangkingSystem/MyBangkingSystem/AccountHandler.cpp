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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 출력" << endl;
	cout << "5. 종료" << endl;
}

void AccountHandler::MakeAccount()
{
	int sel;

	cout << "[계좌종류 선택]" << endl;
	cout << "1. 보통예금계좌 2.신용예금계좌" << endl;
	cout << "선택 : ";
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

	cout << "[보통예금계좌 개설]" << endl;
	
	cout << "계좌 ID : ";
	cin >> id;
	
	cout << "이름 : ";
	cin >> name;

	cout << "입금액 : ";
	cin >> bal;

	cout << "이자율 : ";
	cin >> interRate;
	cout << endl;
	accArr[AccNum++] = new NormalAccount(id, bal, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id, bal, interRate, creditLevel;
	string name;

	cout << "[신용계좌 개설]" << endl;

	cout << "계좌 ID : ";
	cin >> id;

	cout << "이름 : ";
	cin >> name;

	cout << "입금액 : ";
	cin >> bal;

	cout << "이자율 : ";
	cin >> interRate;

	cout << "신용등급 (1toA, 2toB, 3toC) : ";
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

	cout << "[입금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	cout << "입금액 : ";
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
					cout << "입금완료" << endl;
					return;
				}
			}
			cout << "유효하지 않은 ID" << endl << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "입금액만 재입력하세요" << endl;
		}
	}
}

void AccountHandler::WitharwMoney()
{
	int money;
	int id;

	cout << "[출금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	cout << "출금액 : ";
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
						cout << "잔액부족" << endl;
						return;
					}

					cout << "출금완료" << endl;
					return;
				}
			}

			cout << "유효하지 않은 ID" << endl << endl;
			return;
		}
		catch (MinusException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "입금액만 재입력하세요" << endl;
		}
		catch (InsuffException& expt)
		{
			expt.ShowExceptionInfo();
			cout << "출금액만 재입력하세요" << endl;
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