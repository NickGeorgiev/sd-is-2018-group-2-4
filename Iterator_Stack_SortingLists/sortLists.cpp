#include<iostream>

template<typename T>
struct Box {
	T data;
	Box<T>* next;
	Box(const T& _data, Box<T>* _next = nullptr) : data(_data), next(_next) {}
};

template<typename T>
Box<T>* findMin(Box<T>* start) {
	Box<T>* currentMin = start;
	while (start) {
		if (start->data < currentMin->data) {
			currentMin = start;
		}
		start = start->next;
	}
	return currentMin;
}

template<typename T>
void sortList(Box<T>* start) {
	while (start) {
		Box<T>* currentMin = findMin(start);
		if (start->data > currentMin->data) {
			T swapHelper = start->data;
			start->data = currentMin->data;
			currentMin->data = swapHelper;
		}
		start = start->next;
	}
}

template<typename T>
void print(Box<T>* start) {
	while (start) {
		std::cout << start->data<<' ';
		start = start->next;
	}
}


//int main() {
//	Box<int>* a3 = new Box<int>(12);
//	Box<int>* a2 = new Box<int>(3,a3);
//	Box<int>* a1 = new Box<int>(15,a2);
//	Box<int>* min = findMin(a1);
//	//print(a1);
//	sortList(a1);
//	print(a1);
//}