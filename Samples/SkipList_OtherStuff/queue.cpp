#include<iostream>

template<class T>
class Iterator {
public:
	virtual T operator* () const = 0;
	virtual void operator ++ (int) = 0;
};

template<class T>
struct QueueNode {
	T data;
	QueueNode<T>* next;
	QueueNode(const T& _data, QueueNode<T>* _next = nullptr) {

	}
};

template<class T>
class Queue {
	QueueNode<T>* head;
	QueueNode<T>* tail;
	size_t crrsize;
	void copy(const Queue<T>& other) {

	}
	void erase() {

	}
public:
	Queue() {

	}
	Queue(const Queue<T>& other) {

	}
	Queue<T>& operator=(const Queue<T>& other) {

	}

	~Queue() {

	}

	void push(const T& elem) {
		if (!head) {
			//To do
		}
		else {
			tail->next = new QueueNode<T>(data);
			tail = tail->next;
		}
	}

	void pop() {
		if (head) {
			QueueNode<T>* save = head;
			head = head->next;
			delete save;
			crrsize--;
		}
	}
};


//рнбю е ясссоеп мемсфмн х цпеьмн!!!!!!!
//template<class T>
//class QueueIterator: public Iterator<T> {
//	Queue<T>* queueToIterate;
//	bool end;
//public:
//	QueueIterator() = delete;
//	QueueIterator(const Queue<T>* _queue, bool _end):queueToIterate(_queue), end(_end) {
//	}
//	void operator++(int) {
//		queueToIterate->pop();
//	}
//	bool operator != (QueueIterator<T> other) {
//		if (queueToIterate == other.queueToIterate && queueToIterate->size() == 0) {
//
//		}
//	}
//	bool end() const {
//
//	}
//};