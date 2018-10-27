#include<iostream>
#include<cassert>
template<class T>
struct Node {
	T data;
	Node<T>* next;
	Node(const T& _data, Node<T>* _next = nullptr) : data(_data), next(_next) {}
};

template<typename T>
class Stack {
	Node<T>* topOfStack;
	int size;
public:
	Stack() :topOfStack(nullptr), size(0) {}

	void push(const T& newData) {
		if (!topOfStack) {
			this->topOfStack = new Node<T>(newData);
		}
		else {
			Node<T>* newNode = new Node<T>(newData, topOfStack);
			this->topOfStack = newNode;
		}
		this->size++;
	}

	bool isEmpty() const {
		return this->topOfStack == nullptr;
	}

	void pop() {
		if (!isEmpty()) {
			Node<T>* currentPointer = topOfStack;
			this->topOfStack = topOfStack->next;
			delete currentPointer;
			this->size--;
		}
	}

	T top() const {
		assert(!isEmpty());
		return topOfStack->data;
	}

	int count() const { return this->size; }

};




//int main() {
//	Stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.pop();
//	int res = s.top();
//	std::cout << res << '\n';
//	std::cout << s.count();
//}