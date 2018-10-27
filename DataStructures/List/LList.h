#pragma once
template<class T>
struct ListNode {
	T data;
	ListNode<T>* next;
	ListNode(const T&, ListNode<T>* = nullptr);
};
template<class T>
class ListIterator;

template<class T>
class List {
	ListNode<T>* first;
	ListNode<T>* last;
	size_t currentSize;
	void copyList(const List<T>&);
	void deleteList();
public:
	List();
	List(const List<T>&);
	~List();
	List<T>& operator=(const List<T>&);
	void push_back(const T& data);
	void pop_back();
	void push_front(const T& data);
	void pop_front();
	T front() const;
	T back() const;
	bool empty() const;
	size_t size() const;
	ListIterator<T> begin() const;
	ListIterator<T> end() const;
};

template<class T>
class ListIterator {
	ListNode<T>* iteratedElement;
public:
	ListIterator() = delete;
	ListIterator(const ListIterator<T>&) = default;
	ListIterator& operator=(const ListIterator<T>&) = default;
	~ListIterator() = default;
	ListIterator(ListNode<T>* _listPosition);
	bool next();
	T operator*() const;
	bool operator ++(int);
	bool operator ==(const ListIterator<T>&) const;
	bool operator !=(const ListIterator<T>&) const;
};