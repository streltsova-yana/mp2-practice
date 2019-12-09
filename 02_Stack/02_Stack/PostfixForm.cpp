#include "PostfixForm.h"

int Postfix::Priority(const char a)
{
	if ((a == '(') || (a == ')'))
		return 0;
	if ((a == '*') || (a == '/'))
		return 1;
	if ((a == '+') || (a == '-'))
		return 2;
};
bool Postfix::operand(const char a)
{
	if ((a == '(') || (a == ')') || (a == '*') || (a == '/') || (a == '+') || (a == '-'))
		return false;
	return true;
};
void Postfix::PostfixForm(string s, string& postfix, Operand* & x, int& size, int& length)
{

	if (s.length() == 0)
	{
		throw "Error: empty string";
	}
	TStack<char> A(s.length() + 1);
	TStack<char> B(s.length() + 1);
	int i = 0;
	size = 0;
	length = 0;
	while (s[i] != '\0')
	{
		if (operand(s[i]))
		{
			A.Push(s[i]);
			length++;
			int flag = 0;
			for (int j = 0; j < size; j++)
				if (s[i] == x[j].name)
					flag = 1;
			if (flag == 0)
				x[size++].name = s[i];
		}
		else
		{
			if (s[i] == '(')
				B.Push(s[i]);
			if (s[i] == ')')
			{
				while (B.Top() != '(')
				{
					A.Push(B.Top());
					length++;
					B.Pop();
					if (B.IsEmpty())
						throw "Error: no '('";
				}
				B.Pop();
			}
			if ((s[i] != '(') && (s[i] != ')'))
			{
				if (!B.IsEmpty())
				{
					while (Priority(B.Top()) >= Priority(s[i]))
					{
						A.Push(B.Top());
						length++;
						B.Pop();
					}
				}
				B.Push(s[i]);
			}
		}
		i++;
	}
	while (!B.IsEmpty())
	{
		A.Push(B.Top());
		length++;
		B.Pop();
	}
	while (!A.IsEmpty())
	{
		postfix += A.Top();
		A.Pop();
	}
	for (int i = 0; i < length / 2; i++)
		swap(postfix[i], postfix[length - 1 - i]);
}
void Postfix::Input_var(Operand*& x, int size)
{
	cout << "Enter the value of the variables in the order in which they are received" << endl;
	for (int i = 0; i < size; i++)
		cin >> x[i].value;
}
double Postfix::Calculation(string postfix, Operand* x, int size, int length)
{
	TStack<double> A(length);
	for (int i = 0; i < length; i++)
	{
		if (operand(postfix[i]))
		{
			for (int j = 0; j < size; j++)
				if (x[j].name == postfix[i])
					A.Push(x[j].value);
		}
		else
		{
			double x1, x2, res;
			x1 = A.Top();
			A.Pop();
			x2 = A.Top();
			A.Pop();

			if (postfix[i] == '+')
				res = x2 + x1;
			if (postfix[i] == '-')
				res = x2 - x1;
			if (postfix[i] == '*')
				res = x2 * x1;
			if (postfix[i] == '/')
			{
				if (x1 == 0)
					throw "Error: Division by 0";
				res = x2 / x1;
			}
			A.Push(res);
		}
	}
	return A.Top();
}