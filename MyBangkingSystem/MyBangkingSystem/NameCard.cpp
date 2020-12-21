#include "NameCard.h"
#include <iostream>
using namespace std;

#define endl "\n"

void NameCard::ShowNameCardInfo()
{
	cout << "이름 : " << NameCard::name << endl;
	cout << "회사 : " << NameCard::Comp << endl;
	cout << "전화번호 : " << NameCard::PN << endl;
	cout << "직급 : " << NameCard::Position << endl;
	cout << endl;
}

NameCard::~NameCard()
{
	cout << "소멸자 호출" << endl;
}