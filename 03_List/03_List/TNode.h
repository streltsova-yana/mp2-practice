#pragma once
template <class TKey, class TData>
struct TNode
{
	TKey key;
	TData* Data;
	TNode<TKey, TData>* pNext;

	TNode();
	TNode(TKey _key, TData* _data, TNode<TKey, TData>* _pNext = NULL);
	TNode(const TNode<TKey, TData>& a);
	~TNode();
};

template <class TKey, class TData>
TNode<TKey, TData>::TNode()
{
	Data = new TData;
	pNext = NULL;
}
template <class TKey, class TData>
TNode<TKey, TData>::TNode(TKey _key, TData* _data, TNode<TKey, TData>* _pNext)
{
	key = _key;
	Data = new TData(*_data);
	/*Data = new TData;*/
	Data = _data;
	pNext = _pNext;
}
template <class TKey, class TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& a)
{
	key = a.key;
	Data = new TData;
	Data = a.Data;
	pNext = a.pNext;
};
template <class TKey, class TData>
TNode<TKey, TData>::~TNode()
{
	key = 0;
	delete Data;
	Data = NULL; // delete Data
	pNext = NULL;
}