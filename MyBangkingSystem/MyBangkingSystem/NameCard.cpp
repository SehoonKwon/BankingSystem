#include "NameCard.h"
#include <iostream>
using namespace std;

#define endl "\n"

void NameCard::ShowNameCardInfo()
{
	cout << "�̸� : " << NameCard::name << endl;
	cout << "ȸ�� : " << NameCard::Comp << endl;
	cout << "��ȭ��ȣ : " << NameCard::PN << endl;
	cout << "���� : " << NameCard::Position << endl;
	cout << endl;
}

NameCard::~NameCard()
{
	cout << "�Ҹ��� ȣ��" << endl;
}