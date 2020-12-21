#pragma once
#include "Account.h"
#include "AccountException.h"

class NormalAccount : public Account
{
private:
	int interRate; // 이자율 % 단위

public:
	NormalAccount(int id, int money, string name, int rate) : Account(id, money, name), interRate(rate) {}
	virtual ~NormalAccount() {}
	virtual void Deposit(int money)
	{
		if (money < 0)
			throw MinusException(money);

		Account::Deposit(money); // 원금추가
		Account::Deposit(money*(interRate / 100.0)); //이자 추가
	}
};