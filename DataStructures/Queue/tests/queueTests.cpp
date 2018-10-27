#include<iostream>
#include<cassert>
#include "Queue.cpp"
bool queueTests(bool debug = false) {
	Queue<int> testQueue;
	assert(testQueue.size() == 0);
	assert(testQueue.empty());
	if (debug) std::cout << "Queue is empty!" << std::endl;

	testQueue.push(12);
	assert(testQueue.size() == 1);
	assert(!testQueue.empty());
	assert(testQueue.front() == 12);
	assert(testQueue.back() == 12);
	if (debug) std::cout << "Successfully pushed element in the queue!" << std::endl;

	testQueue.push(24);
	assert(testQueue.size() == 2);
	assert(!testQueue.empty());
	assert(testQueue.front() == 12);
	assert(testQueue.back() == 24);
	if (debug) std::cout << "Successfully pushed another element!" << std::endl;

	testQueue.push(0);
	assert(testQueue.size() == 3);
	assert(!testQueue.empty());
	assert(testQueue.front() == 12);
	assert(testQueue.back() == 0);
	if (debug) std::cout << "Successfully pushed one more!" << std::endl;

	testQueue.pop();
	assert(testQueue.size() == 2);
	assert(!testQueue.empty());
	assert(testQueue.front() == 24);
	assert(testQueue.back() == 0);
	if (debug) std::cout << "Successfully popped element from the queue!" << std::endl;

	testQueue.pop();
	assert(testQueue.size() == 1);
	assert(!testQueue.empty());
	assert(testQueue.front() == 0);
	assert(testQueue.back() == 0);
	if (debug) std::cout << "Successfully popped another element!" << std::endl;

	Queue<int> testCopyQueue(testQueue);
	assert(testCopyQueue.size() == 1);
	assert(!testCopyQueue.empty());
	assert(testCopyQueue.front() == 0);
	assert(testCopyQueue.back() == 0);
	if (debug) std::cout << "Successfully copied queue!" << std::endl;

	Queue<int> testAssignedQueue;
	testAssignedQueue = testQueue;
	assert(testAssignedQueue.size() == 1);
	assert(!testAssignedQueue.empty());
	assert(testAssignedQueue.front() == 0);
	assert(testAssignedQueue.back() == 0);
	if (debug) std::cout << "Successfully assigned queue!" << std::endl;
	return true;
}

int main () {
	std::cout << queueTests();
	return 0;
}