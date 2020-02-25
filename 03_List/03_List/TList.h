#pragma once
#include <iostream>
#include "TNode.h"

using namespace std;

template <class TKey, class TData>
class TList
{
private:
	TNode<TKey, TData>* pFirst;
	TNode<TKey, TData>* pPrev;
	TNode<TKey, TData>* pCurr;
	TNode<TKey, TData>* pNext;
public:
	TList();
	TList(TNode<TKey, TData>* a);
	TList(const TList<TKey, TData>& a);
	~TList();

	bool IsEnded() const;
	void Next();
	void Reset();

	TNode<TKey, TData>* Search(TKey _key);
	void PushFront(TKey _key, TData* _data);
	void PushBack(TKey _key, TData* _data);
	void InsertBefore(TKey search_key, TKey ins_key, TData* _data);
	void InsertAfter(TKey search_key, TKey ins_key, TData* _data);
	void Remove(TKey _key);

	friend ostream& operator<<(ostream& out, TList<TKey, TData>& a)
	{
		TNode<TKey, TData>* curr = a.pCurr;
		TNode<TKey, TData>* prev = a.pPrev;
		TNode<TKey, TData>* next = a.pNext;
		a.Reset();
		while (!a.IsEnded())
		{
			out << a.pCurr->key << " - " << a.pCurr->Data[0] << endl;
			a.Next();
		}
		out << endl;
		a.pCurr = curr;
		a.pPrev = prev;
		a.pNext = next;
		return out;
	}
};

template <class TKey, class TData>
TList<TKey, TData>::TList()
{
	pFirst = NULL;
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
};
template <class TKey, class TData>
TList<TKey, TData>::TList(TNode<TKey, TData>* a)
{
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
	if (a == NULL)
		pFirst = NULL;
	else
	{
		pFirst = new TNode<TKey, TData>(*a);
		pCurr = pFirst;
		TNode<TKey, TData>* tmp = a->pNext;
		while (tmp != NULL)
		{
			pCurr->pNext = new TNode<TKey, TData>(*tmp);
			pCurr = pCurr->pNext;
			tmp = tmp->pNext;
		}
		Reset();
	}
};
template <class TKey, class TData>
TList<TKey, TData>::TList(const TList<TKey, TData>& a)
{
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
	if (a.pFirst == NULL)
		pFirst = NULL;
	else
	{
		pFirst = new TNode<TKey, TData>(*(a.pFirst));
		pCurr = pFirst;
		TNode<TKey, TData>* tmp = a.pFirst;
		tmp = tmp->pNext;
		while (tmp != NULL)
		{
			pCurr->pNext = new TNode<TKey, TData>(*tmp);
			pCurr = pCurr->pNext;
			tmp = tmp->pNext;
		}
		Reset();
	}
};
template <class TKey, class TData>
TList<TKey, TData>::~TList()
{
	Reset();
	while (!IsEnded())
	{
		Next();
		delete pPrev;
	}
	pFirst = NULL;
	pPrev = NULL;
	pCurr = NULL;
	pNext = NULL;
};

template <class TKey, class TData>
bool TList<TKey, TData>::IsEnded() const
{
	return (pCurr == NULL);
};
template <class TKey, class TData>
void TList<TKey, TData>::Next()
{
	if (IsEnded())
		throw "Error: list is empty";//throw
	pPrev = pCurr;
	pCurr = pNext;
	if (pNext != NULL)
		pNext = pNext->pNext;
	else pNext = NULL;
};
template <class TKey, class TData>
void TList<TKey, TData>::Reset()
{
	pPrev = NULL;
	pCurr = pFirst;
	if (pFirst != NULL)
		pNext = pCurr->pNext;
	else
		pNext = NULL;
};

