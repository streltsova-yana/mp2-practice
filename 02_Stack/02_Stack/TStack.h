#pragma once
template <class T>
class TStack
{
private:
	int size;
	int top;
	T* x;
public:
	TStack(int _size);
	TStack(const TStack& a);
	~TStack();
	void Push(T elem);
	T Top() const;
	void Pop();
	bool IsEmpty() const;
	bool IsFull() const;
};

template <class T>
TStack<T>::TStack(int _size)
{
	size = _size;
	top = 0;
	x = new T[size];
}
template <class T>
TStack<T>::TStack(const TStack& a)
{
	size = a.size;
	top = a.top;
	x = new T[size];
	for (int i = 0; i < size; i++)
		x[i] = a.x[i];
}
template <class T>
TStack<T>::~TStack()
{
	delete[] x;
	size = 0;
	top = 0;
}
template <class T>
void TStack<T>::Push(T elem)
{
	if(IsFull())
		throw "Error: Stack is full";
	x[top++] = elem;
}
template <class T>
T TStack<T>::Top() const
{
	if (IsEmpty())
		throw "Error: Stack is empty";
	return x[top - 1];
}
template <class T>
void TStack<T>::Pop()
{
	if (IsEmpty())
		throw "Error: Stack is empty";
	top--;
}
template <class T>
bool TStack<T>::IsEmpty() const
{
	return (top == 0);
}
template <class T>
bool TStack<T>::IsFull() const
{
	return (top == size);
}