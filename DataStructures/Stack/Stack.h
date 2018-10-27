#pragma once

// FILO structure;
// User operates only with the element on the top os the stack;
// User cannot view, delete or change any other element, different from the one on the top.

template<class T>
struct StackNode {
	T data;
	StackNode<T>* next;
	StackNode(const T&, StackNode<T>* = nullptr);
};

template<class T>
class Stack {
	StackNode<T>* topOfStack;
	StackNode<T>* lastInStack;
	size_t currentSize;
	void copyStack(const Stack<T>&);
	void deleteStack();
public:
	Stack();
	Stack(const Stack<T>&);
	~Stack();
	Stack<T>& operator=(const Stack<T>&);
	void push(const T&);
	void pop();
	T top() const;
	bool empty() const;
	size_t size() const;
};