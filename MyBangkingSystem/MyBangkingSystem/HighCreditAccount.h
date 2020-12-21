#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;

public:
	HighCreditAccount(int id, int money, string name, int rate, int special) : NormalAccount(id, money, name, rate), specialRate(special) {}
	virtual ~HighCreditAccount() {}
	virtual void Deposit(int money)
	{
		if (money < 0)
			throw MinusException(money);

		NormalAccount::Deposit(money);
		Account::Deposit(money*(specialRate / 100.0));
	}
};