/**
*@file HighCredeitAccount.h
*신용도 높은 고객 전용 계좌
*/
#pragma once
#include "NormalAccount.h"

///@brief 신용계좌 클래스
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