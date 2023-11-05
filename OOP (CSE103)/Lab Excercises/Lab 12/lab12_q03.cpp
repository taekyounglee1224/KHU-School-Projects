#pragma once 
#include <iostream>
#include <string>
using namespace std;


#include "Text.h"

string Text::get() { return text; }
void Text::append(string _t) { text += _t; }


#include "FancyText.h"

FancyText::FancyText(string _t, string _lb, string _rb, string _con) :
	Text::Text(_t), left_brac(_lb), right_brac(_rb), connector(_con) {}
string FancyText::get() {
	return left_brac + Text::get() + right_brac;
}
void FancyText::append(string _extra) {
	Text::Text::append(connector + _extra);
}

#include "FixedText.h"
FixedText::FixedText() : Text::Text("FIXED") {}
string FixedText::get() { return text; }
void FixedText::append(string _t) {}

#include "Text.h"
#include "FancyText.h"
#include "FixedText.h"


#include <iostream>
#include <string>
using namespace std;

int main() {
	Text t1("Plain");
	t1.append("A");
	cout << t1.get() << endl;

	FancyText t2("Fancy", "<<", ">>", "***");
	t2.append("A");
	cout << t2.get() << endl;

	FixedText t3;
	t3.append("A");
	cout << t3.get() << endl;
	t1 = t2;
	return 0;
}

