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
	static void Count(const string& s, Operand*& x, int& size);
	static void PostfixForm(const string& s, string& postfix);
	static void Input_var(Operand* & x, int size);
	static double Calculation(const string& postfix, Operand* & x, int size);
};