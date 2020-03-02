#include <iostream>
#include "TList.h"

using namespace std;

int main()
{
	TList<int, int> A;
	int a[1] = {7};
	int b[1] = {6};
	A.PushFront(3, a);
	A.PushBack(1, b);
	cout << "List A - PushFront & PushBack:" << endl;
	cout << A;
	TList<int, int> B(A);
	cout << "List B - copy A:" << endl;
	cout << B;
	cout << "List B - Insert key 5 before key 1:" << endl;
	try
	{
		B.InsertBefore(1, 5, b);
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << "List B - Insert key 5 before key 8:" << endl;
	try
	{
		B.InsertBefore(8, 5, b);
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl << endl;
	}
	cout << "List B - Insert key 4 after key 5:" << endl;
	try
	{
		B.InsertAfter(5, 4, a);
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << "List B - Insert key 4 after key 9:" << endl;
	try
	{
		B.InsertAfter(9, 4, a);
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl << endl;
	}
	cout <<"Find the element with key 5: " << B.Search(5) << endl;
	cout <<"Find the element with key 7: " << B.Search(7) << endl << endl;
	cout << "Delete the elemtnt with key 5: " << endl;
	try
	{
		B.Remove(5);
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout << "Delete the elemtnt with key 7: " << endl;
	try
	{
		B.Remove(7);
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	return 0;
}