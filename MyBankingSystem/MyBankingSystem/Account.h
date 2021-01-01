/**
*@file Account.h
*/
#pragma once
#include <string>
using namespace std;

///@brief �������� Ŭ����
class Account
{
private:
	int accID;
	int balance;
	string cus_name;

public:
	Account(int id, int money, string name);
	~Account();

	int GetAccID() const; ///���� ID Ȯ��
	void ShowAccInfo() const; ///�������� ���
	virtual void Deposit(int money); ///�Ա�
	int Witdraw(int money); ///���
};