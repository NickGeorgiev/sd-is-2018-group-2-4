#include<iostream>
#include<cassert>

#include "Stack.h"

template<class T>
StackNode<T>::StackNode(const T& _data, StackNode<T>* _next) :data(_data), next(_next) {}

template<class T>
Stack<T>::Stack() {
	topOfStack = lastInStack = nullptr;
	currentSize = 0;
}

template<class T>
void Stack<T>::copyStack(const Stack<T>& other) {
	topOfStack = lastInStack = nullptr;
	currentSize = 0;
	if (other.topOfStack) {
		StackNode<T>* otherIterate = other.topOfStack;
		while (otherIterate) {
			StackNode<T>* newElement = new StackNode<T>(otherIterate->data);
			if (!topOfStack) {
				topOfStack = lastInStack = newElement;
			}
			else {
				lastInStack->next = newElement;
				lastInStack = lastInStack->next;
			}
			currentSize++;
			otherIterate = otherIterate->next;
		}
	}
}

template<class T>
void Stack<T>::deleteStack() {
	while (topOfStack) {
		StackNode<T>* toDelete = topOfStack;
		topOfStack = topOfStack->next;
		delete toDelete;
	}
	topOfStack = lastInStack = nullptr;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) {
	copyStack(other);
}

template<class T>
Stack<T>::~Stack() {
	deleteStack();
}

template<class T>
Stack<T>& Stack<T>::operator = (const Stack<T>& other) {
	if (this != &other) {
		deleteStack();
		copyStack(other);
	}
	return *this;
}

template<class T>
void Stack<T>::push(const T& data) {
	StackNode<T>* toAdd = new StackNode<T>(data, topOfStack);
	topOfStack = toAdd;
	if (currentSize == 0) {
		lastInStack = topOfStack;
	}
	currentSize++;
}

template<class T>
void Stack<T>::pop() {
	if (topOfStack) {
		if (topOfStack == lastInStack) {
			delete topOfStack;
			topOfStack = lastInStack = nullptr;
			return;
		}
		StackNode<T>* toDelete = topOfStack;
		topOfStack = topOfStack->next;
		delete toDelete;
		currentSize--;
	}
}

template<class T>
T Stack<T>::top() const {
	assert(topOfStack);
	return topOfStack->data;
}

template<class T>
size_t Stack<T>::size() const {
	return currentSize;
}

template<class T>
bool Stack<T>::empty() const {
	return topOfStack == nullptr;
}
