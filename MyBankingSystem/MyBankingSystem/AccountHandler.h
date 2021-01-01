/**
*@file AccountHandler.h
*인터페이스 조작
*/
#pragma once
#include "Account.h"
#include "AccountArray.h"

///@brief 인터페이스 조작용 클래스
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