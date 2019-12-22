#include <iostream>
#include "TVector.h"
#include "TMatrix.h"

using namespace std;

int Mode()
{
	cout << "Select an object. To select the object, enter:" << endl;
	cout << "1 - Vector" << endl;
	cout << "2 - Matrix" << endl;
	int mode = 0;
	while ((mode != 1) && (mode != 2))
		cin >> mode;
	return mode;
}

int Menu()
{
	cout << "Select an operation. To select the operation, enter:" << endl;
	cout << "1 - Creating" << endl;
	cout << "2 - Component-by-component addition" << endl;
	cout << "3 - Component-by-component difference" << endl;
	cout << "4 - Adding a constant" << endl;
	cout << "5 - Subtract a constant" << endl;
	cout << "6 - Multiplying by a constant" << endl;
	cout << "7 - Multiplication" << endl;
	cout << "8 - Equating" << endl;
	cout << "9 - Comparison" << endl;
	cout << "10 - Copy constructor" << endl;
	cout << "11 - Exit" << endl;
	int mode = 0;
	while ((mode <= 0) || (mode > 11))
		cin >> mode;
	return mode;
}

//Тест вектора
void VPrint(TVector<double>& v)
{
	try
	{
		cout << "Vector: " << v;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
TVector<double> VCreate()
{
	int n = 0;
	cout << "Enter vector size: ";
	do
	{
		cin >> n;
	} while ((n <= 0) || (n > 10));
	TVector<double> a(n);
	cout << "Enter vector: ";
	try
	{
		cin >> a;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
	return a;
}
void VSum(TVector<double> v)
{
	TVector<double> v1 = VCreate();
	try
	{
		v += v1;
		VPrint(v);
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
void VDif(TVector<double> v)
{
	TVector<double> v1 = VCreate();
	try
	{
		v -= v1;
		VPrint(v);
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
void VAdd(TVector<double> v)
{
	double a;
	cout << "Enter a number: ";
	cin >> a;
	v += a;
	VPrint(v);
}
void VSub(TVector<double> v)
{
	double a;
	cout << "Enter a number: ";
	cin >> a;
	v -= a;
	VPrint(v);
}
void VMulti(TVector<double> v)
{
	double a;
	cout << "Enter a number: ";
	cin >> a;
	v *= a;
	VPrint(v);
}
void VProduct(TVector<double> v)
{
	TVector<double> v1 = VCreate();
	double a;
	try
	{
		a = v * v1;
		cout << a << endl;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
void VEquat(TVector<double> v)
{
	TVector<double> v1 = VCreate();
	cout << "v = v1: " << endl;
	v = v1;
	VPrint(v);
}
void VCompar(TVector<double> v)
{
	TVector<double> v1 = VCreate();
	cout << "v = v1? " << endl;
	if (v == v1)
		cout << "Yes" << endl;
	else cout << "No" << endl;
}
void VCopy(TVector<double> v)
{
	TVector<double> v1(v);
	cout << "A copy of the ";
	VPrint(v1);
}

//Тест матрицы
void MPrint(TMatrix<double>& m)
{
	try
	{
		cout << "Matrix: " << endl;
		cout << m;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
TMatrix<double> MCreate()
{
	int n = 0;
	cout << "Enter matrix size: ";
	do
	{
		cin >> n;
	} while ((n <= 0) || (n > 10));
	TMatrix<double> a(n);
	cout << "Enter matrix:" << endl;
	try
	{
		cin >> a;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
	return a;
}
void MSum(TMatrix<double> m)
{
	TMatrix<double> m1 = MCreate();
	try
	{
		m += m1;
		MPrint(m);
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
void MDif(TMatrix<double> m)
{
	TMatrix<double> m1 = MCreate();
	try
	{
		m -= m1;
		MPrint(m);
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
}
void MAdd(TMatrix<double> m)
{
	double a;
	cout << "Enter a number: ";
	cin >> a;
	m += a;
	MPrint(m);
}
void MSub(TMatrix<double> m)
{
	double a;
	cout << "Enter a number: ";
	cin >> a;
	m -= a;
	MPrint(m);
}
void MMulti(TMatrix<double> m)
{
	double a;
	cout << "Enter a number: ";
	cin >> a;
	m *= a;
	MPrint(m);
}
void MProduct(TMatrix<double> m)
{
	int i = Mode();
	if (i == 1)
	{
		TVector<double> v1 = VCreate();
		try
		{
			TVector<double> tmp = m * v1;
			VPrint(tmp);
		}
		catch (const char* a)
		{
			cout << a << endl;
		}
	}
	else
	{
		TMatrix<double> m1 = MCreate();
		try
		{
			TMatrix<double> tmp = m * m1;
			MPrint(tmp);
		}
		catch (const char* a)
		{
			cout << a << endl;
		}
	}
}
void MEquat(TMatrix<double> m)
{
	TMatrix<double> m1 = MCreate();
	cout << "m = m1: " << endl;
	m = m1;
	MPrint(m);
}
void MCompar(TMatrix<double> m)
{
	TMatrix<double> m1 = MCreate();
	cout << "m = m1? " << endl;
	if (m == m1)
		cout << "Yes" << endl;
	else cout << "No" << endl;
}
void MCopy(TMatrix<double> m)
{
	int i = Mode();
	if (i == 1)
	{
		int n = 0;
		cout << "Enter vector size: ";
		do
		{
			cin >> n;
		} while ((n <= 0) || (n > 10));
		TVector<TVector<double> > v1(n);
		for (int i = 0; i < n; i++)
		{
			TVector<double> a(n - i, i);
			cout << "Enter a vector of length " << n - i << ": ";
			try
			{
				cin >> a;
			}
			catch (const char* a)
			{
				cout << a << endl;
			}
			v1[i] = a;
		}
		TMatrix<double> m1(v1);
		cout << "A copy of the ";
		MPrint(m1);
	}
	else
	{
		TMatrix<double> m1(m);
		cout << "A copy of the ";
		MPrint(m1);
	}
}

int main()
{
	int i = Mode();
	TVector<double> v;
	TMatrix<double> m;
	int j;
	do
	{
		j = Menu();
		switch (j)
		{
		case 1:
			if (i == 1)
			{
				v = VCreate();
				VPrint(v);
			}
			else
			{
				m = MCreate();
				MPrint(m);
			}
			break;
		case 2:
			if (i == 1)
			{
				VSum(v);
			}
			else
			{
				MSum(m);
			}
			break;
		case 3:
			if (i == 1)
			{
				VDif(v);
			}
			else
			{
				MDif(m);
			}
			break;
		case 4:
			if (i == 1)
			{
				VAdd(v);
			}
			else
			{
				MAdd(m);
			}
			break;
		case 5:
			if (i == 1)
			{
				VSub(v);
			}
			else
			{
				MSub(m);
			}
			break;
		case 6:
			if (i == 1)
			{
				VMulti(v);
			}
			else
			{
				MMulti(m);
			}
			break;
		case 7:
			if (i == 1)
			{
				VProduct(v);
			}
			else
			{
				MProduct(m);
			}
			break;
		case 8:
			if (i == 1)
			{
				VEquat(v);
			}
			else
			{
				MEquat(m);
			}
			break;
		case 9:
			if (i == 1)
			{
				VCompar(v);
			}
			else
			{
				MCompar(m);
			}
			break;
		case 10:
			if (i == 1)
			{
				VCopy(v);
			}
			else
			{
				MCopy(m);
			}
			break;
		}
	} while (j != 11);
	return 0;
}