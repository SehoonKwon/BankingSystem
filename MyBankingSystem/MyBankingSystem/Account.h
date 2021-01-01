/**
*@file Account.h
*/
#pragma once
#include <string>
using namespace std;

///@brief 계좌정보 클래스
class Account
{
private:
	int accID;
	int balance;
	string cus_name;

public:
	Account(int id, int money, string name);
	~Account();

	int GetAccID() const; ///계좌 ID 확인
	void ShowAccInfo() const; ///계좌정보 출력
	virtual void Deposit(int money); ///입금
	int Witdraw(int money); ///출금
};