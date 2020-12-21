#pragma once
#include "Account.h"
#include "AccountArray.h"

class AccountHandler
{
private:
	BoundCheckArray<Account*> accArr;
	int AccNum;

public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WitharwMoney();
	void ShowAllInfo() const;
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};