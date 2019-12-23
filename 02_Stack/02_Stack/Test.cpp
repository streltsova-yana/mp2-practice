#include <iostream>
#include <string>
#include "PostfixForm.h"
#include "TStack.h"

using namespace std;

int main()
{
	cout << "Enter an expression: ";
	string s, postfix;
	int size;
	cin >> s;
	Operand* x;
	Postfix A;
	try
	{
		A.Count(s, x, size);
		A.PostfixForm(s, postfix);
		cout << postfix << endl;
		A.Input_var(x, size);
		double value = A.Calculation(postfix, x, size);
		cout << s << " = " << value;
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
	delete x;
	return 0;
}
