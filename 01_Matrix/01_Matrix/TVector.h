#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class TVector
{
protected:
	int size;
	int startInd;
	T* x;
public:
	explicit TVector(int _size = 10, int _startInd = 0);
	TVector(const TVector& a);
	virtual ~TVector();
	int GetInd() const;
	int GetSize() const;

	//Сложение, вычитание, умножение на константу
	TVector operator+(T elem); 
	TVector& operator+=(T elem);
	TVector operator-(T elem);
	TVector& operator-=(T elem);
	TVector operator*(T elem);
	TVector& operator*=(T elem);

	//Сложение, вычитание векторов
	TVector operator+(const TVector& a); 
	TVector& operator+=(const TVector& a);
	TVector operator-(const TVector& a);
	TVector& operator-=(const TVector& a);

	T length() const; //Длина вектора
	T operator*(const TVector& a); //Скалярное произведение
	TVector& operator=(const TVector& a); //Операция присваивания

	//Операции сравнения
	bool operator==(const TVector& a) const; 
	bool operator!=(const TVector& a) const;

	//Операции индексации
	T& operator[](int i);
	const T& operator[](int i) const;

	//Операции ввода, вывода
	friend istream& operator>>(istream& in, TVector& a)
	{

		if (a.size == 0)
			throw "Error: empty vector";
		for (int i = 0; i < a.size; i++)
			in >> a.x[i];
		return in;
	};
	friend ostream& operator<<(ostream& out, const TVector& a)
	{
		for (int i = 0; i < a.GetInd(); i++)
			out << setw(5) << setprecision(2) << right << " ";
		for (int i = 0; i < a.size; i++)
			out << setw(5) << setprecision(2) << right << a.x[i];
		cout << endl;
		return out;
	};
};

template <typename T>
TVector<T>::TVector(int _size, int _startInd)
{
	this->size = _size;
	this->startInd = _startInd;
	this->x = new T[this->size];
};
template <typename T>
TVector<T>::TVector(const TVector& a)
{
	this->size = a.size;
	this->startInd = a.startInd;
	this->x = new T[this->size];
	for (int i = 0; i < this->size; i++)
		this->x[i] = a.x[i];
};
template <typename T>
TVector<T>::~TVector()
{
	delete[] this->x;
	this->size = 0;
	this->startInd = 0;
};
template <typename T>
int  TVector<T>::GetInd() const
{
	return this->startInd;
}
template <typename T>
int TVector<T>::GetSize() const
{
	return this->size;
};

//Сложение, вычитание, умножение на константу
template <typename T>
TVector<T> TVector<T>::operator+(T elem)
{
	TVector tmp(this->size, this->startInd);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] + elem;
	return tmp;
};
template <typename T>
TVector<T>& TVector<T>::operator+=(T elem)
{
	for (int i = 0; i < this->size; i++)
		this->x[i] += elem;
	return *this;
};
template <typename T>
TVector<T> TVector<T>::operator-(T elem)
{
	TVector tmp(this->size, this->startInd);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] - elem;
	return tmp;
};
template <typename T>
TVector<T>& TVector<T>::operator-=(T elem)
{
	for (int i = 0; i < this->size; i++)
		this->x[i] -= elem;
	return *this;
};
template <typename T>
TVector<T> TVector<T>::operator*(T elem)
{
	TVector tmp(this->size, this->startInd);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] =this-> x[i] * elem;
	return tmp;
};
template <typename T>
TVector<T>& TVector<T>::operator*=(T elem)
{
	for (int i = 0; i < this->size; i++)
		this->x[i] *= elem;
	return *this;
};

//Сложение, вычитание векторов
template <typename T>
TVector<T> TVector<T>::operator+(const TVector& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of vectors";
	TVector tmp(this->size, this->startInd);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] + a.x[i];
	return tmp;
};
template <typename T>
TVector<T>& TVector<T>::operator+=(const TVector& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of vectors";
	for (int i = 0; i < this->size; i++)
		this->x[i] += a.x[i];
	return *this;
};
template <typename T>
TVector<T> TVector<T>::operator-(const TVector& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of vectors";
	TVector tmp(this->size, this->startInd);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] - a.x[i];
	return tmp;
};
template <typename T>
TVector<T>& TVector<T>::operator-=(const TVector& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of vectors";
	for (int i = 0; i < this->size; i++)
		this->x[i] -= a.x[i];
	return *this;
};

//Длина вектора
template <typename T>
T TVector<T>::length() const
{
	T l = 0;
	for (int i = 0; i < this->size; i++)
		l += (this->x[i] * this->x[i]);
	return sqrt(l);
};

//Скалярное произведение
template <typename T>
T TVector<T>::operator*(const TVector& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of vectors";
	T S = 0;
	for (int i = 0; i < this->size; i++)
		S += (this->x[i] * a.x[i]);
	return S;
};

//Операция присваивания
template <typename T>
TVector<T>& TVector<T>::operator=(const TVector& a)
{
	if (*this == a)
	{
		return *this;
	}
	if (this->size != a.size)
	{
		delete[] this->x;
		this->size = a.size;
		this->x = new T[this->size];
	}
	this->startInd = a.startInd;
	for (int i = 0; i < this->size; i++)
		this->x[i] = a.x[i];
	return *this;
};

//Операции сравнения
template <typename T>
bool TVector<T>::operator==(const TVector& a) const
{
	if ((this->size != a.size) || (this->startInd != a.startInd))
		return false;
	bool flag = 1;
	for (int i = 0; i < this->size; i++)
		if(this->x[i] != a.x[i])
			flag = 0;
	return flag;
};
template <typename T>
bool TVector<T>::operator!=(const TVector& a) const
{
	return !(*this == a);
};

//Операции индексации
template <typename T>
T& TVector<T>::operator[](int i)
{
	if ((i < 0) || (i >= this->size))
		throw "Error: going beyond the dimension of the vector";
	return this->x[i];
};
template <typename T>
const T& TVector<T>::operator[](int i) const
{
	if ((i < 0) || (i >= this->size))
		throw "Error: going beyond the dimension of the vector";
	return this->x[i];
};