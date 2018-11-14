#include <iostream>
#include <string>

template <class T>
struct DLinkedListNode
{
    T data;
    DLinkedListNode<T> *previous;
    DLinkedListNode<T> *next;
    DLinkedListNode(const T &_data, DLinkedListNode<T> *_next = nullptr, DLinkedListNode<T> *_previous = nullptr) : data(_data), next(_next), previous(_previous) {}
};

template <class T>
struct LinkedListNode
{
    T data;
    LinkedListNode<T> *previous;
    LinkedListNode<T> *next;
    LinkedListNode(const T &_data, LinkedListNode<T> *_next = nullptr) : data(_data), next(_next) {}
};

//helper functions
template <class T>
void printList(DLinkedListNode<T> *first)
{
    while (first)
    {
        std::cout << first->data << " ";
        first = first->next;
    }
}

template <class T>
void printList(LinkedListNode<T> *first)
{
    while (first)
    {
        std::cout << first->data << " ";
        first = first->next;
    }
}

template <class T>
LinkedListNode<T> *createList(unsigned int n)
{
    LinkedListNode<T> *newList = new LinkedListNode<T>(0);
    LinkedListNode<T> *currentElement = newList;
    for (int i = 1; i <= n; i++)
    {
        currentElement->next = new LinkedListNode<T>(i, nullptr);
        currentElement = currentElement->next;
    }
    return newList;
}

template <class T>
DLinkedListNode<T> *createDLList(unsigned int n)
{
    DLinkedListNode<T> *newList = new DLinkedListNode<T>(0);
    DLinkedListNode<T> *currentElement = newList;
    for (int i = 1; i <= n; i++)
    {
        currentElement->next = new DLinkedListNode<T>(i, nullptr, currentElement);
        currentElement = currentElement->next;
    }
    return newList;
}

template <class T>
void reverseList(DLinkedListNode<T> *&first, unsigned int n)
{
    if (!first)
    {
        return;
    }
    DLinkedListNode<T> *currentElement = first;
    DLinkedListNode<T> *lastReversed = first;
    while (n > 0 && currentElement)
    {
        std::swap(currentElement->next, currentElement->previous);
        lastReversed = currentElement;
        currentElement = currentElement->previous;
        n--;
    }
    first->next = currentElement;
    if (currentElement)
    {
        currentElement->previous = first;
    }
    lastReversed->previous = nullptr;
    first = lastReversed;
}

template <class T>
void makeProgression(DLinkedListNode<T> *&first)
{
    if (!first || !first->next)
    {
        return;
    }
    int progStep = first->next->data - first->data;
    DLinkedListNode<T> *currentElement = first->next->next;
    while (currentElement)
    {
        if (currentElement->data - currentElement->previous->data != progStep)
        {
            DLinkedListNode<T> *toDelete = currentElement;
            currentElement->previous->next = currentElement->next;
            if (currentElement->next)
            {
                currentElement->next->previous = currentElement->previous;
            }
            currentElement = currentElement->next;
            delete toDelete;
        }
        else
        {
            currentElement = currentElement->next;
        }
    }
}

void DLinkedListTests()
{
    DLinkedListNode<int> *list = createDLList<int>(5);
    printList(list);
    reverseList(list, 3);
    std::cout << std::endl;
    printList(list);
    std::cout << std::endl;
    makeProgression(list);
    printList(list);
    std::cout << std::endl;
}

void LinkedListTests()
{
    LinkedListNode<int> *list = createList<int>(5);
    printList(list);
    std::cout << std::endl;
}

int main()
{
    DLinkedListTests();
    LinkedListTests();
    return 0;
}