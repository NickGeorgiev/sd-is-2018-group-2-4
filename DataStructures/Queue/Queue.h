#pragma once

// FIFO structure;
// Element is added at the end (tail);
// Element is removed from the start (head);
// Working with any element different from the head and tail is not allowed.

template<class T>
struct QueueNode {
	T data;
	QueueNode<T>* next;
	QueueNode(const T&, QueueNode<T>* = nullptr);
};

template<class T>
class Queue {
	QueueNode<T>* head;
	QueueNode<T>* tail;
	size_t currentSize;
	void copyQueue(const Queue<T>&);
	void deleteQueue();
public:
	Queue();
	Queue(const Queue<T>&);
	~Queue();
	Queue<T>& operator=(const Queue<T>&);
	void push(const T& data);
	void pop();
	T front() const;
	T back() const;
	bool empty() const;
	size_t size() const;
};
