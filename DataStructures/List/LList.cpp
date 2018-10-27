#include<iostream>
#include<cassert>

#include "LList.h"

template<class T>
ListNode<T>::ListNode(const T& _data, ListNode<T>* _next) :data(_data), next(_next) {}

template<class T>
List<T>::List() {
	first = last = nullptr;
	currentSize = 0;
}

template<class T>
void List<T>::copyList(const List<T>& other) {
	first = last = nullptr;
	currentSize = 0;
	if (other.first) {
		ListNode<T>* otherIterate = other.first;
		while (otherIterate) {
			ListNode<T>* newElement = new ListNode<T>(otherIterate->data);
			if (!first) {
				last = first = newElement;
			}
			else {
				last->next = newElement;
				last = last->next;
			}
			currentSize++;
			otherIterate = otherIterate->next;
		}
	}
}

template<class T>
void List<T>::deleteList() {
	while (first) {
		ListNode<T>* toDelete = first;
		first = first->next;
		delete toDelete;
	}
	first = last =  nullptr;
}

template<class T>
List<T>::List(const List<T>& other) {
	copyList(other);
}

template<class T>
List<T>::~List() {
	deleteList();
}

template<class T>
List<T>& List<T>::operator = (const List<T>& other) {
	if (this != &other) {
		deleteList();
		copyList(other);
	}
	return *this;
}

template<class T>
void List<T>::push_back(const T& data) {
	ListNode<T>* toAdd = new ListNode<T>(data);
	if (!first) {
		last = first = toAdd;
	}
	else {
		last->next = toAdd;
		last = last->next;
	}
	currentSize++;
}

template<class T>
void List<T>::push_front(const T& data) {
	ListNode<T>* toAdd = new ListNode<T>(data, first);
	first = toAdd;
	if (!last) {
		last = first;
	}
	currentSize++;
}

template<class T>
void List<T>::pop_back() {
	if (first) {
		if (first == last) {
			delete first;
			first = last = nullptr;
			return;
		}
		ListNode<T>* tempIterate = first;
		while (tempIterate->next != last) {
			tempIterate = tempIterate->next;
		}
		delete last;
		last = tempIterate;
		last->next = nullptr;
		currentSize--;
	}
}

template<class T>
void List<T>::pop_front() {
	if (first) {
		if (first == last) {
			delete first;
			last = first = nullptr;
			return;
		}
		ListNode<T>* toDelete = first;
		first = first->next;
		delete toDelete;
		currentSize--;
	}
}

template<class T>
size_t List<T>::size() const {
	return currentSize;
}

template<class T>
bool List<T>::empty() const {
	return first == nullptr;
}

template<class T>
T List<T>::front() const {
	assert(first);
	return first->data;
}

template<class T>
T List<T>::back() const {
	assert(last);
	return last->data;
}


template<class T>
ListIterator<T>::ListIterator(ListNode<T>* _listPosition) : iteratedElement(_listPosition) {}\

template<class T>
bool ListIterator<T>::next() {
	if (iteratedElement) {
		iteratedElement = iteratedElement->next;
	}
	return iteratedElement != nullptr;
}

template<class T>
T ListIterator<T>::operator*() const {
	assert(iteratedElement);
	if (iteratedElement) {
		return iteratedElement->data;
	}
}

template<class T>
bool ListIterator<T>::operator==(const ListIterator<T>& other) const {
	return iteratedElement == other.iteratedElement;
}

template<class T>
bool ListIterator<T>::operator != (const ListIterator<T>& other) const {
	return iteratedElement != other.iteratedElement;
}
template<class T>
bool ListIterator<T>::operator++(int elem) {
	return next();
}

template<class T>
ListIterator<T> List<T>::begin() const {
	return ListIterator<T>(first);
}

template<class T>
ListIterator<T> List<T>::end() const {
	return ListIterator<T>(nullptr);
}