#include<iostream>
#include<cassert>
#include "DlList.cpp"

bool dllistTests(bool debug = false) {
	DLList<int> testList;
	assert(testList.size() == 0);
	assert(testList.empty());
	if (debug) std::cout << "List is empty!" << std::endl;

	testList.push_front(12);
	assert(testList.size() == 1);
	assert(!testList.empty());
	assert(testList.front() == 12);
	assert(testList.back() == 12);
	if (debug) std::cout << "Successfully pushed element at the beginning!" << std::endl;

	testList.push_back(24);
	assert(testList.size() == 2);
	assert(!testList.empty());
	assert(testList.front() == 12);
	assert(testList.back() == 24);
	if (debug) std::cout << "Successfully pushed element at the end" << std::endl;

	testList.push_front(0);
	assert(testList.size() == 3);
	assert(!testList.empty());
	assert(testList.front() == 0);
	assert(testList.back() == 24);
	if (debug) std::cout << "Successfully pushed another element at front!" << std::endl;

	testList.pop_front();
	assert(testList.size() == 2);
	assert(!testList.empty());
	assert(testList.front() == 12);
	assert(testList.back() == 24);
	if (debug) std::cout << "Successfully popped element from start!" << std::endl;

	testList.pop_back();
	assert(testList.size() == 1);
	assert(!testList.empty());
	assert(testList.front() == 12);
	assert(testList.back() == 12);
	if (debug) std::cout << "Successfully popped element from back!" << std::endl;

	DLList<int> testCopyList(testList);
	assert(testCopyList.size() == 1);
	assert(!testCopyList.empty());
	assert(testCopyList.front() == 12);
	assert(testCopyList.back() == 12);
	if (debug) std::cout << "Successfully copied list!" << std::endl;

	DLList<int> testAssignedList;
	testAssignedList = testList;
	assert(testAssignedList.size() == 1);
	assert(!testAssignedList.empty());
	assert(testAssignedList.front() == 12);
	assert(testAssignedList.back() == 12);
	if (debug) std::cout << "Successfully assigned list!" << std::endl;
	return true;
}
bool dliteratorTests(bool debug = false) {
	if (debug) std::cout << "Testing list iterator!" << std::endl;

	DLList<int> testList;
	for (int i = 0; i < 10; i++) {
		testList.push_back(i);
	}
	if (debug) std::cout << "Successfully filled list!" << std::endl;

	assert(testList.size() == 10);

	DLListIterator<int> testIterator = testList.begin();
	for (int i = 0; i < 10; i++, testIterator++) {
		assert(*testIterator == i);
	}
	if (debug) std::cout << "Successfully iterated over test list!" << std::endl;

	int testSum = 0, cycle = 0;
	for (testIterator = testList.begin(); testIterator != testList.end(); cycle++) {
		testSum += *testIterator;
		testIterator.next();
	}
	assert(testSum == 45);
	assert(!testIterator.next());
	if (debug) std::cout << "Iterator should return false after reaching the end!" << std::endl;

	testSum = 0, cycle = 0;
	for (testIterator = testList.begin(); testIterator != testList.end(); cycle++) {
		testSum += *testIterator;
		testIterator.next();
	}
	assert(testSum == 45);
	assert(!testIterator.next());
	if (debug) std::cout << "Iterator should return false after reaching the end!" << std::endl;
	return true;
}

//int  main() {
//	std::cout << "Result from tests is: " << std::boolalpha << dllistTests() && dliteratorTests();
//	return 0;
//}