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
	Operand* x = new Operand[s.length()];
	Postfix A;
	try
	{
		A.PostfixForm(s, postfix, x, size);
		cout << postfix << endl;
		A.Input_var(x, size);
		double value = A.Calculation(postfix, x, size);
		cout << s << " = " << value;
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
	return 0;
}