template <class TKey, class TData>
TNode<TKey, TData>* TList<TKey, TData>::Search(TKey _key)
{
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	while ((!IsEnded()) && (pCurr->key != _key))
		Next();
	TNode<TKey, TData>* node;
	if (IsEnded())
		node = NULL;
	else node = pCurr;
	pCurr = curr;
	pPrev = prev;
	pNext = next;
	return node;
};
template <class TKey, class TData>
void TList<TKey, TData>::PushFront(TKey _key, TData* _data)
{
	if (pFirst == NULL)
	{
		pFirst = new TNode<TKey, TData>(_key, _data);
		pCurr = pFirst;
		return;
	};
	TNode<TKey, TData>* tmp = new TNode<TKey, TData>(_key, _data, pFirst);
	if (pCurr == pFirst)
		pPrev = tmp;
	pFirst = tmp;
};
template <class TKey, class TData>
void TList<TKey, TData>::PushBack(TKey _key, TData* _data)
{
	if (pFirst == NULL)
	{
		pFirst = new TNode<TKey, TData>(_key, _data);
		pCurr = pFirst;
		return;
	}
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* curr = pCurr;
	TNode<TKey, TData>* next = pNext;
	while (!IsEnded())
		Next();
	pCurr = new TNode<TKey, TData>(_key, _data);
	pPrev->pNext = pCurr;
	if (curr == pPrev)
		pNext = pCurr;
	else
		pNext = next;
	pPrev = prev;
	pCurr = curr;
	/*pNext = next; *//// if
};
template <class TKey, class TData>
void TList<TKey, TData>::InsertBefore(TKey search_key, TKey ins_key, TData* _data)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	if (pFirst->key == search_key)
	{
		PushFront(ins_key, _data);
		return;
	}
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	TNode<TKey, TData>* tmp = Search(search_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(ins_key, _data, pCurr);
	pPrev->pNext = node;
	if (curr == pPrev)
		pNext = node;
	else
		pNext = next;
	if (curr == pCurr)
		pPrev = node;
	else
		pPrev = prev;
	pCurr = curr;
};
template <class TKey, class TData>
void TList<TKey, TData>::InsertAfter(TKey search_key, TKey ins_key, TData* _data)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	TNode<TKey, TData>* curr = pCurr;
	Reset();
	TNode<TKey, TData>* tmp = Search(search_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	TNode<TKey, TData>* node = new TNode<TKey, TData>(ins_key, _data,pNext);
	pCurr->pNext = node;
	if (curr == pCurr)
		pNext = node;
	else
		pNext = next;
	if (curr == pNext)
		pPrev = node;
	else
		pPrev = prev;
	pCurr = curr;
};
template <class TKey, class TData>
void TList<TKey, TData>::Remove(TKey _key)
{
	if (pFirst == NULL)
		throw "Error: list is empty";
	if (pFirst->key == _key)
	{
		if (pCurr == pFirst)
		{
			pCurr = pNext;
			if (pNext != NULL)
				pNext = pNext->pNext;
			else
				pNext = NULL;
			delete pFirst;
			pFirst = pCurr;
			return;
		}
		if (pCurr == pFirst->pNext)
		{
			pPrev = NULL;
			delete pFirst;
			pFirst = pCurr;
			return;
		}
		delete pFirst;
		return;
	}
	TNode<TKey, TData>* curr = pCurr;
	TNode<TKey, TData>* prev = pPrev;
	TNode<TKey, TData>* next = pNext;
	Reset();
	TNode<TKey, TData>* tmp = Search(_key);
	if (tmp == NULL)
		throw "Error: there is no element with this key";
	while (pCurr != tmp)
		Next();
	pPrev->pNext = pNext;
	if ((curr == pCurr) || (curr == pNext))
	{
		pCurr = pNext;
		pNext = pCurr->pNext;
		delete tmp;
		return;
	}
	if (curr == pPrev)
	{
		pCurr = pPrev;
		pPrev = prev;
		pNext = pCurr->pNext;
		delete tmp;
		return;
	}
	pNext = next;
	pCurr = curr;
	delete tmp;
	return;
};