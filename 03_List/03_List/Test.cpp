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
	try
	{
		B.InsertBefore(1, 5, b);
		cout << "List B - Insert key 5 before key 1:" << endl;
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	try
	{
		B.InsertAfter(5, 4, a);
		cout << "List B - Insert key 4 after key 5:" << endl;
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	cout <<"Find the element with key 5: " << B.Search(5) << endl;
	cout <<"Find the element with key 7: " << B.Search(7) << endl;
	try
	{
		B.Remove(5);
		cout << "Delete the elemtnt with key 5: " << endl;
		cout << B;
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	return 0;
}