/**
*@file AccountHandler.h
*�������̽� ����
*/
#pragma once
#include "Account.h"
#include "AccountArray.h"

///@brief �������̽� ���ۿ� Ŭ����
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
	void MakeNormalAccount();
	void MakeCreditAccount();
	~AccountHandler();
};