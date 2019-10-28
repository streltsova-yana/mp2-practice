#pragma once
#include "TVector.h"

template <typename T>
class TMatrix : public TVector<TVector<T> >
{
public:
	TMatrix(int _size = 10);
	TMatrix(const TMatrix& a);
	TMatrix(const TVector<TVector<T> >& a);
	~TMatrix();

	//Сложение, вычитание, умножение на константу
	TMatrix operator+(T elem);
	TMatrix& operator+=(T elem);
	TMatrix operator-(T elem);
	TMatrix& operator-=(T elem);
	TMatrix operator*(T elem);
	TMatrix& operator*=(T elem);

	//Сложение, вычитание, умножение с матрицей
	TMatrix operator+(const TMatrix& a);
	TMatrix& operator+=(const TMatrix& a);
	TMatrix operator-(const TMatrix& a);
	TMatrix& operator-=(const TMatrix& a);
	TMatrix operator*(const TMatrix& a);
	TVector<T> operator*(const TVector<T>& a);

	TMatrix& operator=(const TMatrix& a); //Операция присваивания

	//Операции сравнения
	bool operator==(const TMatrix& a) const;
	bool operator!=(const TMatrix& a) const;

	//Операции ввода, вывода
	friend istream& operator>>(istream& in, TMatrix& a)
	{
		if (a.size == 0)
			throw "Error: empty matrix";
		for (int i = 0; i < a.size; i++)
			in >> a.x[i];
		return in;
	};
	friend ostream& operator<<(ostream& out, const TMatrix& a)
	{
		if (a.size == 0)
			throw "Error: empty matrix";
		for (int i = 0; i < a.size; i++)
			out << endl << a.x[i] << " ";
		return out;
	};
};

template <typename T>
TMatrix<T>::TMatrix(int _size) : TVector<TVector<T> >(_size)
{
	this->size = _size;
	for (int i = 0; i < this->size; i++)
		this->x[i] = TVector<T>(this->size - i, i);
};
template <typename T>
TMatrix<T>::TMatrix(const TMatrix<T>& a) : TVector<TVector<T> >(a){};
template <typename T>
TMatrix<T>::TMatrix(const TVector<TVector<T> >& a) : TVector<TVector<T> >(a){};
template <typename T>
TMatrix<T>::~TMatrix(){};

//Сложение, вычитание, умножение на константу
template <typename T>
TMatrix<T> TMatrix<T>::operator+(T elem)
{
	TMatrix<T> tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] + elem;
	return tmp;
};
template <typename T>
TMatrix<T>& TMatrix<T>::operator+=(T elem)
{
	for (int i = 0; i < this->size; i++)
		this->x[i] += elem;
	return *this;
};
template <typename T>
TMatrix<T> TMatrix<T>::operator-(T elem)
{
	TMatrix<T> tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] - elem;
	return tmp;
};
template <typename T>
TMatrix<T>& TMatrix<T>::operator-=(T elem)
{
	for (int i = 0; i < this->size; i++)
		this->x[i] -= elem;
	return *this;
};
template <typename T>
TMatrix<T> TMatrix<T>::operator*(T elem)
{
	TMatrix<T> tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] * elem;
	return tmp;
};
template <typename T>
TMatrix<T>& TMatrix<T>::operator*=(T elem)
{
	for (int i = 0; i < this->size; i++)
		this->x[i] *= elem;
	return *this;
};

//Сложение, вычитание, умножение с матрицей
template <typename T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of matrix";
	TMatrix tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] + a.x[i];
	return tmp;
};
template <typename T>
TMatrix<T>& TMatrix<T>::operator+=(const TMatrix<T>& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of matrix";
	for (int i = 0; i < this->size; i++)
		this->x[i] += a.x[i];
	return *this;
};
template <typename T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of matrix";
	TMatrix tmp(this->size);
	for (int i = 0; i < this->size; i++)
		tmp.x[i] = this->x[i] - a.x[i];
	return tmp;
};
template <typename T>
TMatrix<T>& TMatrix<T>::operator-=(const TMatrix<T>& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of matrix";
	for (int i = 0; i < this->size; i++)
		this->x[i] -= a.x[i];
	return *this;
};
template <typename T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& a)
{
	if (this->size != a.size)
		throw "Error: different dimension of matrix";
	TMatrix tmp(*this);
	for (int i = 0; i < this->size; i++)
		for (int j = this->x[i].GetInd(); j < this->size; j++)
		{
			tmp.x[i][j - i] = 0.0;
			for (int k = i; k <= j; k++)
				tmp.x[i][j - i] += this->x[i][k - i] * a.x[k][j - k];
		}
	return tmp;
};
template <typename T>
TVector<T> TMatrix<T>::operator*(const TVector<T>& a)
{
	if (this->size != a.GetSize())
		throw "Error: different dimension of matrix";
	TVector<T> tmp(this->size);
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = 0;
		for (int j = 0; j < this->x[i].GetSize(); j++)
			tmp[i] += this->x[i][j] * a[i + j];
	}
	return tmp;
};

//Операция присваивания
template <typename T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix& a)
{
	if (*this == a)
	{
		return *this;
	}
	if (this->size != a.size)
	{
		delete[] this->x;
		this->size = a.size;
		this->x = new TVector<T>[this->size]; 
	}
	for (int i = 0; i < this->size; i++)
		this->x[i] = a.x[i];
};

//Операции сравнения
template <typename T>
bool TMatrix<T>::operator==(const TMatrix& a) const
{
	if (this->size != a.size)
		return false;
	bool flag = 1;
	for (int i = 0; i < this->size; i++)
		if (this->x[i] != a.x[i])
			flag = 0;
	return flag;
};
template <typename T>
bool TMatrix<T>::operator!=(const TMatrix& a) const
{
	return !(*this == a);
};