#pragma once
#include <iostream>
#include <string>
#include "TStack.h"

using namespace std;

struct Operand
{
	char name;
	double value;
};
class Postfix
{
private:
	static int Priority(const char a);
	static bool operand(const char a);
public:
	static void PostfixForm(string s, string& postfix, Operand* & x, int& size, int& length);
	static void Input_var(Operand* & x, int size);
	static double Calculation(string postfix, Operand* x, int size, int length);
};