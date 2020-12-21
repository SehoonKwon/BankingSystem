#pragma once
#include "Account.h"
#include "AccountException.h"

class NormalAccount : public Account
{
private:
	int interRate; // ������ % ����

public:
	NormalAccount(int id, int money, string name, int rate) : Account(id, money, name), interRate(rate) {}
	virtual ~NormalAccount() {}
	virtual void Deposit(int money)
	{
		if (money < 0)
			throw MinusException(money);

		Account::Deposit(money); // �����߰�
		Account::Deposit(money*(interRate / 100.0)); //���� �߰�
	}
};