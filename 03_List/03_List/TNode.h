#pragma once
template <typename TKey, typename TData>
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

template <typename TKey, typename TData>
TNode<TKey, TData>::TNode()
{
	Data = NULL;
	pNext = NULL;
}
template <typename TKey, typename TData>
TNode<TKey, TData>::TNode(TKey _key, TData* _data, TNode<TKey, TData>* _pNext)
{
	key = _key;
	Data = new TData(*_data);
	pNext = _pNext;
}
template <typename TKey, typename TData>
TNode<TKey, TData>::TNode(const TNode<TKey, TData>& a)
{
	key = a.key;
	Data = new TData(*a.Data);
	pNext = a.pNext;
};
template <typename TKey, typename TData>
TNode<TKey, TData>::~TNode()
{
	key = 0;
	if (Data != NULL)
	delete Data;
	Data = NULL; // delete Data
	pNext = NULL;
}
