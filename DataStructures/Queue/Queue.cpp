#include<iostream>
#include<cassert>

#include "Queue.h"

template<class T>
QueueNode<T>::QueueNode(const T& _data, QueueNode<T>* _next) :data(_data), next(_next) {}

template<class T>
Queue<T>::Queue() {
	head = tail = nullptr;
	currentSize = 0;
}

template<class T>
void Queue<T>::copyQueue(const Queue<T>& other) {
	head = tail = nullptr;
	currentSize = 0;
	if (other.head) {
		QueueNode<T>* otherIterate = other.head;
		while (otherIterate) {
			QueueNode<T>* newElement = new QueueNode<T>(otherIterate->data);
			if (!head) {
				tail = head = newElement;
			}
			else {
				tail->next = newElement;
				tail = tail->next;
			}
			currentSize++;
			otherIterate = otherIterate->next;
		}
	}
}

template<class T>
void Queue<T>::deleteQueue() {
	while (head) {
		QueueNode<T>* toDelete = head;
		head = head->next;
		delete toDelete;
	}
	head = tail = nullptr;
}

template<class T>
Queue<T>::Queue(const Queue<T>& other) {
	copyQueue(other);
}

template<class T>
Queue<T>::~Queue() {
	deleteQueue();
}

template<class T>
Queue<T>& Queue<T>::operator = (const Queue<T>& other) {
	if (this != &other) {
		deleteQueue();
		copyQueue(other);
	}
	return *this;
}

template<class T>
void Queue<T>::push(const T& data) {
	QueueNode<T>* toAdd = new QueueNode<T>(data);
	if (!head) {
		tail = head = toAdd;
	}
	else {
		tail->next = toAdd;
		tail = tail->next;
	}
	currentSize++;
}


template<class T>
void Queue<T>::pop() {
	if (head) {
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		QueueNode<T>* toDelete = head;
		head = head->next;
		delete toDelete;
		currentSize--;
	}
}


template<class T>
size_t Queue<T>::size() const {
	return currentSize;
}

template<class T>
bool Queue<T>::empty() const {
	return head == nullptr;
}

template<class T>
T Queue<T>::front() const {
	assert(head);
	return head->data;
}

template<class T>
T Queue<T>::back() const {
	assert(tail);
	return tail->data;
}