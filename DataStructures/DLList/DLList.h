#pragma once
template<class T>
struct DLListNode {
	T data;
	DLListNode<T>* next;
	DLListNode<T>* previous;
	DLListNode(const T&, DLListNode<T>* = nullptr , DLListNode<T>* = nullptr);
};
template<class T>
class DLListIterator;

template<class T>
class DLList {
	DLListNode<T>* first;
	DLListNode<T>* last;
	size_t currentSize;
	void copyList(const DLList<T>&);
	void deleteList();
public:
	DLList();
	DLList(const DLList<T>&);
	~DLList();
	DLList<T>& operator=(const DLList<T>&);
	void push_back(const T& data);
	void pop_back();
	void push_front(const T& data);
	void pop_front();
	T front() const;
	T back() const;
	bool empty() const;
	size_t size() const;
	DLListIterator<T> begin() const;
	DLListIterator<T> end() const;
};

template<class T>
class DLListIterator {
	DLListNode<T>* iteratedElement;
public:
	DLListIterator() = delete;
	DLListIterator(const DLListIterator<T>&) = default;
	DLListIterator& operator=(const DLListIterator<T>&) = default;
	~DLListIterator() = default;
	DLListIterator(DLListNode<T>* _listPosition);
	bool next();
	bool previous();
	T operator*() const;
	bool operator ++(int);
	bool operator -- (int);
	bool operator ==(const DLListIterator<T>&) const;
	bool operator !=(const DLListIterator<T>&) const;
};