#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountException.h"

//�⺻ ������
Account::Account(int id, int money, string name) : accID(id), balance(money), cus_name(name) {};

Account::~Account() {};

int Account::GetAccID() const
{
	return accID;
}

void Account::ShowAccInfo() const
{
	cout << "����ID : " << accID << endl;
	cout << "�̸� : " << cus_name << endl;
	cout << "�ܾ� : " << balance << endl;
}

void Account::Deposit(int money)
{
	if (money < 0)
		throw MinusException(money);

	balance += money;
}

int Account::Witdraw(int money)
{
	if (balance < money)
		throw InsuffException(balance, money);

	balance -= money;
	return money;
}