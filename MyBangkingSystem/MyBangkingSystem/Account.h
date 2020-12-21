#pragma once
#include <string>
using namespace std;

class Account
{
private:
	int accID;
	int balance;
	string cus_name;

public:
	Account(int id, int money, string name);
	~Account();

	int GetAccID() const;
	void ShowAccInfo() const;
	virtual void Deposit(int money);
	int Witdraw(int money);
};