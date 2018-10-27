#pragma once
#include<iostream>
#include<cassert>
#include<vector>
template <class T>
struct dllnode
{
	T data;
	dllnode *next, *prev;
	dllnode(const T&, dllnode*, dllnode*);
};

template<class T>
class Iterator{
public:
	virtual T operator* () const = 0;
	virtual void operator ++ (int) = 0;
	virtual void operator -- (int) = 0;
};

template <class T>
class ListIterator:public Iterator<T> {
	dllnode<T>* list;
	bool end;
public:
	ListIterator() = delete;
	ListIterator(dllnode<T>* start, bool _end=false) : end(_end) {
		if (end) {
			list = nullptr;
		}
		else {
			list = start;
		}
	}

	void next() {
		if (list) {
			list = list->next;
		}
	}
	void operator ++(int size) override {
		next();
	}
	bool operator !=(const ListIterator& other) {
		return list != other.list;
	}
	T operator *() const  {
		return list->data;
	}
	void operator -- (int) override {
		if (list) {
		list = list->prev;
		}
	}

};

template <class T>
class DLList
{
public:
	DLList();
	DLList(const DLList<T> &other);
	DLList& operator= (const DLList<T> &other);

	T& operator [] (size_t index);

	void push(const T&);
	T& top();
	void pop();

	size_t size();

	~DLList();
	void removeDuplicates();
	void removeNode(dllnode<T>* node);
	void pushAtIndex(T data, size_t index);
	T lastNthToLast(const size_t& n);

	void sort();
	bool isSorted()const;
	void reverse();

	void merge(const DLList<T>*& _list)
	{
		if (!(_list->isSorted()) || first == nullptr)return;
		else
		{

		}
	}

	void print()const;

	ListIterator<T> begin();
	ListIterator<T> end();

private:
	dllnode<T> *first;
	size_t crrsize;

	//----- ITERATION OPTIMIZATION -----
	dllnode <T> *lastFound;
	size_t lastFoundIndex;
	//----------------------------------

	void copy(const DLList<T> &other);
	void erase();
};

template <class T>
dllnode<T>::dllnode(const T &_data, dllnode *_next, dllnode *_prev)
	:data(_data), next(_next), prev(_prev)
{}

template <class T>
DLList<T>::DLList()
{
	first = nullptr;
	crrsize = 0;
	lastFoundIndex = -1;
	lastFound = nullptr;
}

template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
	copy(other);
}

template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
	if (other.first == nullptr)
	{
		first = nullptr;
		return;
	}
	first = new dllnode<T>(other.first->data, nullptr, nullptr);

	dllnode<T> *lastcreated = first;
	dllnode<T> *nexttocopy = other.first->next;

	while (nexttocopy != nullptr)
	{
		lastcreated->next = new dllnode<T>(nexttocopy->data, nullptr, lastcreated);
		lastcreated = lastcreated->next;
		nexttocopy = nexttocopy->next;
	}

	crrsize = other.crrsize;

	/*RESTART ITERATION*/
	lastFoundIndex = -1;
	lastFound = nullptr;

}

template <class T>
void DLList<T>::erase()
{
	dllnode<T> *next;
	while (first != nullptr)
	{
		next = first->next;
		delete first;
		first = next;
	}

	crrsize = 0;
	/*RESTART ITERATION*/
	lastFoundIndex = -1;
	lastFound = nullptr;

}


template <class T>
DLList<T>& DLList<T>::operator= (const DLList<T> &other)
{
	if (this != &other)
	{
		erase();
		copy(other);
		/*RESTART ITERATION*/
		lastFoundIndex = -1;
		lastFound = nullptr;
	}
	return *this;
}

template <class T>
T& DLList<T>::operator [] (size_t index)
{
	assert(first != nullptr);
	//ñàìî çà äà ñå êîìïèëèðà

	if (lastFoundIndex != -1 &&
		lastFoundIndex == index - 1)
	{
		assert(lastFound != nullptr);
		lastFound = lastFound->next;
	}
	else if (lastFoundIndex != -1 &&
		lastFoundIndex == index + 1)
	{
		assert(lastFound != nullptr);
		lastFound = lastFound->prev;
	}
	else {
		lastFound = first;
		while (lastFound != nullptr && index > 0)
		{
			lastFound = lastFound->next;
			index--;
		}
	}

	//ÈÇÊËÞ×ÅÍÀ ÎÏÒÈÌÈÇÈÀÖÈß!
	//lastFoundIndex = index;
	assert(lastFound != nullptr);
	return lastFound->data;
}

template <class T>
void DLList<T>::push(const T &data)
{
	//first ñî÷è íåùî

	first = new dllnode<T>(data, first, nullptr);
	if (first->next != nullptr)
	{
		first->next->prev = first;
	}

	crrsize++;
	/*RESTART ITERATION*/
	lastFoundIndex = -1;
	lastFound = nullptr;

}

