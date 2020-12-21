#pragma once
#include <string>
using namespace std;

class NameCard
{
private:
	string name;
	string Comp;
	string PN;
	enum {	Cleck, Senior, Assist, Manager };
	int Position;
public:
	NameCard(string n, string C, string pn, int pos) : name(n), Comp(C), PN(pn), Position(pos) {};
	~NameCard();
	void ShowNameCardInfo();
};