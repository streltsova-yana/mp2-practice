#include "PostfixForm.h"

int Postfix::Priority(const char a)
{
	if ((a == '(') || (a == ')'))
		return 2;
	if ((a == '*') || (a == '/'))
		return 1;
	if ((a == '+') || (a == '-'))
		return 0;
};
bool Postfix::operand(const char a)
{
	if ((a == '(') || (a == ')') || (a == '*') || (a == '/') || (a == '+') || (a == '-'))
		return false;
	return true;
};
void Postfix::Count(const string& s, Operand*& x, int& size)
{
	size = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		if (operand(s[i]))
		{
			int flag = 0;
			for (int j = 0; j < i; j++)
				if (s[i] == s[j])
					flag = 1;
			if (flag == 0)
				size++;
		}
		i++;
	}
	x = new Operand[size];
	int k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (operand(s[i]))
		{
			int flag = 0;
			for (int j = 0; j < k; j++)
				if (s[i] == x[j].name)
					flag = 1;
			if (flag == 0)
				x[k++].name = s[i];
		}
		i++;
	}
}
void Postfix::PostfixForm(const string& s, string& postfix)
{

	if (s.length() == 0)
	{
		throw "Error: empty string";
	}
	TStack<char> A(s.length() + 1);
	TStack<char> B(s.length() + 1);
	int i = 0;
	int left = 0, right = 0;
	while (s[i] != '\0')
	{
		if (operand(s[i]))
			A.Push(s[i]);
		else
		{
			if (s[i] == '(')
			{
				B.Push(s[i]);
				left++;
			}
			if (s[i] == ')')
			{
				if (B.IsEmpty())
					throw "Error: no '('";
				while (B.Top() != '(')
				{
					A.Push(B.Top());
					B.Pop();
					if (B.IsEmpty())
						throw "Error: no '('";
				} 
				B.Pop();
				right++;
			}
			if ((s[i] != '(') && (s[i] != ')'))
			{
				while ((!B.IsEmpty()) && (Priority(B.Top()) >= Priority(s[i])) && (B.Top() != '('))
				{
					A.Push(B.Top());
					B.Pop();
				}
				B.Push(s[i]);
			}
		}
		i++;
	}
	if (left != right)
		throw "Error: no ')'";
	while (!B.IsEmpty())
	{
		A.Push(B.Top());
		B.Pop();
	}
	while (!A.IsEmpty())
	{
		postfix += A.Top();
		A.Pop();
	}
	for (int i = 0; i < postfix.length() / 2; i++)
		swap(postfix[i], postfix[postfix.length() - 1 - i]);
}
void Postfix::Input_var(Operand*& x, int size)
{
	cout << "Enter the variable values in the following order: ";
	for (int i = 0; i < size; i++)
		cout << x[i].name << " ";
	cout << endl;
	for (int i = 0; i < size; i++)
		cin >> x[i].value;
}
double Postfix::Calculation(const string& postfix, Operand* & x, int size)
{
	TStack<double> A(postfix.length());
	for (int i = 0; i < postfix.length(); i++)
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