template <class T>
T& DLList<T>::top()
{
	assert(first != nullptr);
	//ñàìî çà äà ñå êîìïèëèðà
	return first->data;
}

template <class T>
void DLList<T>::pop()
{
	assert(first != nullptr);
	dllnode<T> *next = first->next;
	delete first;
	first = next;
	crrsize--;
	/*RESTART ITERATION*/
	lastFoundIndex = -1;
	lastFound = nullptr;

}
template <class T>
DLList<T>::~DLList()
{
	erase();
}

template <class T>
size_t DLList<T>::size()
{
	return crrsize;
}

template<class T>
void DLList<T>::removeDuplicates()
{
	if (this->first == nullptr)
	{
		return;
	}
	dllnode<T>* crrNode = first;
	dllnode<T>* nextNode;
	while (crrNode != nullptr)
	{

		nextNode = crrNode->next;
		while (nextNode != nullptr)
		{
			if (nextNode->data == crrNode->data)
			{
				dllnode<T>* save = nextNode;
				nextNode = nextNode->next;
				crrNode->next = nextNode;
				nextNode->prev = crrNode;
				delete save;
				crrsize--;
			}
			nextNode = nextNode->next;
		}
		crrNode = crrNode->next;
	}
}

template<class T>
void DLList<T>::removeNode(dllnode<T>* crr)
{
	dllnode<T>* temp = crr->next;
	crr->data = temp->data;
	crr->next = temp->next;
	delete temp;
}

template<class T>
void DLList<T>::print()const
{
	if (first == nullptr)return;
	dllnode<T>* crr = first;
	std::cout << '[';
	while (crr != nullptr)
	{
		std::cout << crr->data << " ";
		crr = crr->next;
	}
	std::cout << "]";

}

template<class T>
void DLList<T>::pushAtIndex(T _data, size_t index)
{
	if (index >= this->size())return;

	dllnode<T>* crr = first;
	for (size_t i = 0; i < index - 1; i++)
	{
		crr = crr->next;
	}
	dllnode<T>* save = crr->next;
	dllnode<T>* toAdd = new dllnode<T>(_data, save, crr);
	crr->next = toAdd;
	save->prev = toAdd;
	crrsize++;
	//this->print();
}

template<class T>
T DLList<T>::lastNthToLast(const size_t& n)
{
	if (n > this->size())return NULL;
	if (this->first == nullptr)return NULL;
	dllnode<T>* fst = first;
	dllnode<T>* snd = first;
	size_t count = 0;
	while (fst != nullptr)
	{
		if (count >= n)
		{
			snd = snd->next;
		}
		fst = fst->next;
		count++;
	}
	return snd->data;
}

template<class T>
bool DLList<T>::isSorted()const
{
	dllnode<T>* tmp = first;
	if (first == nullptr) return false;//throw std::invalid_argument("first was a nullpointer");
	while (tmp != nullptr)
	{
		if (tmp->data > tmp->next->data)return false;
		tmp = tmp->next;
	}
	return true;
}

template<class T>
void DLList<T>::reverse()
{
	// Initialize current, previous and 
	// next pointers 
	dllnode<T> *current = first;
	dllnode<T> *prev = nullptr, *next = nullptr;


	while (current != nullptr)
	{
		// Store next 
		next = current->next;

		// Reverse current node's pointer 
		current->next = prev;

		// Move pointers one position ahead. 
		prev = current;
		current = next;
	}
	first = prev;
}


template<class T>
void DLList<T>::sort()
{
	if (first == nullptr)return;
	dllnode<T>* crrNode = first;
	dllnode<T>* nextNode;
	while (crrNode != nullptr)
	{
		nextNode = crrNode->next;
		while (nextNode != nullptr)
		{
			if (nextNode->data<crrNode->data)
			{
				T save = crrNode->data;
				crrNode->data = nextNode->data;
				nextNode->data = save;
			}
			nextNode = nextNode->next;
		}
		crrNode = crrNode->next;
	}
}


template<class T>
ListIterator<T> DLList<T>::begin() {
	return ListIterator<T>(this->first);
}

template<class T>
ListIterator<T> DLList<T>::end() {
	return ListIterator<T>(this->first, true);
}

//
//int main() {
//	DLList<int> list;
//	list.push(1);
//	list.push(2);
//	list.push(31);
//	list.push(5);
//	list.push(61);
//	DLList<int> list1;
//	list1.push(22);
//	list1.push(33);
//	list1.push(44);
//	list1.push(55);
//	list1.push(66);
//	std::vector<DLList<int>> mixedArray;
//	mixedArray.push_back(list);
//	mixedArray.push_back(list1);
//	for (DLList<int> element : mixedArray) { // for(int i=0; i < mixedArray.size(); i++) for(auto elem : mixedArray)
//		
//		for (ListIterator<int> it = element.begin(); it != element.end(); it++) { // can be done with auto
//			std::cout << *it<< ' ';
//		}
//			std::cout << std::endl;
//	}
//
//	return 0;
//}